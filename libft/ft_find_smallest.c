/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_smallest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:49:23 by rbozhko           #+#    #+#             */
/*   Updated: 2018/07/28 18:49:58 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_find_smallest(const int *arr, const size_t arr_size)
{
	size_t		sml;
	size_t		i;

	i = 0;
	sml = i;
	if (arr)
	{
		while (i < arr_size)
		{
			sml = (arr[i] < arr[sml]) ? i : sml;
			i++;
		}
	}
	else
		ft_throw_exception("Wrong array format");
	return (sml);
}
