/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:43:37 by khaynes           #+#    #+#             */
/*   Updated: 2022/07/07 16:43:39 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	get_pos(t_stack **stack);
static int	get_target(t_stack **a, int b_idx, int tgt_idx, int tgt_pos);

/* get_pos:
*	assigns a position to each element in a stack, from top to bottom
*	in ascending order.
*	EXAMPLE:
*			VALUE:		 6		 1		 9		 4
*			INDEX:		[3]		[1]		[4]		[3]
*			POS:		<0>		<1>		<2>		<3>
*	this POS is used to calculate the cost of moving a VALUE
*	to another POS. If the above example is STACK_B, it would
*	cost nothing to push the first element to STACK_A, however if we
*	wanted push the highest VALUE, 9, at POS <2>, which is the third
*	postion, it would cost 2 RB moves to bring that 9 to the top of
*	STACK_B before we can push it STACK_A.
*/

static void	get_pos(t_stack **stack)
{
	t_stack *tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* get_lowest_index_pos:
*		gets the POS of the element with the lowest INDEX in a
*		stack.
*/

int	get_lowest_index_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_pos(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_target:
*	Picks the best target POS in STACK_A for the given INDEX of an
*	element in STACK_B. First check is if the INDEX of the element
*	fits somewhere in between elements in STACK_A, by checking if there
*	is an element with an INDEX in STACK_A greater than its own. if not,
*	it finds the element in STACK_A with the smallest index in A and assigns
*	that as the target POS.
*/

static int	get_target(t_stack **a, int b_idx, int tgt_idx, int tgt_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < tgt_idx)
		{
			tgt_idx = tmp_a->index;
			tgt_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (tgt_idx != INT_MAX)
		return (tgt_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < tgt_idx)
		{
			tgt_idx = tmp_a->index;
			tgt_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (tgt_pos);
}

/* get_target_pos:
*	assigns a target postion in STACK_A to each element of STACK_A.
*	the target postion is the spot that the element from STACK_B needs
*	needs to get to in order to be sorted correctly. This position will
*	be used to calculate the cost of moving each element to its target
*	position in STACK_A.
*/

void	get_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_pos(a);
	get_pos(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
