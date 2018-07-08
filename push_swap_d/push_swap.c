#include "push_swap.h"

int		main(int ac, char const *av[])
{
	t_stack			stack;
	t_sh			shared;
	char			*args;

	if (ac > 1)
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
				ft_initialization(&stack, args);
				ft_sort_stack(&stack, &shared);
			}
		}
	}
	else
		ft_throw_exception("No data is passed");
	return (0);
}
