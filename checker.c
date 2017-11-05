#include "checker.h"

void		ft_throw_exception(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

size_t		ft_is_int(char *str)
{
	intmax_t		num;

	num = ft_atoi_base(str, 10);
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	else
		return (0);
}

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
		ft_putendl(arr[i]);
		arr_temp = ft_strsplit(arr[i++], ' ');
		// ft_putendl("LOL!");
		while (arr_temp[j])
		{
			temp = ft_strjoin(temp, arr_temp[j++]);
			ft_strdel(&str);
			str = temp;
			printf("CURR j AND LEN:%zu|%zu\n", j, ft_bidlen(arr_temp));
			(j < ft_bidlen(arr_temp) || i != len) ? temp = ft_strjoin(temp, " ") : 0;
			(j < ft_bidlen(arr_temp) || i != len) ? ft_strdel(&str) : 0;
			(j < ft_bidlen(arr_temp) || i != len) ? str = temp : 0;
		}
		// i++;
		ft_free_bidarr(arr_temp, ft_bidlen(arr_temp));
	}
	printf("TEMP OF THE STRING:%s\n", temp);
	return (temp);
}

size_t			ft_bid_strlen(char **arr)
{
	size_t		i;
	size_t		len;

	len = 0;
	i = 0;
	while (arr[i])
	{
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
		i++;
	}
}

int			main(int ac, char const **av)
{
	t_checker		checker;
	char			*args;

	if ((ac > 1) && (ft_bid_strlen(((char**)av) + 1) > 0))
	{
		args = NULL;
		(av)++;
		args = ft_validate_args(ft_bidarrjoin((char**)av,
			ft_bidlen((char**)av)), &checker);
		printf("YOYOOY%s\n", args);
		(args) ? 0 : ft_output(1, &checker);
		printf("ARGUMENTS:%s\n", args);
		(ft_bidlen(checker.input)) ? ft_validate_instrs(&checker, 0) : ft_output(2, &checker);
		ft_putendl("YO, I am sTUCKED!");
		ft_checker_init(&checker, args);
		ft_handle_instrs(&checker);
	}
	return (0);
}
