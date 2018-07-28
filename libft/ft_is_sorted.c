/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:55:10 by rbozhko           #+#    #+#             */
/*   Updated: 2018/07/28 18:55:11 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool		ft_is_sorted(const int *arr, const size_t len)
{
	size_t		i;

	if (len > 1)
	{
		i = 0;
		while (i < len)
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
