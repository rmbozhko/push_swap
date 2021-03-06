#include "checker.h"

char**		ft_get_defined_instrs(void)
{
	char**		arr;

	arr = (char**)malloc((sizeof(char*) * INSTRS_NUM) + 1);
	arr[0] = ft_strdup("sa");
	arr[1] = ft_strdup("sb");
	arr[2] = ft_strdup("ss");
	arr[3] = ft_strdup("pa");
	arr[4] = ft_strdup("pb");
	arr[5] = ft_strdup("ra");
	arr[6] = ft_strdup("rb");
	arr[7] = ft_strdup("rr");
	arr[8] = ft_strdup("rra");
	arr[9] = ft_strdup("rrb");
	arr[10] = ft_strdup("rrr");
	arr[INSTRS_NUM] = NULL;

	return (arr);
}

int			main(int ac, char const **av)
{
	t_stack			stack;
	t_sh			shared;
	char			*args;

	if ((ac > 1))
	{
		if (ft_bid_strlen(av + 1) > 0)
		{
			args = ft_init_shared(&shared, ++(av), false);
			if (!args)
				ft_output(1, &shared);
			if (shared.print_help)
				ft_print_help(&shared);
			if (shared.algo != NONE)
				ft_throw_exception("There is no algorithms flag for ./checker");
			ft_initialization(&stack, args);
			(!shared.in_fd) ? ft_validate_instrs(&stack, &shared, 0) : 
							ft_validate_file_instrs(&stack, &shared);
		}
		else
			ft_output(1, &shared);
	}
	return (0);
}
