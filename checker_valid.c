#include "checker.h"

static size_t		ft_check_are_digits(char **arr)
{
	size_t		i;

	i = 0;
	while (arr[i])
	{
		if (!ft_is_numeric(arr[i])) // is it allowed +12 or -29 in push_swap?????
		{
			// if (i != 0)
			// {
			// 	if (ft_strcmp(arr[i - 1], BONUS_FILE_FD) != 0
			// 		&& ft_strcmp(arr[i], BONUS_FILE_FD) != 0
			// 		&& ft_strcmp(arr[i - 1], BONUS_COLOR) != 0
			// 		&& ft_strcmp(arr[i], BONUS_COLOR) != 0)
			// 	{
			// 		return (1);
			// 	}
			// }
			// else
			// {
			// 	if (ft_strcmp(arr[i], BONUS_FILE_FD) != 0 && ft_strcmp(arr[i], BONUS_COLOR) != 0)
			// 	{
			// 		return (1);
			// 	}
			// }
#ifdef DEBUG
			printf("ERROR ELEM:%s\n", arr[i]);
#endif
			return (1);
		}
		i++;
	}
	return (0);
}

static size_t		ft_check_are_ints(char **arr)
{
	size_t		i;

	i = 0;
	while (arr[i])
	{
		if (!ft_is_int(arr[i]))
		{
			// if (i != 0)
			// {
			// 	if (ft_strcmp(arr[i - 1], BONUS_FILE_FD)
			// 		|| ft_strcmp(arr[i], BONUS_FILE_FD)
			// 		|| ft_strcmp(arr[i - 1], BONUS_COLOR)
			// 		|| ft_strcmp(arr[i], BONUS_COLOR))
			// 		return (1);
			// }
			// else
			#ifdef DEBUG
			printf("ERROR ELEM:%s\n", arr[i]);
			#endif
			return (1);
		}
		i++;
	}
	return (0);
}

static size_t		ft_check_are_duplicates(char **arr)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (arr[i] && !(j = 0))
	{
		// printf("CURR[i]:%s|CURR[j]:%s\n", arr[i], arr[j]);
		while (arr[j])
		{
			// printf("CURR[i]:%s|CURR[j]:%s\n", arr[i], arr[j]);
			if (j != i)
			{
				if (!ft_strcmp(arr[j], arr[i]))
				{
					// printf("FOUND: %s|%s\n", arr[j], arr[i]);
					// if (i != 0)
					// {
					// 	if (ft_strcmp(arr[i - 1], BONUS_FILE_FD)
					// 		|| ft_strcmp(arr[i - 1], BONUS_COLOR))
					// 		return (1);
					// }
					// else
					#ifdef DEBUG
					printf("ERROR ELEM:%s\n", arr[i]);
					#endif
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

char		*ft_rotate_args(char *str, char c)
{
	char		*string;
	char		**arr;
	char		**temp;
	int			i;
	size_t		j;

	arr = ft_strsplit(str, c);
	ft_strdel(&str);
	i = ft_bidlen(arr) - 1;
	temp = (char**)malloc(sizeof(char*) * (i + 2));
	j = 0;
	// printf("%i\n", i);
	while (i >= 0)
	{
		// ft_putendl("A!");
		// printf("ELEMENT:%s|%zu|%i\n", arr[i], j, i);
		temp[j++] = ft_strdup(arr[i--]);
	}
	temp[j] = NULL;
	// ft_putendl("END!");
	ft_free_bidarr(arr, ft_bidlen(arr));
	// ft_putbidstr(temp);
	string = ft_bidarrjoin(temp, ft_bidlen(temp));
	// printf("STRING:%s\n", string);
	ft_free_bidarr(temp, j);
	return (string);
}

char		*ft_validate_args(char *str, t_checker *checker)
{
	char 		**arr;
	size_t		errors;

	arr = ft_strsplit(str, ' ');
	errors = 0;
	// printf("Start\n");
	errors += ft_check_are_digits(arr);
	// printf("IS_DIGIT ERROR:%zu\n", errors);
	errors += (!errors) ? ft_check_are_ints(arr) : 0;
	// printf("INT-LIKE ERROR:%zu\n", errors);
	errors += (!errors) ? ft_check_are_duplicates(arr) : 0;
	// printf("DUPLICATE ERROR:%zu\n", errors);
	if ((!errors) && ((ft_get_fd(checker, arr) == -1)
		|| ((checker->color = ft_get_color(arr)) == NULL)))
		errors++;
	// ft_putendl("Y!");
	ft_free_bidarr(arr, ft_bidlen(arr));
#ifdef DEBUG
	printf("str:%s\n", str);
#endif
	return ((errors) ? NULL : str);
}

bool 		ft_find_instr(char *line)
{
	char 		**instrs;
	size_t		j;
	bool 		found;

	found = false;
	instrs = ft_get_defined_instrs();
	j = 0;
	while (j < INSTRS_NUM)
	{
		if (!ft_strcmp(line, instrs[j]))
			found = true;
		j++;
	}
	ft_free_bidarr(instrs, ft_bidlen(instrs));
	return (found);
}

void		ft_validate_file_instrs(t_checker *checker)
{
	char 		**input;
	size_t 		i;

	i = 0;
	if ((input = ft_read_file(checker->in_fd, NULL)) == NULL)
		ft_throw_exception("Failed to read from file.");
	while (input[i])
	{
		if (!ft_find_instr(input[i]))
		{
			ft_free_bidarr(input, ft_bidlen(input));
			ft_output(1, checker);
		}
		i++;
	}
	ft_handle_file_instrs(input, checker);
}

void		ft_validate_instrs(t_checker *checker)
{
	char 		*line;
	int 		status;

	line = ft_strnew(0);
	while ((status = get_next_line(checker->in_fd, &line, ft_strnew(0))) > 0)
	{
		if (!ft_find_instr(line))
		{
			ft_strdel(&line);
			ft_output(1, checker);
		}
		else
			ft_handle_instrs(checker, line);
	}
	if (status == -1)
		ft_throw_exception("During stdin reading error occured.");
	((ft_is_sorted(checker->stack_a, checker->counter_a))
		? ft_output(3, checker) : ft_output(2, checker));
}
