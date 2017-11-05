#include "checker.h"

void		ft_output(int flag, t_checker *checker)
{
	int 		fd;

	fd = (flag == 1) ? 2 : 1;
	ft_putstr_fd(checker->color, fd);
	if (flag == 1)
		ft_putendl_fd("Error", 2);
	else if (flag == 2)
		ft_putendl_fd("KO", 1);
	else if (flag == 3)
		ft_putendl_fd("OK", 1);
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
