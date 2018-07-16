#include "push_swap.h"

void		ft_print_help(t_sh* shared)
{
	ft_putendl_fd("Usage: ./push_swap [FLAGS] [INT_SEQUENCE]", shared->out_fd);
	ft_putstr_fd("\tFLAGS can be following (multiple at once possible): \n\t", shared->out_fd);
	ft_putstr_fd(BONUS_HELP, shared->out_fd);
	ft_putstr_fd(" -- Get the help of using program\n\t", shared->out_fd);
	ft_putstr_fd(BONUS_DISPLAY, shared->out_fd);
	ft_putstr_fd(" -- Display both stacks\n\t", shared->out_fd);
	ft_putstr_fd(BONUS_COLOR, shared->out_fd);
	ft_putendl_fd(" -- Change color of output", shared->out_fd);
	ft_putstr_fd("\t\t[BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN and default, WHITE]\n\t", shared->out_fd);
	ft_putstr_fd(BONUS_IF_FD, shared->out_fd);
	ft_putstr_fd(" -- Specify the input source\n\t", shared->out_fd);
	ft_putstr_fd(BONUS_OF_FD, shared->out_fd);
	ft_putstr_fd(" -- Specify the output source\n\t", shared->out_fd);
	ft_putstr_fd(BONUS_BUBBLE, shared->out_fd);
	ft_putstr_fd(" -- Specify the sorting algorithm, currently bubble sort.\n\t", shared->out_fd);
	ft_putstr_fd(BONUS_INSERT, shared->out_fd);
	ft_putstr_fd(" -- Specify the sorting algorithm, currently insertion sort.\n\t", shared->out_fd);
	ft_putstr_fd(BONUS_QUICK, shared->out_fd);
	ft_putstr_fd(" -- Specify the sorting algorithm, currently quicksort.\n", shared->out_fd);
	ft_putstr_fd("Specify the sorting algorithm, currently quicksort.\n", shared->out_fd);
	ft_putendl_fd("INT_SEQUENCE can be passed as follows: ", shared->out_fd);
	ft_putendl_fd("INT ... \"INT\" ... INT ... \"INT\" ...", shared->out_fd);
}

int			main(int ac, char const *av[])
{
	t_stack			stack;
	t_sh			shared;
	char			*args;

	if (ac > 1)
	{
		if (ft_bid_strlen(av + 1) > 0)
		{
			args = NULL;
			(av)++;
			shared.in_fd = 0;
			shared.out_fd = 0;
			shared.color = WHITE;
			shared.algo = QUICK;
			shared.print_help = false;
			shared.display_stacks = false;
			args = ft_validate_args(ft_bidarrjoin((char**)av,
				ft_bidlen((char**)av)), &shared);
			if (shared.print_help)
				ft_print_help(&shared);
			if (!args)
				ft_output(1, &shared);
			else
			{
				ft_initialization(&stack, args);
				(shared.display_stacks) ? ft_print_stacks(&stack, &shared) : 0;
				ft_sort_stack(&stack, &shared);
			}
		}
	}
	else
		ft_throw_exception("No data is passed");
	return (0);
}
