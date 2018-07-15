#ifndef CHECKER_H
#define CHECKER_H

# include "../shared/shared.h"
# include <time.h>

void		ft_sort_stack(t_stack *stack, t_sh *shared);
void		ft_quicksort(t_stack* stack, const size_t len, bool STACK_A);
void		ft_handle_two_elems(t_stack* stack, bool STACK_A);

#endif
