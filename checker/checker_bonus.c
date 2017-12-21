#include "checker.h"

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

