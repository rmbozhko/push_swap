#include "push_swap.h"

size_t						ft_abs(const int n)
{
	return ((n < 0) ? -n : n );
}

static inline size_t		ft_choose_pivot(const int arr_size)
{
	time_t		t;
	size_t		res;
	
	/* Intializes random number generator */
	srand((unsigned) time(&t));
	
	/* Get random pivot from 0 to arr_size - 1 */
	res = (rand() % arr_size);
	
	return (res);
}

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
		ft_throw_exception("Wrong array format");
	return (j);
}

void			ft_quicksort(t_stack* stack, const size_t len)
{
	int			pivot;
	size_t		i;
	size_t		j;

	if (len == 1)
		return ;
	pivot = stack->stack_a[ft_get_pivot(stack->stack_a, len)];
	i = 0;
	j = 0;
	#ifdef DEBUG
		printf("pivot: %d\n", pivot);
		printf("Before stacks splitting\n");
	    printf("Stack A:\n");
	    ft_print_iarr(stack->stack_a, stack->counter_a);
	#endif

	while (i < len)
	{
		#ifdef DEBUG
			printf("elem in stack A: %d\n", stack->stack_a[i]);
		#endif
		if (stack->stack_a[0] > pivot)
			ft_handle_instrs_p(stack, "pb", true);
		else
			ft_handle_instrs_r(stack, "ra", true);
		i++;
	}
	#ifdef DEBUG
	printf("After stacks splitting\n");
	printf("Stack A:\n");
	ft_print_iarr(stack->stack_a, stack->counter_a);

	printf("Stack B:\n");
	ft_print_iarr(stack->stack_b, stack->counter_b);
	#endif

	i = 0;
    //reverse the list back to original position
    while (i < (len - stack->counter_b)) // no need
    {
    	ft_handle_instrs_r(stack, "rra", true);
    	i++;
    }

    //push larger half onto smaller half
    i = stack->counter_b;
    while (stack->counter_b != 0)
    	ft_handle_instrs_p(stack, "pa", true);
    #ifdef DEBUG
	    printf("Before 1-st rec call\n");
	    printf("Stack A:\n");
		ft_print_iarr(stack->stack_a, stack->counter_a);

		printf("Stack B:\n");
		ft_print_iarr(stack->stack_b, stack->counter_b);
		printf("I is LEN for 1-st ft_quicksort call: %zu\n", i);
    #endif
    //recursively call this on the larger half
    ft_quicksort(stack, i);
    #ifdef DEBUG
	    printf("After 1-st rec call\n");
	    printf("Stack A:\n");
		ft_print_iarr(stack->stack_a, stack->counter_a);

		printf("Stack B:\n");
		ft_print_iarr(stack->stack_b, stack->counter_b);
	#endif

    //rotate smaller half to front
    while (j < i)
    {
    	ft_handle_instrs_r(stack, "ra", true);
    	j++;
    }

    #ifdef DEBUG
    printf("Before 1-st rec call\n");
    printf("Stack A:\n");
	ft_print_iarr(stack->stack_a, stack->counter_a);

	printf("Stack B:\n");
	ft_print_iarr(stack->stack_b, stack->counter_b);
	printf("I is LEN for 2-nd ft_quicksort call: %zu\n", len - i);
	#endif
    //recursively call this on smaller half
    ft_quicksort(stack, len - i);

    //reverse list back to original position
    while (j != 0)
    {
    	ft_handle_instrs_r(stack, "rra", true);
    	j--;
    }
    #ifdef DEBUG
    printf("At the very end\n");
    printf("Stack A:\n");
	ft_print_iarr(stack->stack_a, stack->counter_a);

	printf("Stack B:\n");
	ft_print_iarr(stack->stack_b, stack->counter_b);
	#endif
}