#include "push_swap.h"
static int	find_highest_index(t_stack *stack);

/* find_highest_index:
* returns the highest index in a stack.
*/
static int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* small_sort:
*	sorts a stack of 3 numbers in 2 or fewer moves. The sorting
*	is done by INDEX rather than VALUE. example:
*		VALUE:	 0	 9	 2
*		INDEX:	[1] [3]	[2]
*	Solution, 2 moves:
*	RRA:
*		VALUE:	 2	 0	 9
*		INDEX:	[2]	[1]	[3]
*	SA:
*		VALUE:	 0	 2	 9
*		INDEX:	[1]	[2]	[3]
*/
void	small_sort(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}