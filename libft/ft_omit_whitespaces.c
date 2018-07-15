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
