#ifndef SHARED_H
#define SHARED_H

# include "../libft/libft.h"
# include <stdio.h>

# define INSTRS_NUM 11
# define SPACE_BETWEEN_STACKS 5

# define BONUS_BUBBLE "-bubble"
# define BONUS_INSERT "-insert"
# define BONUS_QUICK "-quick"
# define BONUS_COLOR "-c"
# define BONUS_HELP "-h"
# define BONUS_DISPLAY "-d"
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

typedef enum ALGO
{
	BUBBLE=0,
	INSERT,
	QUICK,
	NONE
} T_ALGO;

typedef	struct 	s_sh
{
	bool 		ps_st;
	int 		in_fd;
	int 		out_fd;
	char		*color;
	T_ALGO		algo;
	bool 		print_help;
	bool 		display_stacks;
}				t_sh;

typedef	struct 	s_stack
{
	int 		*stack_a;
	int 		*stack_b;
	size_t		counter_a;
	size_t		counter_b;
}				t_stack;

void		ft_print_stacks(const t_stack* stack, const t_sh* shared);

size_t		ft_check_are_digits(const char **arr);
size_t		ft_check_are_ints(const char **arr);
size_t		ft_check_are_duplicates(const char **arr);

size_t		ft_bid_strlen(const char **arr);
char*		ft_handle_colors(const char *str);
char*		ft_get_color(const char **arr);
bool 		ft_is_bonus_flag(const char **arr, size_t i);

void		ft_rev_rotate_ints(int *arr, size_t len);
void		ft_rotate_ints(int *arr, size_t len);
void		ft_push_int(int *arr1, int *arr2, size_t *pos1, size_t *pos2);
void		ft_swap_ints(int *arr, size_t pos);

char*		ft_init_shared(t_sh* shared, const char** av, const bool PUSH_SWAP);
void		ft_initialization(t_stack *stack, char *args);
void		ft_output(int flag, t_sh *shared);
char*		ft_validate_args(char *str, t_sh *shared);
int 		ft_get_fd(t_sh *shared, const char **arr);
void		ft_print_help(const t_sh* shared);

void		ft_handle_instrs_s(t_stack *stack, const char *str, bool print_instr, const int fd);
void		ft_handle_instrs_p(t_stack *stack, const char *str, bool print_instr, const int fd);
void		ft_handle_instrs_r(t_stack *stack, const char *str, bool print_instr, const int fd);
#endif