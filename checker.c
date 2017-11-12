#include "checker.h"

char		*ft_bidarrjoin(char **arr, size_t len)
{
	char		*temp;
	char		*str;
	size_t		i;
	char 		**arr_temp;
	size_t		j;

	i = 0;
	temp = ft_strnew(0);
	ft_bzero(temp, sizeof(char*));
	str = temp;
	while (i < len && !(j = 0))
	{
		arr_temp = ft_strsplit(arr[i++], ' ');
		while (arr_temp[j])
		{
			temp = ft_strjoin(temp, arr_temp[j++]);
			ft_strdel(&str);
			str = temp;
			(j < ft_bidlen(arr_temp) || i != len) ? temp = ft_strjoin(temp, " ") : 0;
			(j < ft_bidlen(arr_temp) || i != len) ? ft_strdel(&str) : 0;
			(j < ft_bidlen(arr_temp) || i != len) ? str = temp : 0;
		}
		ft_free_bidarr(arr_temp, ft_bidlen(arr_temp));
	}
	return (temp);
}

size_t			ft_omit_whitespaces(char *str, size_t i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

size_t			ft_bid_strlen(char **arr)
{
	size_t		i;
	size_t		len;

	len = 0;
	i = 0;
	while (arr[i])
	{
		if (ft_omit_whitespaces(arr[i], 0) == ft_strlen(arr[i]))
			return (0);
		len += ft_strlen(arr[i]);
		i++;
	}
	return (len);
}

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
		if (ft_strcmp(arr[i], BONUS_FILE_FD) || ft_strcmp(arr[i], BONUS_COLOR))
		{
			if (i != 0)
			{
				if (ft_strcmp(arr[i - 1], BONUS_FILE_FD) || ft_strcmp(arr[i - 1], BONUS_COLOR))
					checker->stack_a[i] = ft_atoi_base(arr[i], 10);
			}
			else
				checker->stack_a[i] = ft_atoi_base(arr[i], 10);
		}
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
