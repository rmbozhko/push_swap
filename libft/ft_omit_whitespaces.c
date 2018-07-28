/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_omit_whitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:42:28 by rbozhko           #+#    #+#             */
/*   Updated: 2018/07/28 18:42:31 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_omit_whitespaces(const char *str, size_t i)
{
	if (str)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	else
		ft_throw_exception("ft_omit_whitespaces: Passed string is NULL");
	return (i);
}
