/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:57:17 by aperron           #+#    #+#             */
/*   Updated: 2024/02/11 01:43:16 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_to_b2(int *a_rotations, int *b_rotations, int atot, int btot)
{
	int	opp_a;
	int	opp_b;

	if (*a_rotations < 0 && *b_rotations < 0)
		return ;
	if (*a_rotations >= 0 && *b_rotations >= 0)
		return ;
	if (*a_rotations >= 0)
		opp_a = *a_rotations - atot;
	else
		opp_a = atot - abs(*a_rotations);
	if (*b_rotations >= 0)
		opp_b = *b_rotations - btot;
	else
		opp_b = btot - abs(*b_rotations);
	push_to_b3(a_rotations, b_rotations, opp_a, opp_b);
}

void	push_to_b(t_push_swap *push_swap, int index)
{
	int	a_rotations;
	int	b_rotations;
	int	atot;
	int	btot;

	atot = nb_in_stack(push_swap->a);
	btot = nb_in_stack(push_swap->b);
	a_rotations = index;
	if (index > nb_in_stack(push_swap->a) / 2)
		a_rotations -= nb_in_stack(push_swap->a);
	b_rotations = get_rotations(push_swap->b, value_index(push_swap->a, index));
	push_to_b2(&a_rotations, &b_rotations, atot, btot);
	push_to_b4(push_swap, &a_rotations, &b_rotations);
	push_to_b5(push_swap, b_rotations);
	pb(push_swap);
}

int	get_ideal_index_a(t_stack *a, int value)
{
	int	index;
	int	previous;

	index = 0;
	previous = value_index(a, nb_in_stack(a) - 1);
	while (a)
	{
		if (previous < value && a->value > value)
			return (index);
		previous = a->value;
		a = a->next;
		index++;
	}
	return (index);
}

// Get how many rotations to b to get ideal value on top of b
// positive if rotations negative if reverse rotations
int	get_rotations_a(t_stack *a, int value)
{
	int	nb;

	nb = 0;
	if (value < smallest_value(a) || value > biggest_value(a))
		nb = (index_smallest(a));
	else
		nb = get_ideal_index_a(a, value);
	if (nb > nb_in_stack(a) / 2)
		nb -= nb_in_stack(a);
	return (nb);
}

void	push_to_a(t_push_swap *push_swap)
{
	int	a_rotations;

	while (nb_in_stack(push_swap->b))
	{
		a_rotations = get_rotations_a(push_swap->a, push_swap->b->value);
		while (a_rotations != 0)
		{
			if (a_rotations < 0)
			{
				rra(push_swap);
				a_rotations++;
			}
			else
			{
				ra(push_swap);
				a_rotations--;
			}
		}
		pa(push_swap);
	}
}
