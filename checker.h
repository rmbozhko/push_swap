#ifndef CHECKER_H
#define CHECKER_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

# define INSTRS_NUM 11

# define BONUS_FILE_FD "-f"
# define BONUS_COLOR "-c"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"
# define BUFF_SIZE 1
# define NL_CODE ft_strchr(temp, '\n')
# define S_C_SUB (NL_CODE - temp)
# define IF_FP ((fd < 0 || fd > 4096) || ((read(fd, buff, 0)) == -1 && !(head)))
# define IF_SP (!(line) || !(ft_memset(buff, 0, BUFF_SIZE + 1)))
# define MEMORY_COEF 5

typedef	struct	s_node
{
	int				fd;
	char			*str;
	struct s_node	*next;
}				t_node;

typedef	struct 	s_checker
{
	int 		fd;
	char		**input;
	int 		*stack_a;
	int 		*stack_b;
	size_t		counter_a;
	size_t		counter_b;
	char		*color;
}				t_checker;

char		*ft_get_color(char **arr);
size_t		ft_bid_strlen(char **arr);
char		*ft_bidarrjoin(char **arr, size_t arr_len);
void		ft_throw_exception(char *str);
size_t		ft_is_int(char *str);
void		ft_handle_instrs(t_checker *checker);
char 		**ft_get_defined_instrs(void);
void		ft_output(int flag, t_checker *checker);
int 		ft_get_fd(char **arr);
void		ft_validate_instrs(t_checker *checker, size_t i);
char		*ft_validate_args(char *str, t_checker *checker);
int			get_next_line(const int fd, char **line, char *str);
bool		ft_check_if_sorted(int *arr, size_t len);
void		ft_rev_rotate_ints(int *arr, size_t len);
void		ft_rotate_ints(int *arr, size_t len);
void		ft_push_int(int *arr1, int *arr2, size_t *pos1, size_t *pos2);
void		ft_swap_ints(int *arr, size_t pos);

#endif