#include "shared.h"

void		ft_handle_instrs_s(t_stack *stack, const char *str, bool print_instr)
{
	if (!ft_strcmp(str, "sa"))
		ft_swap_ints(stack->stack_a, stack->counter_a);
	else if (!ft_strcmp(str, "sb"))
		ft_swap_ints(stack->stack_b, stack->counter_b);
	else if (!ft_strcmp(str, "ss"))
	{
		ft_swap_ints(stack->stack_a, stack->counter_a);
		ft_swap_ints(stack->stack_b, stack->counter_b);
	}
	(print_instr) ? ft_putendl(str) : 0;
}

void		ft_handle_instrs_p(t_stack *stack, const char *str, bool print_instr)
{
	if (!ft_strcmp(str, "pa"))
		ft_push_int(stack->stack_a, stack->stack_b,
				&stack->counter_a, &stack->counter_b);
	else if (!ft_strcmp(str, "pb"))
		ft_push_int(stack->stack_b, stack->stack_a,
				&stack->counter_b, &stack->counter_a);
	(print_instr) ? ft_putendl(str) : 0;
}

void		ft_handle_instrs_r(t_stack *stack, const char *str, bool print_instr)
{
	if (!ft_strcmp(str, "ra"))
		ft_rotate_ints(stack->stack_a, stack->counter_a);
	else if (!ft_strcmp(str, "rb"))
		ft_rotate_ints(stack->stack_b, stack->counter_b);
	else if (!ft_strcmp(str, "rr"))
	{
		ft_rotate_ints(stack->stack_a, stack->counter_a);
		ft_rotate_ints(stack->stack_b, stack->counter_b);
	}
	else if (!ft_strcmp(str, "rra"))
		ft_rev_rotate_ints(stack->stack_a, stack->counter_a);
	else if (!ft_strcmp(str, "rrb"))
		ft_rev_rotate_ints(stack->stack_b, stack->counter_b);
	else if (!ft_strcmp(str, "rrr"))
	{
		ft_rev_rotate_ints(stack->stack_a, stack->counter_a);
		ft_rev_rotate_ints(stack->stack_b, stack->counter_b);
	}
	(print_instr) ? ft_putendl(str) : 0;
}