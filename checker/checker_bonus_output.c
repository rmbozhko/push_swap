#include "checker.h"

size_t		ft_largest_number(int *arr, size_t len)
{
	size_t		i;
	size_t		size;

	size = 0;
	i = 0;
	while (i < len)
	{
		size = (ft_numlen(arr[i]) > size) ? ft_numlen(arr[i]) : size;
		i++;
	}
	return (size);
}

void		ft_nprint(char *str, size_t times)
{
	size_t		i;

	i = 0;
	while (i < times)
	{
		ft_putstr(str);
		i++;
	}
}

void		ft_display_instr_res(int *arr, size_t len, size_t move, bool flag)
{
	size_t		i;
	size_t		mnum_len;

	i = 0;
	mnum_len = ft_largest_number(arr, len);

	ft_putendl("------------------------------------------------------------");
	ft_putstr("Instruction #");
	ft_putnbrendl(move);
	while (i < len)
	{
		ft_putnbrendl(arr[i]);
		i++;
	}
	ft_nprint("-", mnum_len);
	ft_nprint(" ", (mnum_len / 2 + (mnum_len % 2) ? 1 : 0));
	ft_putendl((flag) ? "a" : "b"); 
}

void		ft_check_top(t_checker *checker, bool flag)
{
	char		**arr;
	int			num;

	arr = ft_strsplit(checker->args, ' ');
	ft_putstr("\t\t\t\tTop position of stack ");
	ft_putstr((flag) ? "A:\t" : "B:\t");
	if ((checker->counter_a == 0  && flag) || (checker->counter_b == 0 && !flag))
		num = ft_bidlen(arr);
	else
		num = ft_bidlen(arr) - checker->((flag) ? counter_a : counter_b);
	ft_putnbrendl(num);
	ft_free_bidarr(arr, ft_bidlen(arr));
}

void		ft_check_elems(t_checker *checker, bool flag)
{
	ft_putstr("\t\t\t\tAmount of elems in stack ");
	ft_putstr((flag) ? "A: " : "B: ");
	ft_putnbrendl(checker->((flag) ? counter_a : counter_b));
}

// char		*ft_rotate_str(char *str)
// {
// 	size_t		i;
// 	size_t		j;
// 	size_t		num;

// 	i = ft_strlen(str);
// 	temp = (char*)malloc(sizeof(char) * i + 1);
// 	ft_bzero(temp, sizeof(char*));
// 	j = 0;
// 	while (i > 0)
// 	{
// 		temp[j] = str[i];
// 		num = i;
// 		while (!ft_isspace(str[i]))
// 			i--;
// 		if (num != i)
// 		{
// 			while (num > i)
// 				temp[j++] = str[num--];
// 		}
// 		else
// 		{
// 			j++;
// 			i--;
// 		}
// 	}
// }

