#ifndef CHECKER_H
#define CHECKER_H

# include "../shared/shared.h"

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

char 		**ft_get_defined_instrs(void);
void		ft_output(int flag, t_sh *shared);
int 		ft_get_fd(t_sh *shared, char **arr);

void		ft_validate_instrs(t_stack *stack, t_sh *shared);
void		ft_validate_file_instrs(t_stack *stack, t_sh *shared);

char		*ft_validate_args(char *str, t_sh *shared);
int			get_next_line(const int fd, char **line, char *str);
void		ft_handle_file_instrs(char **input, t_stack *stack, t_sh *sh);
void		ft_handle_instrs(t_stack *stack, char *line);


#endif
