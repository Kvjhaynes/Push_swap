#include "push_swap.h"
static void	swap(t_stack *stack);

/*	swap:
*	swaps the two elements of a stack.
*	does nothing if there is only one or no elements.
*/
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* do_sa:
*	swaps the top 2 elements of STACK_A.
*	prints "sa" to the standard output.
*/
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* do_sb:
*	swaps the two top elements of STACK_B.
*	prints "sa" to the STDOUT.
*/
void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* do_ss:
*	swaps the top 2 elements of STACK_A and STACK_B.
*	prints "ss" to the STDOUT.
*/
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}