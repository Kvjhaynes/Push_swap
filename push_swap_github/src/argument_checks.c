/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:43:30 by khaynes           #+#    #+#             */
/*   Updated: 2022/07/07 16:43:32 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	arg_is_num(char *av);
static int	has_dup(char **av);
static int	arg_is_zero(char *av);

/* arg_is_num:
*		checks if the argument is a number.
*		returns 1 if arg is a number, 0 if not.
*/
static int	arg_is_num(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i] && av[i + 1] != '\0'))
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* has_dup:
*		checks if the argument list has duplicate numbers.
*		return 1 if a duplicate is found, 0 if not.
*/
static int	has_dup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* arg_is_zero:
*		checks the argument for 0 to avoid 0 +0 -0 duplicates.
*		return 1 if the arg is a zero, 0 if it contains anything
*		other than 0.
*/
static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/* is_correct_input:
*		Checks if all the given args are all numbers, without duplicates.
*		return 1 if true, 0 if not.
*/
int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_num(av[i]))
			return (0);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (has_dup(av))
		return (0);
	return (1);
}