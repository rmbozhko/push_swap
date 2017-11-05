#include "checker.h"

static void		ft_handle_instrs_s(t_checker *checker, size_t line_num)
{
	if (!ft_strcmp(checker->input[line_num], "sa"))
		ft_swap_ints(checker->stack_a, checker->counter_a);
	else if (!ft_strcmp(checker->input[line_num], "sb"))
		ft_swap_ints(checker->stack_b, checker->counter_b);
	else if (!ft_strcmp(checker->input[line_num], "ss"))
	{
		ft_swap_ints(checker->stack_a, checker->counter_a);
		ft_swap_ints(checker->stack_b, checker->counter_b);
	}
}

static void		ft_handle_instrs_p(t_checker *checker, size_t line_num)
{
	if (!ft_strcmp(checker->input[line_num], "pa"))
		ft_push_int(checker->stack_a, checker->stack_b,
				&checker->counter_a, &checker->counter_b);
	else if (!ft_strcmp(checker->input[line_num], "pb"))
		ft_push_int(checker->stack_b, checker->stack_a,
				&checker->counter_b, &checker->counter_a);
}

static void		ft_handle_instrs_r(t_checker *checker, size_t line_num)
{
	if (!ft_strcmp(checker->input[line_num], "ra"))
		ft_rotate_ints(checker->stack_a, checker->counter_a);
	else if (!ft_strcmp(checker->input[line_num], "rb"))
		ft_rotate_ints(checker->stack_b, checker->counter_b);
	else if (!ft_strcmp(checker->input[line_num], "rr"))
	{
		ft_rotate_ints(checker->stack_a, checker->counter_a);
		ft_rotate_ints(checker->stack_b, checker->counter_b);
	}
	else if (!ft_strcmp(checker->input[line_num], "rra"))
		ft_rev_rotate_ints(checker->stack_a, checker->counter_a);
	else if (!ft_strcmp(checker->input[line_num], "rrb"))
		ft_rev_rotate_ints(checker->stack_b, checker->counter_b);
	else if (!ft_strcmp(checker->input[line_num], "rrr"))
	{
		ft_rev_rotate_ints(checker->stack_a, checker->counter_a);
		ft_rev_rotate_ints(checker->stack_b, checker->counter_b);
	}
}

void		ft_handle_instrs(t_checker *checker)
{
	size_t		i;

	i = 0;
	while (checker->input[i])
	{
		if (checker->input[i][0] == 's')
			ft_handle_instrs_s(checker, i);
		else if (checker->input[i][0] == 'p')
			ft_handle_instrs_p(checker, i);
		else if (checker->input[i][0] == 'r')
			ft_handle_instrs_r(checker, i);
		ft_display_instr_res(checker->stack_a, checker->counter_a, i, 1);
		ft_display_instr_res(checker->stack_b, checker->counter_b, i, 0);
		i++;
	}
	((ft_check_if_sorted(checker->stack_a, checker->counter_a))
		? ft_output(3, checker) : ft_output(2, checker));
}
