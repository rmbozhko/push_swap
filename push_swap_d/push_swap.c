#include "push_swap.h"

void		ft_free_resources(t_stack* stack, t_sh* shared)
{
	ft_memdel((void*)stack->stack_a);
	ft_memdel((void*)stack->stack_b);
	ft_strdel(&shared->color);
	close(shared->in_fd);
	close(shared->out_fd);
}

char*		ft_combine_args(const int in_fd, char* args)
{
	char**		input;
	char*		temp1;
	char*		temp2;

	if ((input = ft_read_file(in_fd, NULL)) == NULL)
		ft_throw_exception("push_swap: Failed to read from file.");
	if (args)
	{
		temp2 = ft_bidarrjoin(input, ft_bidlen(input));
		temp1 = ft_strjoin(temp2, " "); 
		ft_strdel(&temp2);
		temp2 = ft_strjoin(temp1, args);
		ft_strdel(&args);
		ft_strdel(&temp1);

		return (temp2);
	}
	else
		return (ft_bidarrjoin(input, ft_bidlen(input)));
}

// void		ps_end(void)
// {
// 	while (1);
// 	exit(0);
// }

int			main(int ac, char const *av[])
{
	t_stack			stack;
	t_sh			shared;
	char			*args = NULL;

	if (ac > 1)
	{
		if (ft_bid_strlen(av + 1) > 0)
		{
			args = ft_init_shared(&shared, (av + 1), true);
			if (shared.print_help)
				ft_print_help(&shared);
			if (shared.display_stacks)
				ft_throw_exception("There is no -d flag for ./push_swap");
			if (shared.in_fd)
				args = ft_validate_args(ft_combine_args(shared.in_fd, args), &shared);
			if (!args)
				ft_output(1, &shared);
			ft_initialization(&stack, args);
			ft_sort_stack(&stack, &shared);
			// ps_end();
		}
	}
	else
		ft_throw_exception("No data is passed");
	return (0);
}
