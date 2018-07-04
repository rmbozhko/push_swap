#include "push_swap.h"

static inline bool		ft_is_greater(const int a, const int b)
{
	return ((a > b) ? true : false);
}

static inline size_t		ft_choose_pivot(const int elem_nums)
{
	int		pivot;
	
	pivot = 0;
	if (elem_nums > 2)
	{
		pivot = 1 + elem_nums + int(elem_nums / 2);
		pivot = int( pivot / 3 );
	}
	return (pivot);
}

void		ft_handle_two_elems(t_stack *stack, t_sh *shared)
{
	if (ft_is_greater(stack->stack_a[0], stack->stack_a[1]))
		ft_handle_instrs_p(stack, "pa");
	else
		((ft_is_sorted(stack->stack_a, stack->counter_a))
			? ft_output(3, shared) : ft_output(2, shared));
}

void		ft_sort_stack(t_stack *stack, t_sh *shared)
{
	printf("Hello, World! Don\'t worry. I am already sorting.\n");
	if (stack->counter_a == 2)
		ft_handle_two_elems(stack, shared);
	else
		printf("Num of elems is greater than 2\n");
}
