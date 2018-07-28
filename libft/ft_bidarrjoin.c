/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bidarrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:50:29 by rbozhko           #+#    #+#             */
/*   Updated: 2018/07/28 18:53:13 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_bidarrjoin(char **arr, const size_t len)
{
	char		*t;
	char		*str;
	size_t		i;
	char		**arr_temp;
	size_t		j;

	i = 0;
	t = ft_strnew(0);
	ft_bzero(t, sizeof(char*));
	str = t;
	while (i < len && !(j = 0))
	{
		arr_temp = ft_strsplit(arr[i++], ' ');
		while (arr_temp[j])
		{
			t = ft_strjoin(t, arr_temp[j++]);
			ft_strdel(&str);
			str = t;
			(j < ft_bidlen(arr_temp) || i != len) ? t = ft_strjoin(t, " ") : 0;
			(j < ft_bidlen(arr_temp) || i != len) ? ft_strdel(&str) : 0;
			(j < ft_bidlen(arr_temp) || i != len) ? str = t : 0;
		}
		ft_free_bidarr(arr_temp, ft_bidlen(arr_temp));
	}
	return (t);
}
