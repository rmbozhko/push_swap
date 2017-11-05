#include "checker.h"

static size_t		ft_check_are_digits(char **arr)
{
	size_t		i;

	i = 0;
	while (arr[i])
	{
		if (!ft_is_numeric(arr[i])) // is it allowed +12 or -29 in push_swap?????
		{
			if (i != 0)
			{
				if (ft_strcmp(arr[i - 1], BONUS_FILE_FD) != 0
					&& ft_strcmp(arr[i], BONUS_FILE_FD) != 0
					&& ft_strcmp(arr[i - 1], BONUS_COLOR) != 0
					&& ft_strcmp(arr[i], BONUS_COLOR) != 0)
				{
					return (1);
				}
			}
			else
			{
				if (ft_strcmp(arr[i], BONUS_FILE_FD) != 0 && ft_strcmp(arr[i], BONUS_COLOR) != 0)
				{
					printf("HERE:%s|\n", arr[i]);
					return (1);
				}
			}
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
			if (i != 0)
			{
				if (ft_strcmp(arr[i - 1], BONUS_FILE_FD)
					|| ft_strcmp(arr[i], BONUS_FILE_FD)
					|| ft_strcmp(arr[i - 1], BONUS_COLOR)
					|| ft_strcmp(arr[i], BONUS_COLOR))
					return (1);
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}

static size_t		ft_check_are_duplicates(char **arr, int i, int j)
{
	printf("___--____--==+_+_+_+_+_+_++_+\n");
	while (arr[++i] && (j = -1))
	{
		printf("CURR[i]:%s|CURR[j]:%s\n", arr[i], arr[j]);
		while (arr[++j])
		{
			printf("CURR[i]:%s|CURR[j]:%s\n", arr[i], arr[j]);
			if (j != i)
			{
				if (!ft_strcmp(arr[j], arr[i]))
				{
					printf("FOUND: %s|%s\n", arr[j], arr[i]);
					if (i != 0)
					{
						if (ft_strcmp(arr[i - 1], BONUS_FILE_FD)
							|| ft_strcmp(arr[i - 1], BONUS_COLOR))
							return (1);
					}
					else
						return (1);
				}
			}
		}
	}
	return (0);
}

char		*ft_validate_args(char *str, t_checker *checker)
{
	char 		**arr;
	size_t		errors;

	arr = ft_strsplit(str, ' ');
	errors = 0;
	ft_putbidstr(arr);
	errors += ft_check_are_digits(arr);
	printf("errors:%zu\n", errors);
	errors += (!errors) ? ft_check_are_ints(arr) : 0;
	printf("errors:%zu\n", errors);
	errors += (!errors) ? ft_check_are_duplicates(arr, -1, -1) : 0;
	printf("errors:%zu\n", errors);
	if ((!errors) && (((checker->fd = ft_get_fd(arr)) == -1)
		|| ((checker->color = ft_get_color(arr)) == NULL)))
		errors++;
	ft_free_bidarr(arr, ft_bidlen(arr));
	return ((errors) ? NULL : str);//ft_reverse_str(str));
}

bool 		ft_space_based_line(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

void		ft_validate_instrs(t_checker *checker, size_t i)
{
	char 		**instrs;
	char 		**input;
	size_t		j;
	char 		found;

	if ((input = ft_read_file(checker->fd, NULL)) == NULL)
		ft_throw_exception("Failed to read from file.");
	instrs = ft_get_defined_instrs();
	while (input[i] && !(j = 0))
	{
		found = 0;
		while (j < INSTRS_NUM)
		{
			if (!ft_strcmp(input[i], instrs[j]))
				found = 1;
			j++;
		}
		if (found == 0)
			break ;
		i++;
	}
	ft_free_bidarr(instrs, ft_bidlen(instrs));
	if (input[0] == NULL)
	{
		//ft_output(2, checker); // to display Error in case of no instructions passage
		ft_free_bidarr(input, ft_bidlen(input));
		exit(0);
	}
	(found == 0) ? ft_output(1, checker) : 0;
	checker->input = input;
}
