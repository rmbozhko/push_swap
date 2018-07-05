#include "push_swap.h"

static inline bool		ft_is_greater(const int a, const int b)
{
	return ((a > b) ? true : false);
}

static void			ft_handle_three_elems(t_stack *stack)
{
	int* 	arr = NULL;
	
	arr = stack->stack_a;
	
	while (!ft_is_sorted(arr))
	{
		if (arr[0] < arr[1])
			ft_handle_instrs_s(stack, "sa");
		if (arr[0] < arr[2] || arr[0] < arr[1])
			ft_handle_instrs_r(stack, "rra");
	}
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

void		ft_handle_two_elems(t_stack *stack)
{
	if (ft_is_greater(stack->stack_a[0], stack->stack_a[1]))
		ft_handle_instrs_p(stack, "pa");
}

void		ft_sort_stack(t_stack *stack, t_sh *shared)
{
	printf("Hello, World! Don\'t worry. I am already sorting.\n");
	if (stack->counter_a == 2)
		ft_handle_two_elems(stack);
	else if (stack->counter_a == 3)
		ft_handle_three_elems(stack);
	else
		printf("Num of elems is greater than 2\n");
	
	if (ft_is_sorted(stack->stack_a, stack->counter_a))
		ft_output(3, shared);
	else
		ft_output(2, shared));
}
