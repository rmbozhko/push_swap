#include <stdio.h>
#include "libft/libft.h"


// #include <stdio.h>
// #include "libft/libft.h"

// void 		ft_push_int_rec(int *arr1, size_t i, size_t *j, int value)
// {
// 	if (i == *j)
// 	{
// 		arr1[i] = value;
// 		(*j)++;
// 		return ;
// 	}
// 	ft_push_int_rec(arr1, i + 1, j, arr1[i]);
// 	arr1[i] = value;
// }

// int 		main(void)
// {
// 	int 		arr[1] = {1};
// 	size_t		len = 1;

// 	printf("LEN BEFORE:%zu\n", len);
// 	ft_push_int_rec(arr, 0, &len, 4);
// 	printf("LEN AFTER:%zu\n", len);
// 	ft_print_iarr(arr, len);
// 	return (0);
// }

void 		ft_push_int_rec(int *arr1, size_t i, size_t *j, int value)
{
	if (i == *j)
	{
		arr1[i] = value;
		(*j)++;
		return ;
	}
	ft_push_int_rec(arr1, i + 1, j, arr1[i]);
	arr1[i] = value;
}

void		ft_extract_int_rec(int *arr1, size_t i, size_t *j, int value)
{
	if (i == *j)
	{
		(*j)--;
		return ;
	}
	ft_extract_int_rec(arr1, i + 1, j, arr1[i + 2]);
	arr1[i] = value;
}
#define LEN 5
int 		main(void)
{
	int 		arr[LEN + 1] = {660, 4506, 9442, 8043, 426};
	size_t		len = LEN;

	printf("LEN BEFORE:%zu\n", len);
	// ft_push_int_rec(arr, 0, &len, 4);
	printf("LEN AFTER PUSHING:%zu\n", len);
	ft_print_iarr(arr, len);
	ft_extract_int_rec(arr, 0, &len, arr[1]);
	printf("LEN AFTER EXCTRACTING:%zu\n", len);
	ft_print_iarr(arr, len);
	ft_extract_int_rec(arr, 0, &len, arr[1]);
	printf("LEN AFTER EXCTRACTING:%zu\n", len);
	ft_print_iarr(arr, len);
	return (0);
}