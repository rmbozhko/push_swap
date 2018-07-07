#include "shared.h"

int 		ft_get_fd(t_sh *shared, char **arr)
{
	size_t		i;
	int 		fd;

	i = 0;
	fd = 0;
	while (arr[i])
	{
		if ((!ft_strcmp(arr[i], BONUS_OF_FD) && arr[i + 1] != NULL)
			|| (!ft_strcmp(arr[i], BONUS_IF_FD) && arr[i + 1] != NULL))
		{
			if ((!ft_strcmp(arr[i], BONUS_IF_FD)))
			{
				shared->in_fd = open(arr[i + 1], O_RDONLY);
				fd = shared->in_fd;
			}
			else if ((!ft_strcmp(arr[i], BONUS_OF_FD)))
			{
				shared->out_fd = open(arr[i + 1], O_WRONLY | O_CREAT, 0777);
				fd = shared->out_fd;
			}
			if (fd < 0 || fd > 4096)
				return (-1);
		}
		i++;
	}
	return (fd);
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

char		*ft_handle_colors(char *str)
{
	if (!ft_strcmp(str, "BLACK"))
		return (BLACK);
	else if (!ft_strcmp(str, "RED"))
		return (RED);
	else if (!ft_strcmp(str, "GREEN"))
		return (GREEN);
	else if (!ft_strcmp(str, "YELLOW"))
		return (YELLOW);
	else if (!ft_strcmp(str, "BLUE"))
		return (BLUE);
	else if (!ft_strcmp(str, "MAGENTA"))
		return (MAGENTA);
	else if (!ft_strcmp(str, "CYAN"))
		return (CYAN);
	else if (!ft_strcmp(str, "WHITE"))
		return (WHITE);
	else
		return (NULL);
}

char		*ft_get_color(char **arr)
{
	size_t		i;
	char 		*temp;

	i = 0;
	temp = WHITE;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], BONUS_COLOR) && arr[i + 1] != NULL)
		{
			temp = ft_handle_colors(arr[i + 1]);
			break ;
		}
		i++;
	}
	return ((temp) ? ft_strdup(temp) : NULL);
}

char		*ft_validate_args(char *str, t_sh *shared)
{
	char 		**arr;
	size_t		errors;

	arr = ft_strsplit(str, ' ');
	errors = 0;
	errors += ft_check_are_digits(arr);
	errors += (!errors) ? ft_check_are_ints(arr) : 0;
	errors += (!errors) ? ft_check_are_duplicates(arr) : 0;
	if ((!errors) && ((ft_get_fd(shared, arr) == -1)
		|| ((shared->color = ft_get_color(arr)) == NULL)))
		errors++;
	ft_free_bidarr(arr, ft_bidlen(arr));
	return ((errors) ? NULL : str);
}

void		ft_initialization(t_stack *stack, char *args)
{
	size_t			i;
	size_t			j;
	char 			**arr;

	i = 0;
	j = i;
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
			stack->stack_a[j++] = ft_atoi_base(arr[i], 10);
		i++;
	}
	stack->counter_a = j;
	ft_free_bidarr(arr, stack->counter_a);
}

void		ft_output(int flag, t_sh *shared)
{
	int 		fd;

	fd = (flag == 1) ? 2 : 1;
	ft_putstr_fd(shared->color, fd);
	if (flag == 1)
	{
		ft_putendl_fd("Error", shared->out_fd);
	}
	else if (flag == 2)
	{
		ft_putendl_fd("KO", shared->out_fd);
	}
	else if (flag == 3)
	{
		ft_putendl_fd("OK", shared->out_fd);
	}
	ft_putstr_fd(RESET, fd);
	exit((flag == 1) ? 1 : 0);
}