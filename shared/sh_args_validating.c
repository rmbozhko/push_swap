#include "shared.h"

size_t		ft_check_are_digits(char **arr)
{
	size_t		i;

	i = 0;
	while (arr[i])
	{
		if (!ft_is_numeric(arr[i]))
		{
			#ifdef DEBUG
				printf("ERROR ELEM:%s\n", arr[i]);
			#endif
			if (!ft_is_bonus_flag(arr, i))
				return (1);
		}
		i++;
	}
	return (0);
}

size_t		ft_check_are_ints(char **arr)
{
	size_t		i;

	i = 0;
	while (arr[i])
	{
		if (!ft_is_int(arr[i]))
		{
			#ifdef DEBUG
				printf("ERROR ELEM:%s\n", arr[i]);
			#endif
			if (!ft_is_bonus_flag(arr, i))
				return (1);
		}
		i++;
	}
	return (0);
}

size_t		ft_check_are_duplicates(char **arr)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (arr[i] && !(j = 0))
	{
		while (arr[j])
		{
			if (j != i)
			{
				if (!ft_strcmp(arr[j], arr[i]))
				{
					#ifdef DEBUG
						printf("ERROR ELEM:%s\n", arr[i]);
					#endif
					if (!ft_is_bonus_flag(arr, i))
						return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}