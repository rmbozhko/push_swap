#include "checker.h"

void		ft_handle_file_instrs(char **input, t_stack *stack, t_sh *sh)
{
	size_t		i;

	i = 0;
	while (input[i])
	{
		if (input[i][0] == 's')
			ft_handle_instrs_s(stack, input[i], false);
		else if (input[i][0] == 'p')
			ft_handle_instrs_p(stack, input[i], false);
		else if (input[i][0] == 'r')
			ft_handle_instrs_r(stack, input[i], false);
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

void		ft_handle_instrs(t_stack *stack, const char *line)
{
	if (line[0] == 's')
		ft_handle_instrs_s(stack, line, false);
	else if (line[0] == 'p')
		ft_handle_instrs_p(stack, line, false);
	else if (line[0] == 'r')
		ft_handle_instrs_r(stack, line, false);
}

