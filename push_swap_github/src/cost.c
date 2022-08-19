#include "push_swap.h"

/* get_cost:
*	Calculates the cost of moving each element of STACK_B into
*	the correct position in STACK_A.
*	Two costs are calculated:
*		cost_b represents the cost of getting the element to the top of STACK_B.
*		cost_a represents the cost of getting an element from STACK_B to the right
*				position in STACK_A.
*		If the element is in the bottom half of the stack, the cost will be negative,
*		if it is in the top half, the cost is positive.
*/
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
				tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
				tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

/* do_cheapest_move:
*	Finds the element in STACK_B with the cheapest cost to move to STACK_A
*	and moves it to the correct position in STACK_A.
*/
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs_val(tmp->cost_a) + abs_val(tmp->cost_b) < abs_val(cheapest))
		{
			cheapest = abs_val(tmp->cost_b) + abs_val(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}	