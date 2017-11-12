#include "checker.h"

int 		ft_get_fd(t_checker *checker, char **arr)
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
				checker->in_fd = open(arr[i + 1], O_RDONLY);
				fd = checker->in_fd;
			}
			else if ((!ft_strcmp(arr[i], BONUS_IF_FD)))
			{
				checker->out_fd = open(arr[i + 1], O_WRONLY);
				fd = checker->out_fd;
			}
			if (fd < 0 || fd > 4096)
				return (-1);
		}
		i++;
	}
	return (fd);
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
	temp = BLACK;
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
