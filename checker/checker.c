#include "checker.h"

static void		ft_checker_init(t_checker *checker, char *args)
{
	size_t			i;
	char 			**arr;

	i = 0;
	arr = ft_strsplit(args, ' ');
	checker->stack_a = (int*)malloc(sizeof(int) * ft_bidlen(arr));
	ft_bzero(checker->stack_a, sizeof(int*));
	checker->counter_a = ft_bidlen(arr);
	// printf("STACK A LEN:%zu\n", checker->counter_a);
	checker->stack_b = (int*)malloc(sizeof(int) * ft_bidlen(arr));
	ft_bzero(checker->stack_b, sizeof(int*));
	checker->counter_b = 0;
	while (i < checker->counter_a)
	{
		if (!ft_is_bonus_flag(arr, i))
			checker->stack_a[i] = ft_atoi_base(arr[i], 10);
#ifdef DEBUG
		printf("INT_ELEM OF STACK:%i\n", checker->stack_a[i]);
#endif
		i++;
	}
	ft_free_bidarr(arr, checker->counter_a);
}

int			main(int ac, char const **av)
{
	t_checker		checker;
	char			*args;

	if ((ac > 1))
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
	return (0);
}
