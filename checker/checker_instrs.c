#include "checker.h"

static void		ft_handle_instrs_s(t_stack *stack, char *str)
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
}

static void		ft_handle_instrs_p(t_stack *stack, char *str)
{
	if (!ft_strcmp(str, "pa"))
		ft_push_int(stack->stack_a, stack->stack_b,
				&stack->counter_a, &stack->counter_b);
	else if (!ft_strcmp(str, "pb"))
		ft_push_int(stack->stack_b, stack->stack_a,
				&stack->counter_b, &stack->counter_a);
}

static void		ft_handle_instrs_r(t_stack *stack, char *str)
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
}

void		ft_handle_file_instrs(char **input, t_stack *stack, t_sh *sh)
{
	size_t		i;

	i = 0;
	while (input[i])
	{
		if (input[i][0] == 's')
			ft_handle_instrs_s(stack, input[i]);
		else if (input[i][0] == 'p')
			ft_handle_instrs_p(stack, input[i]);
		else if (input[i][0] == 'r')
			ft_handle_instrs_r(stack, input[i]);
		i++;
		if (input[i] != NULL)
		{
			ft_putendl_fd(((ft_is_sorted(stack->stack_a, stack->counter_a))
			? "Stack A is sorted" : "Stack A is not sorted"), sh->out_fd);
		}
		else
			((ft_is_sorted(stack->stack_a, stack->counter_a))
			? ft_output(3, sh) : ft_output(2, sh));
	}
}

void		ft_handle_instrs(t_stack *stack, char *line)
{
#ifdef DEBUG
	printf("Stack A after %s instr.\n", line);
	ft_print_iarr(stack->stack_a, stack->counter_a);
	printf("Stack B after %s instr.\n", line);
	ft_print_iarr(stack->stack_b, stack->counter_b);
	printf("______----------------------__________________\n");
#endif	
	if (line[0] == 's')
		ft_handle_instrs_s(stack, line);
	else if (line[0] == 'p')
		ft_handle_instrs_p(stack, line);
	else if (line[0] == 'r')
		ft_handle_instrs_r(stack, line);
#ifdef DEBUG
	printf("Stack A after %s instr.\n", line);
	ft_print_iarr(stack->stack_a, stack->counter_a);
	printf("Stack B after %s instr.\n", line);
	ft_print_iarr(stack->stack_b, stack->counter_b);
	printf("______----------------------__________________\n");
#endif	
}

