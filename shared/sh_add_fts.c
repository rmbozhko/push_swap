#include "shared.h"

int 		ft_get_fd(t_sh *shared, const char **arr)
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

size_t			ft_bid_strlen(const char **arr)
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

char		*ft_handle_colors(const char *str)
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

char		*ft_get_color(const char **arr)
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

bool 		ft_need_help(const char **arr)
{
	size_t		i;
	bool 		need_help;

	i = 0;
	need_help = false;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], BONUS_HELP))
		{
			need_help = true;
			break ;
		}
		i++;
	}
	return (need_help);
}

bool 		ft_display_stacks(const char **arr)
{
	size_t		i;
	bool 		display_stacks;

	i = 0;
	display_stacks = false;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], BONUS_DISPLAY))
		{
			display_stacks = true;
			break ;
		}
		i++;
	}
	return (display_stacks);
}

T_ALGO 		ft_get_algo(const char **arr)
{
	size_t		i;
	T_ALGO 		algo;

	i = 0;
	algo = QUICK;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], BONUS_BUBBLE))
			algo = BUBBLE;
		else if (!ft_strcmp(arr[i], BONUS_INSERT))
			algo = INSERT;
		else if (!ft_strcmp(arr[i], BONUS_QUICK))
			algo = QUICK;
		i++;
	}
	return (algo);
}

char		*ft_validate_args(char *str, t_sh *shared)
{
	const char 		**arr = (const char**)ft_strsplit(str, ' ');
	size_t			errors;

	errors = 0;
	errors += ft_check_are_digits(arr);
	errors += (!errors) ? ft_check_are_ints(arr) : 0;
	errors += (!errors) ? ft_check_are_duplicates(arr) : 0;
	if ((!errors) && ((ft_get_fd(shared, arr) == -1)
		|| ((shared->color = ft_get_color(arr)) == NULL)))
		errors++;
	shared->print_help = ft_need_help(arr);
	shared->algo = ft_get_algo(arr);
	shared->display_stacks = ft_display_stacks(arr);
	ft_free_bidarr((char**)arr, ft_bidlen((char**)arr));
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
		if (!ft_is_bonus_flag((const char**)arr, i))
			stack->stack_a[j++] = ft_atoi_base(arr[i], 10);
		i++;
	}
	stack->counter_a = j;
	ft_free_bidarr(arr, stack->counter_a);
}

size_t		ft_numlen_sh(int num)
{
	size_t		places;
	
	places = 0;
	if (num < 0)
	{
		if (num == INT_MIN)
			num++;
		num = -num;
		places++;
	}
	while (num >= 10)
	{
		num /= 10;
		places++;
	}
	places++;
	// printf("NUM:%d|PLACES:%d\n", num, places);
	return (places);
}

void		ft_print_char_repeat_fd(char c, size_t times, int fd)
{
	while(times--)
		ft_putchar_fd(c, fd);
}

// size_t		ft_get_spacing(const size_t num_len)
// {
// 	size_t		res;

// 	if (num_len >= 1 && num_len <= 3)
// 		res = SPACE_BETWEEN_STACKS;
// 	else if (num_len >= 4 && num_len <= 6)
// 		res = SPACE_BETWEEN_STACKS + 
// }

void		ft_arr_abs(int* arr, const size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		arr[i] = ft_abs(arr[i]);
		i++;
	}
}

size_t		ft_find_longest(const int* arr, const size_t len)
{
	size_t		lng;
	size_t		i;
	
	i = 0;
	lng = i;
	if (arr)
	{
		while (i < len)
		{
			lng = (ft_numlen_sh(arr[i]) > ft_numlen_sh(arr[lng])) ? i : lng;
			i++;
		}
	}
	else
		ft_throw_exception("ft_find_longest: Wrong array format");
	return (lng);
}

void		ft_print_stacks(const t_stack* stack, const t_sh* shared)
{
	ft_putstr_fd(shared->color, shared->out_fd);
	size_t		i;
	int			biggest_elem;
	size_t		biggest_elem_size;
	int			a_pending;

	biggest_elem = stack->stack_a[ft_find_longest(stack->stack_a, stack->counter_a)];
	// printf("biggest_elem:%d\n", biggest_elem);
	biggest_elem_size = ft_numlen_sh(biggest_elem);
	
	// printf("biggest_elem_size:%zu\n", biggest_elem_size);
	a_pending =  biggest_elem_size / 2;
	// printf("a_pending:%d\n", a_pending);

	i = 0;
	ft_print_char_repeat_fd(' ', a_pending, shared->out_fd);
	ft_putstr_fd("A", shared->out_fd);
	ft_print_char_repeat_fd(' ', ((biggest_elem_size % 2) ? (a_pending) : a_pending - 1) + (ft_numlen_sh(stack->stack_b[
								ft_find_biggest(stack->stack_b, stack->counter_b)]) / 2)
								+ SPACE_BETWEEN_STACKS, shared->out_fd);
	ft_putendl_fd("B", shared->out_fd);
	a_pending += SPACE_BETWEEN_STACKS;
	while (i < stack->counter_a)
	{
		ft_putnbr_fd(stack->stack_a[i], shared->out_fd);
		// (stack->stack_a[i] == -101) ? printf("\nbes:%d|len:%d\n", biggest_elem_size, ft_numlen_sh(stack->stack_a[i])) : 0;
		ft_print_char_repeat_fd(' ',
			biggest_elem_size - ft_numlen_sh(stack->stack_a[i]) + SPACE_BETWEEN_STACKS, 
			shared->out_fd);

		if (i <= stack->counter_b && i != 0) 
			ft_putnbr_fd(stack->stack_b[i], shared->out_fd);
		else
			ft_putstr_fd("-", shared->out_fd);
		ft_putendl_fd("", shared->out_fd);	
		i++;
	}
	ft_putstr_fd(RESET, shared->out_fd);
}

void		ft_output(int flag, t_sh* shared)
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