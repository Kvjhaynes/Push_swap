/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:31:47 by khaynes           #+#    #+#             */
/*   Updated: 2022/07/05 15:35:37 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* fill_stack:
 * 		fills Stack_A with the provided values.
 * 		If the Values are out of MAX or MIN range, prints error and exits.
 */
 t_stack	*fill_stack_val(int ac, char **av)
 {
	 t_stack	*stack_a;
	 long int	nb;
	 int		i;

	 stack_a = NULL;
	 nb = 0;
	 i = 1;
	 while (i < ac)
	 {
		 nb = ft_atoi(av[i]);
		 if (nb > INT_MAX || nb < INT_MIN)
		 	exit_error(&stack_a, NULL);
		 if (i == 1)
		 	stack_a = new_stack_el((int)nb);
		 else
			add_stack_tail(&stack_a, new_stack_el((int)nb));
		 i++;
	 }
	 return (stack_a);
 }

/* assign_index:
*	assigns an index to each VALUE in STACK_A, this is how we
*	order the VALUES in the stack so they can be sorted. We compare
*	the INDEX value instead of the actual VALUE.
*	EXAMPLE:
*			VALUE	-3	 0	 4	 3
*			INDEX	[1] [2] [4] [3]
*	Indexes are assigned from highest to lowest.
*/
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}