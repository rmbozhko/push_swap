#ifndef CHECKER_H
#define CHECKER_H

# include "../shared/shared.h"

# define OPTIMUM_LEN 5

void		ft_sort_stack(t_stack *stack, const t_sh *shared);
void		ft_quicksort(t_stack* stack, size_t len, bool STACK_A, const int out_fd);
void		ft_handle_two_elems(t_stack* stack, const bool STACK_A, const int out_fd);

#endif
