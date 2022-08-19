#include "push_swap.h"
static void	push(t_stack **src, t_stack **dest);

/* push;
*	pushes the top element of src stack to the top of dest stack.
*/

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;
	
	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

/* do_pa;
*	pushes the top element of STACK_B to the top of STACK_A.
*	prints "pa" to STDOUT.
*/
void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

/* do_pb:
*	pushes to the top element of STACK_A to the top of STACK_B.
*	prints "pb" to STDOUT.
*/
void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}