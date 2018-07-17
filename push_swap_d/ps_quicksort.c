#include "push_swap.h"

// size_t			ft_get_pivot(const int* arr, const size_t len) // test with negative elements in arr
// {
// 	size_t		j;
// 	size_t		i;
// 	int			mean;
// 	int			delta;

// 	if (arr && len != 0)
// 	{
// 		if (len == 2)
// 			return (arr[0] < arr[1]) ? 0 : 1;
// 		i = 0;
// 		j = i;
// 		mean = (int)(ft_abs(arr[ft_find_biggest(arr, len)] + arr[ft_find_smallest(arr, len)]) / 2);
// 		delta = ft_abs(arr[i] - mean);
// 		while (i++ < len)
// 		{
// 			if (ft_abs(arr[i] - mean) < delta)
// 			{
// 				delta = (ft_abs(arr[i] - mean) < delta) ? ft_abs(arr[i] - mean) : delta;
// 				j = i;
// 			}
// 		}
// 	}
// 	else
// 		ft_throw_exception("ft_get_pivot: Wrong array format");
// 	return (j);
// }

int	check_median(const t_stack *stack, const int pivot, const size_t len, bool STACK_A)
{
	size_t		i;

	i = 0;//((STACK_A) ? stack->counter_a : stack->counter_b) - len - 2;
	#ifdef DEBUG
	printf("check_median(i):%zu|STACK_A:%d|len:%zu\n", i, STACK_A, len);
	#endif
	while (i < len)//((STACK_A) ? stack->counter_a : stack->counter_b))
	{
		if (((STACK_A) ? stack->stack_a[i] : stack->stack_b[i]) < pivot && STACK_A)
		{
			#ifdef DEBUG
			printf("LESS THAN PIVOT:%d\n", (STACK_A) ? stack->stack_a[i] : stack->stack_b[i]);
			#endif
			return (1);
		}
		if (((STACK_A) ? stack->stack_a[i] : stack->stack_b[i]) >= pivot && !STACK_A)
		{
			#ifdef DEBUG
			printf("LESS THAN MED:%d\n", (STACK_A) ? stack->stack_a[i] : stack->stack_b[i]);
			#endif
			return (1);
		}
		i++;
	}
	#ifdef DEBUG
	printf("TADAD\n");
	#endif
	return (0);
}

size_t			ft_get_pivot(const int* arr, const size_t arr_len, const size_t len)
{
	int	i;
	int	j;
	int	nb;
	int	med;

	j = 0;//arr_len - len;
	while (j < len)//arr_len)
	{
		med = 0;
		i = 0;//arr_len - len;
		nb = arr[j];
		while (i < len)//arr_len)
		{
			if (nb != arr[i])
				(arr[i] > nb) ? med++ : med--;
			i++;
		}
		if (med == (len % 2 == 0 ? -1 : 0))
			return (j); // position of selected element
		j++;
	}
	return (0);
}

void			ft_sort_stack_a(t_stack* stack, const size_t len)
{
	size_t			i;
	int 			pivot;
	size_t			j;

	j = 0;
	i = 0;
	pivot = stack->stack_a[ft_get_pivot(stack->stack_a, stack->counter_a, len)];
	#ifdef DEBUG
	printf("pivot:%d|len:%zu\n", pivot, len);
	#endif
	while (i <= len)
	{
		if (stack->stack_a[0] < pivot)
			ft_handle_instrs_p(stack, "pb", true);
		else
		{
			ft_handle_instrs_r(stack, "ra", true);
			j++;
		}
		i++;
	}
	#ifdef DEBUG
	printf("STACK_A\n");
	ft_print_iarr(stack->stack_a, stack->counter_a);
	printf("STACK_B\n");
	ft_print_iarr(stack->stack_b, stack->counter_b);
	#endif
	while (j-- > 0 && ((len / 2 + len % 2) != stack->counter_a))
		ft_handle_instrs_r(stack, "rra", true);
}

void			ft_sort_stack_b(t_stack* stack, const size_t len)
{
	size_t			i;
	int 			pivot;
	size_t			j;

	j = 0;
	i = 0;
	pivot = stack->stack_b[ft_get_pivot(stack->stack_b, stack->counter_b, len)];
	#ifdef DEBUG
	printf("pivot:%d|len:%zu\n", pivot, len);
	#endif
	while (i <= len && check_median(stack, pivot, len, false))
	{
		if (stack->stack_b[0] < pivot)
		{
			ft_handle_instrs_r(stack, "rb", true);
			j++;
		}
		if (stack->stack_b[0] >= pivot)
			ft_handle_instrs_p(stack, "pa", true);
			
		i++;
	}
	// do i really need rra?? why?
	while (j-- > 0 && (len / 2 != stack->counter_b))
		ft_handle_instrs_r(stack, "rrb", true);
}

void			ft_quicksort(t_stack* stack, size_t len, bool STACK_A)
{
	#ifdef DEBUG
	printf("QUICK_LEFT(STACK_A:%d)\n", STACK_A);
	printf("TOP_A:%zu\n", stack->counter_a);
	printf("TOP_B:%zu\n", stack->counter_b);
	printf("NB:%zu\n", len);
	printf("Stack A\n");
	ft_print_iarr(stack->stack_a, stack->counter_a);
	printf("Stack B\n");
	ft_print_iarr(stack->stack_b, stack->counter_b);
	#endif
	if (len <= 2) // base case
	{
		if (len == 2)
			(STACK_A) ? ft_handle_two_elems(stack, true) : ft_handle_two_elems(stack, false);
		while (!STACK_A && len--)
			ft_handle_instrs_p(stack, "pa", true);
		return ;
	}
	(STACK_A) ? ft_sort_stack_a(stack, len) : ft_sort_stack_b(stack, len);
	#ifdef DEBUG
	printf("###########################GOING RECURSION##########################\n");
	#endif
	ft_quicksort(stack, len / 2 + len % 2, true);
	#ifdef DEBUG
	printf("___--------------_____________________------------______________\n");
	#endif
	ft_quicksort(stack, len / 2, false);
}