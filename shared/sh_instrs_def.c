/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_instrs_def.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:21:55 by rbozhko           #+#    #+#             */
/*   Updated: 2018/07/28 18:40:00 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void		ft_swap_ints(int *arr, size_t pos)
{
	int		temp;

	if (pos > 1)
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
}

void		ft_push_int_rec(int *arr, size_t i, size_t *j, int value)
{
	if (i == *j)
	{
		arr[i] = value;
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
		arr[--(*j)] = value;
		return ;
	}
	ft_extract_int_rec(arr, i + 1, j, arr[i + 2]);
	arr[i] = value;
}

void		ft_push_int(int *arr1, int *arr2, size_t *pos1, size_t *pos2)
{
	if ((*pos2) > 0)
	{
		ft_push_int_rec(arr1, 0, pos1, arr2[0]);
		ft_extract_int_rec(arr2, 0, pos2, arr2[1]);
	}
}

void		ft_rotate_ints(int *arr, size_t len)
{
	int			num;
	size_t		i;

	if (len > 0)
	{
		i = 0;
		num = arr[i];
		while (i < len)
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
	int		num;
	int		i;

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
