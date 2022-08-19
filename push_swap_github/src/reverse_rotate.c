#include "push_swap.h"
static void	rev_rotate(t_stack **stack);

/* rev_rotate:
*	Brings the bottom element of a stack to the top.
*/
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*penult_tail;

	tail = get_stack_tail(*stack);
	penult_tail = get_penult_stack(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	penult_tail->next = NULL;
}

/* do_rra:
*	brings the bottom element of STACK_A to the top.
*	prints "rra" to the STDOUT.
*/
void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

/* do_rrb:
*	brings the bottom element of STACK_B to the top.
*	prints "rrb" to the STDOUT.
*/
void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/* do_rrr:
*	brings the bottom element of STACK_A and STACK_B
*	to the top.
*	prints "rrr" to the STDOUT.
*/
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}