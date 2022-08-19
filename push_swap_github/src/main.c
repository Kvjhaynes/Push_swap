#include "push_swap.h"
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);

/* is_sorted:
*	checks if a stack is sorted.
*	returns 0 if the stack is not sorted, 1 if it is.
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
*	Chooses a sorting method depending on the number
*	of VALUES to be sorted.
*/

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		small_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/* main:
*	checks if the input is correct, then initializes STACK_A and STACK_B,
*	assigns each VALUE an INDEX then sorts the stacks. When sorting is done, frees
*	both stacks and exits.
*/
int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_val(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
