#include "push_swap.h"

static void			ft_handle_three_elems(t_stack *stack)
{
	int* 		arr = NULL;
	size_t		len;

	len = stack->counter_a;	
	arr = stack->stack_a;

	while (!ft_is_sorted(arr, len))
	{
		if (arr[0] > arr[1])
			ft_handle_instrs_s(stack, "sa", true);
		else if (arr[2] > arr[0] || arr[2] > arr[1]
				|| (arr[2] < arr[0] && arr[2] < arr[1]))
			ft_handle_instrs_r(stack, "rra", true);
	}
}

static void			ft_plain_sort(t_stack* stack)
{
	size_t		pos;

	while (!ft_is_sorted(stack->stack_a, stack->counter_a))
	{
		if (stack->counter_a == 3)
			ft_handle_three_elems(stack); // firstly try out previous commit without 3 elems handling
		else
		{
			pos = ft_find_smallest(stack->stack_a, stack->counter_a);
			if (stack->stack_a[pos] == stack->stack_a[0])
				ft_handle_instrs_p(stack, "pb", true);
			else if ((int)(stack->counter_a / 2) < pos)
				ft_handle_instrs_r(stack, "rra", true);
			else
			{
				if (pos == 1)
					ft_handle_instrs_s(stack, "sa", true);
				else
					ft_handle_instrs_r(stack, "ra", true);
			}
		}
	}
	while (stack->counter_b > 0)
		ft_handle_instrs_p(stack, "pa", true);
}

void		ft_sort_stack(t_stack *stack, t_sh *shared)
{
	bool qs = true;
	if (qs)
	{
		#define DEBUG
	}
	if (stack->counter_a == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			ft_handle_instrs_p(stack, "pa", true);
	}
	else if (stack->counter_a == 3)
		ft_handle_three_elems(stack);
	else
		(qs) ? ft_quicksort(stack, stack->counter_a) : ft_plain_sort(stack);
	(qs) ? ft_print_iarr(stack->stack_a, stack->counter_a) : 0;
}
