/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:06:04 by rbozhko           #+#    #+#             */
/*   Updated: 2017/10/29 20:07:08 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_skip_whitespaces(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	{
		i++;
	}
	return (i);
}
