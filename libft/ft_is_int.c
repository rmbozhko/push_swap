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

bool		ft_is_int(char *str)
{
	intmax_t		num;

	num = ft_atoi_base(str, 10);
	if (num >= -2147483648 && num <= 2147483647)
		return (true);
	else
		return (false);
}
