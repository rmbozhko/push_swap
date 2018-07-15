#include "push_swap.h"

size_t			ft_get_pivot(const int* arr, const size_t len) // test with negative elements in arr
{
	size_t		j;
	size_t		i;
	int			mean;
	int			delta;

	if (arr && len != 0)
	{
		if (len == 2)
			return (arr[0] < arr[1]) ? 0 : 1;
		i = 0;
		j = i;
		mean = (int)(ft_abs(arr[ft_find_biggest(arr, len)] + arr[ft_find_smallest(arr, len)]) / 2);
		delta = ft_abs(arr[i] - mean);
		while (i++ < len)
		{
			if (ft_abs(arr[i] - mean) < delta)
			{
				delta = (ft_abs(arr[i] - mean) < delta) ? ft_abs(arr[i] - mean) : delta;
				j = i;
			}
		}
	}
	else
	{
		printf("LEN:%zu\n", len);
		ft_throw_exception("Wrong array format");
	}
	return (j);
}

void			ft_sort_stack_a(t_stack* stack, const size_t len)
{
	size_t			i;
	int 			pivot;

	i = 0;
	pivot = stack->stack_a[ft_get_pivot(stack->stack_a, len)];
	while (i < len)
	{
		if (stack->stack_a[i] < pivot)
			ft_handle_instrs_p(stack, "pb", true);
		else
			ft_handle_instrs_r(stack, "ra", true);
		i++;
	}
	// do i really need rra?? why?
	// while (i > (len - stack->counter_a))
		// ft_handle_instrs_r(stack, "rra", true);
}

void			ft_sort_stack_b(t_stack* stack, const size_t len)
{
	size_t			i;
	int 			pivot;

	i = 0;
	pivot = stack->stack_b[ft_get_pivot(stack->stack_b, len)];
	while (i < len)
	{
		if (stack->stack_b[i] < pivot)
			ft_handle_instrs_p(stack, "pa", true);
		else
			ft_handle_instrs_r(stack, "rb", true);
		i++;
	}
	// do i really need rra?? why?
	// while (i > (len - stack->counter_b))
		// ft_handle_instrs_r(stack, "rrb", true);
}

void			ft_quicksort(t_stack* stack, const size_t len, bool STACK_A)
{
	if (len <= 2) // base case
	{
		if (len == 2)
			(STACK_A) ? ft_handle_two_elems(stack, true) : ft_handle_two_elems(stack, false);
		while (!STACK_A && stack->counter_b)
			ft_handle_instrs_p(stack, "pa", true);
		return ;
	}
	(STACK_A) ? ft_sort_stack_a(stack, len) : ft_sort_stack_b(stack, len);
	ft_quicksort(stack, len / 2 + len % 2, true);
	ft_quicksort(stack, len / 2, false);
}