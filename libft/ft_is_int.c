/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:34:50 by rbozhko           #+#    #+#             */
/*   Updated: 2017/11/12 18:34:52 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool		ft_is_int(const char *str)
{
	intmax_t		num;

	if (str && ft_strlen(str))
	{
		num = ft_atoi_base((char*)str, 10);
		if (num >= -2147483648 && num <= 2147483647)
			return (true);
	}
	else
		ft_throw_exception("ft_is_int: Passed string is NULL or zero length");
	return (false);
}
