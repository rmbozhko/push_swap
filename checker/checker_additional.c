#include "checker.h"

void		ft_output(int flag, t_sh *shared)
{
	int 		fd;

	fd = (flag == 1) ? 2 : 1;
	// printf("FLAG:%d|%s|%d\n", flag, shared->color, fd);
	ft_putstr_fd(shared->color, fd);
	// printf("FLAG:%d\n", flag);
	if (flag == 1)
	{
		// printf("PRINTING1!\n");
		ft_putendl_fd("Error", shared->out_fd);
	}
	else if (flag == 2)
	{
		// printf("PRINTING2!\n");
		ft_putendl_fd("KO", shared->out_fd);
	}
	else if (flag == 3)
	{
		// printf("PRINTING3!\n");
		ft_putendl_fd("OK", shared->in_fd);
	}
	// printf("PRINTING!\n");
	ft_putstr_fd(RESET, fd);
	exit((flag == 1) ? 1 : 0);
}


char 		**ft_get_defined_instrs(void)
{
	char 		**arr;

	arr = (char**)malloc((sizeof(char*) * 11) + 1);
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
	arr[11] = NULL;
	return (arr);
}
