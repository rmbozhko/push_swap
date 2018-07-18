#include "checker.h"

void		ft_handle_file_instrs(char **input, t_stack *stack, t_sh *sh)
{
	size_t		i;

	i = 0;
	while (input[i])
	{
		if (input[i][0] == 's')
			ft_handle_instrs_s(stack, input[i], false, sh->out_fd);
		else if (input[i][0] == 'p')
			ft_handle_instrs_p(stack, input[i], false, sh->out_fd);
		else if (input[i][0] == 'r')
			ft_handle_instrs_r(stack, input[i], false, sh->out_fd);
		if (sh->display_stacks)
				ft_print_stacks(stack, sh);
		i++;	
	}
}

void		ft_handle_instrs(t_stack *stack, const char *line)
{
	if (line[0] == 's')
		ft_handle_instrs_s(stack, line, false, 0);
	else if (line[0] == 'p')
		ft_handle_instrs_p(stack, line, false, 0);
	else if (line[0] == 'r')
		ft_handle_instrs_r(stack, line, false, 0);
}

