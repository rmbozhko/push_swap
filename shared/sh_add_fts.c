#include "shared.h"

bool		ft_is_sorted(int *arr, size_t len)
{
	size_t		i;

	i = 0;
	// ft_print_iarr(arr, len);
	while (arr[i])
	{
#ifdef DEBUG
		printf("ELEM:%d\n", arr[i]);
#endif
	    if (i + 1 == len)
	        break ;
		else if (arr[i] > arr[i + 1])
			return (false);
		i++;
	}
	return (true);
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