#include "shared.h"

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

size_t		ft_check_are_digits(char **arr)
{
	size_t		i;

	i = 0;
	while (arr[i])
	{
		if (!ft_is_numeric(arr[i]))
		{
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