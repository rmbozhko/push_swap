#include "push_swap.h"

static inline bool		ft_is_greater(const int a, const int b) // delete if necessary
{
	return ((a > b) ? true : false);
}

static size_t			ft_find_smallest(const int* arr, const size_t arr_size)
{
	size_t		sml;
	size_t		i;
	
	i = 0;
	sml = i;
	if (arr)
	{
		while (i < arr_size)
		{
			sml = (arr[i] < arr[sml]) ? i : sml;
			i++;
		}
	}
	else
		ft_throw_exception("Wrong array format");
	return (sml);
}

static void			ft_handle_three_elems(t_stack *stack)
{
	int* 		arr = NULL;
	size_t		len;

	len = stack->counter_a;	
	arr = stack->stack_a;

	while (!ft_is_sorted(arr, len))
	{
		if (arr[0] > arr[1])
			ft_handle_instrs_s(stack, "sa", true);
		else if (arr[2] > arr[0] || arr[2] > arr[1]
				|| (arr[2] < arr[0] && arr[2] < arr[1]))
			ft_handle_instrs_r(stack, "rra", true);
	}
}

static void			ft_handle_more_elems(t_stack* stack)
{
	size_t		pos;

	while (!ft_is_sorted(stack->stack_a, stack->counter_a))
	{
		if (stack->counter_a == 3)
			ft_handle_three_elems(stack); // firstly try out previous commit without 3 elems handling
		else
		{
			pos = ft_find_smallest(stack->stack_a, stack->counter_a);
			if (stack->stack_a[pos] == stack->stack_a[0])
				ft_handle_instrs_p(stack, "pb", true);
			else if ((int)(stack->counter_a / 2) < pos)
				ft_handle_instrs_r(stack, "rra", true);
			else
				ft_handle_instrs_r(stack, "ra", true);
		}
	}
	while (stack->counter_b > 0)
		ft_handle_instrs_p(stack, "pa", true);
}

static inline size_t		ft_choose_pivot(const int arr_size)
{
	time_t		t;
	size_t		res;
	
	/* Intializes random number generator */
	srand((unsigned) time(&t));
	
	/* Get random pivot from 0 to arr_size - 1 */
	res = (rand() % arr_size);
	
	return (res);
}

void		ft_handle_two_elems(t_stack *stack) // delete if necessary
{
	if (ft_is_greater(stack->stack_a[0], stack->stack_a[1]))
		ft_handle_instrs_p(stack, "pa", true);
}

void		ft_sort_stack(t_stack *stack, t_sh *shared)
{
	if (stack->counter_a == 2)
		ft_handle_two_elems(stack);
	else if (stack->counter_a == 3)
		ft_handle_three_elems(stack);
	else
		ft_handle_more_elems(stack);
}
