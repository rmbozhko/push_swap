#include "libft.h"

bool		ft_is_sorted(int *arr, size_t len)
{
	size_t		i;

	if (len > 1)
	{
		i = 0;
		while (arr[i])
		{
		    if (i + 1 == len)
		        break ;
			else if (arr[i] > arr[i + 1])
				return (false);
			i++;
		}
	}
	return (true);
}