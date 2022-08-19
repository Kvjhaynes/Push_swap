/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:22:50 by khaynes           #+#    #+#             */
/*   Updated: 2022/08/12 14:08:39 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int 			cost_a;
	int 			cost_b;
	struct	s_stack *next;
}	t_stack;

/* value = int we are sorting.
 * index = index position of all values for sorting.
 * pos = current position of value in its stack.
 * target_pos = for elements in stack B, it's target position
 * 				in Stack A.
 * cost_a = action cost to rotate Stack A so that the element
 * 			at target postion gets to the top of stack A.
 * cost_b = action cost to rotate Stack B.
 * next = pointer to the next element in the list */

/*			Input Utils					*/
void		free_stack(t_stack **stack);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);

/*			UTILS						*/
void		free_stack(t_stack **stack);
void		exit_error(t_stack **stack_a, t_stack **stack_b);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			abs_val(int nb);

/*			Argument Checks				*/
int			is_correct_input(char **av);

/*			Stack Operations			*/
t_stack	*get_stack_tail(t_stack *stack);
t_stack	*get_penult_stack(t_stack *stack);
t_stack	*new_stack_el(int value);
void	add_stack_tail(t_stack **stack, t_stack *new);
int		get_stack_size(t_stack *stack);

/*			Position Functions			*/
int			get_lowest_index_pos(t_stack **stack);
void		get_target_pos(t_stack **a, t_stack **b);

/*			Initialisation Functions	*/
t_stack	*fill_stack_val(int ac, char **argv);
void	assign_index(t_stack *stack_a, int ac);

/*			PUSH						*/
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);

/*			ROTATE						*/
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);

/*			REVERSE ROTATE				*/
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);

/*			SWAP						*/
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);

/*			Sort Small					*/
void		small_sort(t_stack **stack);

/*			MAIN						*/
int			is_sorted(t_stack *stack);
int			main(int ac, char **av);

/*			SORT						*/
void		sort(t_stack **stack_a, t_stack **stack_b);

/*			DO MOVE						*/
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/*			COST						*/
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

#endif
