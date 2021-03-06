#include "checker.h"

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
	while (i >= 0)
	{
		temp[j++] = ft_strdup(arr[i--]);
	}
	temp[j] = NULL;
	ft_free_bidarr(arr, ft_bidlen(arr));
	string = ft_bidarrjoin(temp, ft_bidlen(temp));
	ft_free_bidarr(temp, j);
	return (string);
}

int 		ft_find_instr(char *line)
{
	char 		**instrs;
	size_t		j;
	int 		found;

	if (line && ft_strlen(line) > 1)
	{
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
	else
		return (false);
}

void		ft_validate_file_instrs(t_stack *stack, t_sh *shared)
{
	char 		**input;
	size_t 		i;

	i = 0;
	if ((input = ft_read_file(shared->in_fd, NULL)) == NULL)
		ft_throw_exception("checker_valid: Failed to read from file.");
	while (input[i])
	{
		if (!ft_find_instr(input[i]))
		{
			ft_free_bidarr(input, ft_bidlen(input));
			ft_output(1, shared);
		}
		i++;
	}
	ft_handle_file_instrs(input, stack, shared);
	((ft_is_sorted(stack->stack_a, stack->counter_a))
			? ft_output(3, shared) : ft_output(2, shared));
}

void		ft_validate_instrs(t_stack *stack, t_sh *shared, int status)
{
	char 		*line;

	line = ft_strnew(0);
	while ((status = get_next_line(shared->in_fd, &line, ft_strnew(0))) > 0)
	{
		if (ft_strlen(line) == 0)
		{
			ft_strdel(&line);
			return ;
		}
		if (!ft_find_instr(line))
		{
			ft_strdel(&line);
			ft_output(1, shared);
		}
		else
		{
			ft_handle_instrs(stack, line);
			(shared->display_stacks) ? ft_print_stacks(stack, shared) : 0;
			ft_strdel(&line);
		}
	}
	if (status == -1)
		ft_throw_exception("During stdin reading error occured.");
	((ft_is_sorted(stack->stack_a, stack->counter_a))
		? ft_output(3, shared) : ft_output(2, shared));
}
