#ifndef CHECKER_H
#define CHECKER_H

# include "../shared/shared.h"

char 		**ft_get_defined_instrs(void);
void		ft_validate_instrs(t_stack *stack, t_sh *shared);
void		ft_validate_file_instrs(t_stack *stack, t_sh *shared);
void		ft_handle_file_instrs(char **input, t_stack *stack, t_sh *sh);
void		ft_handle_instrs(t_stack *stack, const char *line);

#endif
