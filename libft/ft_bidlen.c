/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bidlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 11:02:28 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/01 11:03:04 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_bidlen(char **arr)
{
	size_t		i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			i++;
	}
	else
		ft_throw_exception("ft_bidlen: Passed bi-dimensional array is NULL");
	return (i);
}
