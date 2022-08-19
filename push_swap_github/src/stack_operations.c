/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:01:11 by khaynes           #+#    #+#             */
/*   Updated: 2022/07/07 16:43:45 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_last_stack:
*		returns the last element in stack.
*/
t_stack	*get_stack_tail(t_stack *stack)
{
	while(stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* get_penult_stack:
*		returns the second to last element in stack.
*/
t_stack	*get_penult_stack(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/* new_stack_el:
*		creates a new stack element with the provided value.
*		Returns the newly created stack element.
*/
t_stack	*new_stack_el(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}
/* add_stack_tail:
*			adds an element to the bottom of a stack.
*/
void	add_stack_tail(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return;
	}
	tail = get_stack_tail(*stack);
	tail->next = new;
}
/* get_stack_size:
*			returns number of elements in a stack.
*/
int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}