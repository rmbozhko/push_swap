#include "libft.h"

size_t		ft_abs(const int n)
{
	if (n == INT_MIN)
		ft_throw_exception("ft_abs: Cannot handle INT_MIN");
	return ((n < 0) ? -n : n );
}
