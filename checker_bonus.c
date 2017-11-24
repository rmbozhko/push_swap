#include "checker.h"

bool 		ft_is_bonus_flag(char **arr, size_t i)
{
		if (!ft_strcmp(arr[i], BONUS_COLOR) || !ft_strcmp(arr[i], BONUS_INFO)
			|| !ft_strcmp(arr[i], BONUS_IF_FD) || !ft_strcmp(arr[i], BONUS_OF_FD))
			return (true);
		else if (i != 0)
		{
			if (!ft_strcmp(arr[i - 1], BONUS_COLOR) || !ft_strcmp(arr[i - 1], BONUS_INFO)
				|| !ft_strcmp(arr[i - 1], BONUS_IF_FD) || !ft_strcmp(arr[i - 1], BONUS_OF_FD))
				return (true);
		}
	return (false);
}

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
			else if ((!ft_strcmp(arr[i], BONUS_OF_FD)))
			{
				checker->out_fd = open(arr[i + 1], O_WRONLY | O_CREAT, 0777);
				fd = checker->out_fd;
			}
			if (fd < 0 || fd > 4096)
			{
				#ifdef DEBUG
					printf("\n\n\nHERE WE GO\n\n\n");
				#endif
				return (-1);
			}
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
	{
		#ifdef DEBUG
			printf("BLUE COLOR OUTPUT!\n");
		#endif
		return (BLUE);
	}
	else if (!ft_strcmp(str, "MAGENTA"))
		return (MAGENTA);
	else if (!ft_strcmp(str, "CYAN"))
		return (CYAN);
	else if (!ft_strcmp(str, "WHITE"))
		return (WHITE);
	else
	{
		#ifdef DEBUG
			printf("FUCKED UP!\n");
		#endif
		return (NULL);
	}
}

char		*ft_get_color(char **arr)
{
	size_t		i;
	char 		*temp;

	i = 0;
	temp = WHITE;
	ft_putbidstr(arr);
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], BONUS_COLOR) && arr[i + 1] != NULL)
		{
			#ifdef DEBUG
				printf("HERE WE ARE%s\n", arr[i]);
			#endif
			temp = ft_handle_colors(arr[i + 1]);
			break ;
		}
		i++;
	}
	return ((temp) ? ft_strdup(temp) : NULL);
}
