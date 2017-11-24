#include "checker.h"

void		ft_swap_ints(int *arr, size_t pos)
{
	int 		temp;

	if (pos > 1)
	{
		// printf("POS:%zu|ELEM POS:%d|ELEM POS - 1:%d\n", pos, arr[pos - 1], arr[pos - 2]);
		
		// temp = arr[pos - 1];
		// arr[pos - 1] = arr[pos];
		// arr[pos] = temp;
		
		//"top" is in the end of an array
		// temp = arr[pos - 2];
		// arr[pos - 2] = arr[pos - 1];
		// arr[pos - 1] = temp;
		
		//"top" is in the beginning of an array
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
}

void 		ft_push_int_rec(int *arr, size_t i, size_t *j, int value)
{
	if (i == *j)
	{
		arr[i] = value;
		#ifdef DEBUG
			printf("HERE WE ARE:%zu|%d\n", i, value);
			#endif
		(*j)++;
		return ;
	}
	ft_push_int_rec(arr, i + 1, j, arr[i]);
	arr[i] = value;
}

void		ft_extract_int_rec(int *arr, size_t i, size_t *j, int value)
{
	if (i == *j)
	{
		arr[--(*j)] = value;//i] = value;
		// printf("VALUE:%zu|%zu|%d\n", i, *j, value);
		// (*j)--;
		return ;
	}
	ft_extract_int_rec(arr, i + 1, j, arr[i + 2]);
	// printf("VALUE:%zu|%zu|%d\n", i, *j, value);
	arr[i] = value;
}

void		ft_push_int(int *arr1, int *arr2, size_t *pos1, size_t *pos2)
{
	int 		*temp1;
	int 		*temp2;
	int 		num;

	#ifdef DEBUG
	printf("VALUE OF POS2:%zu\n", *pos2);
	#endif

	//"top" is in the end of an array
	// if ((*pos2) > 0)
	// {
	// 	arr1[(*pos1)] = arr2[(*pos2) - 1];
	// 	(*pos1)++;
	// 	(*pos2)--;
	// }

	//"top" is in the beginning of an array
	if ((*pos2) > 0)
	{
		// num = arr2[0];
		#ifdef DEBUG
			printf("POS1:%zu|%d\n", *pos1, arr2[0]);
		#endif
		ft_push_int_rec(arr1, 0, pos1, arr2[0]);
		#ifdef DEBUG
			printf("YO, HERE WE ARE:%d|%zu|%zu\n", arr1[0], *pos1, *pos2);
		#endif
		ft_extract_int_rec(arr2, 0, pos2, arr2[1]);
		#ifdef DEBUG
			printf("YO, HERE WE ARE:%d|%zu|%zu\n", arr2[0], *pos1, *pos2);
		#endif
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
