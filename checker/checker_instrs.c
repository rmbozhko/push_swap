#include "checker.h"

static void		ft_handle_instrs_s(t_checker *checker, char *str)
{
	if (!ft_strcmp(str, "sa"))
		ft_swap_ints(checker->stack_a, checker->counter_a);
	else if (!ft_strcmp(str, "sb"))
		ft_swap_ints(checker->stack_b, checker->counter_b);
	else if (!ft_strcmp(str, "ss"))
	{
		ft_swap_ints(checker->stack_a, checker->counter_a);
		ft_swap_ints(checker->stack_b, checker->counter_b);
	}
}

static void		ft_handle_instrs_p(t_checker *checker, char *str)
{
	if (!ft_strcmp(str, "pa"))
		ft_push_int(checker->stack_a, checker->stack_b,
				&checker->counter_a, &checker->counter_b);
	else if (!ft_strcmp(str, "pb"))
		ft_push_int(checker->stack_b, checker->stack_a,
				&checker->counter_b, &checker->counter_a);
}

static void		ft_handle_instrs_r(t_checker *checker, char *str)
{
	if (!ft_strcmp(str, "ra"))
		ft_rotate_ints(checker->stack_a, checker->counter_a);
	else if (!ft_strcmp(str, "rb"))
		ft_rotate_ints(checker->stack_b, checker->counter_b);
	else if (!ft_strcmp(str, "rr"))
	{
		ft_rotate_ints(checker->stack_a, checker->counter_a);
		ft_rotate_ints(checker->stack_b, checker->counter_b);
	}
	else if (!ft_strcmp(str, "rra"))
		ft_rev_rotate_ints(checker->stack_a, checker->counter_a);
	else if (!ft_strcmp(str, "rrb"))
		ft_rev_rotate_ints(checker->stack_b, checker->counter_b);
	else if (!ft_strcmp(str, "rrr"))
	{
		ft_rev_rotate_ints(checker->stack_a, checker->counter_a);
		ft_rev_rotate_ints(checker->stack_b, checker->counter_b);
	}
}

// void		ft_handle_instrs(t_checker *checker)
// {
// 	size_t		i;

// 	i = 0;
// 	while (checker->input[i])
// 	{
// 		if (checker->input[i][0] == 's')
// 			ft_handle_instrs_s(checker, i);
// 		else if (checker->input[i][0] == 'p')
// 			ft_handle_instrs_p(checker, i);
// 		else if (checker->input[i][0] == 'r')
// 			ft_handle_instrs_r(checker, i);
// 		ft_display_instr_res(checker->stack_a, checker->counter_a, i, 1);
// 		ft_display_instr_res(checker->stack_b, checker->counter_b, i, 0);
// 		i++;
// 	}
// 	((ft_check_if_sorted(checker->stack_a, checker->counter_a))
// 		? ft_output(3, checker) : ft_output(2, checker));
// }

void		ft_handle_file_instrs(char **input, t_checker *checker)
{
	size_t		i;

	i = 0;
	printf("STTRING:%s\n", input[i]);
	while (input[i])
	{
		if (input[i][0] == 's')
			ft_handle_instrs_s(checker, input[i]);
		else if (input[i][0] == 'p')
			ft_handle_instrs_p(checker, input[i]);
		else if (input[i][0] == 'r')
			ft_handle_instrs_r(checker, input[i]);
		i++;
		if (input[i] != NULL)
		{
			ft_putendl_fd(((ft_is_sorted(checker->stack_a, checker->counter_a))
			? "Stack A is sorted" : "Stack A is not sorted"), checker->out_fd);
		}
		else
			((ft_is_sorted(checker->stack_a, checker->counter_a))
			? ft_output(3, checker) : ft_output(2, checker));
	}
}

void		ft_handle_instrs(t_checker *checker, char *line)
{
#ifdef DEBUG
	printf("Stack A after %s instr.\n", line);
	ft_print_iarr(checker->stack_a, checker->counter_a);
	printf("Stack B after %s instr.\n", line);
	ft_print_iarr(checker->stack_b, checker->counter_b);
	printf("______----------------------__________________\n");
#endif	
	if (line[0] == 's')
		ft_handle_instrs_s(checker, line);
	else if (line[0] == 'p')
		ft_handle_instrs_p(checker, line);
	else if (line[0] == 'r')
		ft_handle_instrs_r(checker, line);
#ifdef DEBUG
	printf("Stack A after %s instr.\n", line);
	ft_print_iarr(checker->stack_a, checker->counter_a);
	printf("Stack B after %s instr.\n", line);
	ft_print_iarr(checker->stack_b, checker->counter_b);
	printf("______----------------------__________________\n");
#endif	
}

