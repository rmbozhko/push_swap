#include "push_swap.h"

int		main(int argc, char const *argv[])
{
	t_stack			stack;
	t_sh			shared;
	char			*args;

	if (argc > 1)
	{
		if (ft_bid_strlen(((char**)av) + 1) > 0)
		{
			args = NULL;
			(av)++;
			shared.in_fd = 0;
			shared.out_fd = 0;
			shared.color = WHITE;
			args = ft_validate_args(ft_bidarrjoin((char**)av,
				ft_bidlen((char**)av)), &shared);
			if (!args)
				ft_output(1, &shared);
			else
			{
				ft_initialization(&shared, args);
				(!shared.in_fd) ? ft_validate_instrs(&shared) : ft_validate_file_instrs(&shared);
			}
		}
		else
			ft_output(1, &shared);
	}
	return (0);
}