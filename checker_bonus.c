#include "checker.h"

int 		ft_get_fd(char **arr)
{
	size_t		i;
	int 		fd;

	i = 0;
	fd = 0;
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], BONUS_FILE_FD) && arr[i + 1] != NULL)
		{
			fd = open(arr[i + 1], O_RDONLY);
			printf("HERE!!!!!!!\n");
			if (fd < 0 || fd > 4096) //|| read(fd, NULL, 0) == -1)
			{
				fd = -1;
				break ;
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

void		ft_putnbrendl(int num)
{
	ft_putnbr(num);
	ft_putchar('\n');
}

size_t		ft_largest_number(int *arr, size_t len)
{
	size_t		i;
	size_t		size;

	size = 0;
	i = 0;
	while (i < len)
	{
		size = (ft_numlen(arr[i]) > size) ? ft_numlen(arr[i]) : size;
		i++;
	}
	return (size);
}

void		ft_nprint(char *str, size_t times)
{
	size_t		i;

	i = 0;
	while (i < times)
	{
		ft_putstr(str);
		i++;
	}
}

void		ft_display_instr_res(int *arr, size_t len, size_t move, bool flag)
{
	size_t		i;
	size_t		mnum_len;

	i = 0;
	mnum_len = ft_largest_number(arr, len);

	ft_putendl("------------------------------------------------------------");
	ft_putstr("Instruction #");
	ft_putnbrendl(move);
	while (i < len)
	{
		ft_putnbrendl(arr[i]);
		i++;
	}
	ft_nprint("-", mnum_len);
	ft_nprint(" ", (mnum_len / 2 + (mnum_len % 2) ? 1 : 0));
	ft_putendl((flag) ? "a" : "b"); 
}
