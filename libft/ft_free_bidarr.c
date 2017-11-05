/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bidarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:38:51 by rbozhko           #+#    #+#             */
/*   Updated: 2017/08/16 14:38:54 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_free_bidarr(char **arr, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}
