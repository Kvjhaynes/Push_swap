#include "push_swap.h"
static void	rotate(t_stack **stack);

/* rotate:
*	the top element of the stack is sent to the bottom of the same stack.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_tail(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/* do_ra:
*	sends the top element of STACK_A to the bottom.
*	prints "ra" to the STDOUT.
*/
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/* do_rb:
*	sends the top element of STACK_B to the bottom.
*	prints "rb" to the STDOUT.
*/
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/* do_rr:
*	sends the top element of STACK_A and STACK_B to the bottom of their
*	respective stacks.
*	prints "rr" to the STDOUT.
*/
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}