#include "checker.h"

void		ft_swap_ints(int *arr, size_t pos)
{
	int 		temp;

	if (pos > 1)
	{
		temp = arr[pos - 1];
		arr[pos - 1] = arr[pos];
		arr[pos] = temp;
	}
}

int 		*ft_pop(int *arr, size_t len)
{
	size_t		i;
	intmax_t	num;

	i = 0;
	while (i < len)
	{
		num = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = num;
	}
	return (arr);
}

void		ft_push_int(int *arr1, int *arr2, size_t *pos1, size_t *pos2)
{
	if (pos2 > 0)
	{
		arr1[(*pos1)] = arr2[(*pos2) - 1];
		(*pos1)++;
		(*pos2)--;
	}
}

void		ft_rotate_ints(int *arr, size_t len)
{
	int 		num;
	int 		temp;
	size_t		i;

	if (len > 0)
	{
		i = 0;
		num = arr[i];
		while (arr[i])
		{
			if (i + 1 != len)
				arr[i] = arr[i + 1];
			else
				break ;
			i++;
		}
		arr[i] = num;
	}
}

void		ft_rev_rotate_ints(int *arr, size_t len)
{
	int 		num;
	int 		temp;
	int			i;

	if (len > 0)
	{
		i = len - 1;
		num = arr[i];
		while (i != 0)
		{
			if (i - 1 >= 0)
				arr[i] = arr[i - 1];
			else
				break ;
			i--;
		}
		arr[i] = num;
	}
}


bool		ft_check_if_sorted(int *arr, size_t len)
{
	size_t		i;

	i = 0;
	printf("CURR ELEM:%d\n", arr[i]);
	while (arr[i])
	{
		printf("CURR ELEM:%d\n", arr[i]);
	    if (i + 1 == len)
	        break ;
		else if (arr[i] > arr[i + 1])
		{
			printf("CURR ELEM:%d|%d\n", arr[i], arr[i + 1]);
			return (false);
		}
		i++;
	}
	return (true);
}
