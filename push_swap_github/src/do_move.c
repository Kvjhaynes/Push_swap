#include "push_swap.h"
static void	do_rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
static void	do_rotate_a(t_stack **stack_a, int *cost);
static void	do_rotate_b(t_stack **stack_b, int *cost);

/* do_rev_rotate_both:
*	Reverse Rotates both STACK_A and STACK_B until one of them is in position.
*	the given cost is negative since both positions are in the bottom half of
*	their respective stacks. The cost is increased as the stacks are rotated,
*	when one reaches 0, the stacks has been rotated as far as possible and
*	the top position is correct.
*/
static void	do_rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/* do_rotate_both:
*	Rotates both STACK_A and STACK_B until on of them is in
*	position. The given cost is positive since both positions
*	are in the top half of their respective stacks. the cost is decreased
*	as the stacks are rotated, when one reaches 0, the stacks have been 
*	rotated as far as possible and the top position is correct.
*/
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/* do_rotate_a:
*	Rotates STACK_A until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be
*	rotated.
*/
static void	do_rotate_a(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(stack_a);
			(*cost)++;
		}
	}
}

/* do_rotate_b:
*	Rotates STACK_B until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be
*	rotated.
*/
static void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

/* do_move:
*	chooses which move to make to get the STACK_B element into
*	the correct position in STACK_A.
*	If the cost of moving STACK_A and STACK_B into position match,
*	(i.e both negative or both positive) each stack will be rotated
*	or reverse rotated at the same time. They may also be rotated 
*	seperately, before finally pushing the top B element into the top
*	of STACK_A.
*/
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rr_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
		do_rotate_a(a, &cost_a);
		do_rotate_b(b, &cost_b);
		do_pa(a, b);
}