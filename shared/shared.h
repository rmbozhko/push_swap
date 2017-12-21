#ifndef SHARED_H
#define SHARED_H

# include "../libft/libft.h"
# include <stdio.h>

# define INSTRS_NUM 11

# define BONUS_COLOR "-c"
# define BONUS_INFO "-i"
# define BONUS_IF_FD "-istream" // file to read from
# define BONUS_OF_FD "-ostream" // file to write in

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

typedef	struct 	s_sh
{
	int 		in_fd;
	int 		out_fd;
	char		*color;
}				t_sh;

typedef	struct 	s_stack
{
	int 		*stack_a;
	int 		*stack_b;
	size_t		counter_a;
	size_t		counter_b;
}				t_stack;

size_t		ft_check_are_digits(char **arr);
size_t		ft_check_are_ints(char **arr);
size_t		ft_check_are_duplicates(char **arr);

bool		ft_is_sorted(int *arr, size_t len);
size_t		ft_bid_strlen(char **arr);
char		*ft_handle_colors(char *str);
char		*ft_get_color(char **arr);
bool 		ft_is_bonus_flag(char **arr, size_t i);

void		ft_rev_rotate_ints(int *arr, size_t len);
void		ft_rotate_ints(int *arr, size_t len);
void		ft_push_int(int *arr1, int *arr2, size_t *pos1, size_t *pos2);
void		ft_swap_ints(int *arr, size_t pos);

#endif