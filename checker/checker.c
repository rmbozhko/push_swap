#include "checker.h"

static void		ft_checker_init(t_stack *stack, char *args)
{
	size_t			i;
	char 			**arr;

	i = 0;
	arr = ft_strsplit(args, ' ');
	stack->stack_a = (int*)malloc(sizeof(int) * ft_bidlen(arr));
	ft_bzero(stack->stack_a, sizeof(int*));
	stack->counter_a = ft_bidlen(arr);
	stack->stack_b = (int*)malloc(sizeof(int) * ft_bidlen(arr));
	ft_bzero(stack->stack_b, sizeof(int*));
	stack->counter_b = 0;
	while (i < stack->counter_a)
	{
		if (!ft_is_bonus_flag(arr, i))
			stack->stack_a[i] = ft_atoi_base(arr[i], 10);
		i++;
	}
	ft_free_bidarr(arr, stack->counter_a);
}

int			main(int ac, char const **av)
{
	t_stack			stack;
	t_sh			shared;
	char			*args;

	if ((ac > 1))
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
				ft_checker_init(&stack, args);
				if (!shared.in_fd)
					ft_validate_instrs(&stack, &shared);
				else
					ft_validate_file_instrs(&stack, &shared);
			}
		}
		else
			ft_output(1, &shared);
	}
	return (0);
}
