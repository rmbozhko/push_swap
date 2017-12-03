#include "push_swap.h"

int		main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		if (ft_bid_strlen(((char**)av) + 1) > 0)
		{
			args = NULL;
			(av)++;
			checker.in_fd = 0;
			checker.out_fd = 0;
			args = ft_validate_args(ft_bidarrjoin((char**)av,
				ft_bidlen((char**)av)), &checker);
#ifdef DEBUG
			printf("ARGUMENTS:%s\n", args);
#endif
			if (!args)
				ft_output(1, &checker);
			else
			{
				ft_checker_init(&checker, args);
				(!checker.in_fd) ? ft_validate_instrs(&checker) : ft_validate_file_instrs(&checker);
			}
		}
		else
			ft_output(1, &checker);
	}
	return 0;
}