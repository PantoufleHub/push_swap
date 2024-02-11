/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:42:48 by aperron           #+#    #+#             */
/*   Updated: 2024/02/11 01:43:00 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	get_nb_moves3(int a_rotations, int b_rotations, int opp_a, int opp_b)
{
	int	smallest;

	smallest = 2147483647;
	if (a_rotations >= 0)
	{
		smallest = get_big_small(a_rotations + abs(b_rotations), smallest, 1);
		smallest = get_big_small(a_rotations + opp_b, smallest, 1);
		smallest = get_big_small(abs(opp_a) + abs(b_rotations), smallest, 1);
	}
	else
	{
		smallest = get_big_small(abs(a_rotations) + b_rotations, smallest, 1);
		smallest = get_big_small(abs(a_rotations) + abs(opp_b), smallest, 1);
		smallest = get_big_small(opp_a + b_rotations, smallest, 1);
	}
	return (smallest);
}

int	get_nb_moves2(int a_rotations, int b_rotations, int atot, int btot)
{
	int	nb_moves;
	int	opp_a;
	int	opp_b;

	if (a_rotations < 0 && b_rotations < 0)
		return (abs(get_big_small(a_rotations, b_rotations, 1)));
	if (a_rotations >= 0 && b_rotations >= 0)
		return (get_big_small(a_rotations, b_rotations, 0));
	if (a_rotations >= 0)
		opp_a = a_rotations - atot;
	else
		opp_a = atot - abs(a_rotations);
	if (b_rotations >= 0)
		opp_b = b_rotations - btot;
	else
		opp_b = btot - abs(b_rotations);
	nb_moves = get_nb_moves3(a_rotations, b_rotations, opp_a, opp_b);
	return (nb_moves);
}

void	push_to_b5(t_push_swap *push_swap, int b_rotations)
{
	while (b_rotations != 0)
	{
		if (b_rotations > 0)
		{
			rb(push_swap);
			b_rotations--;
		}
		else
		{
			rrb(push_swap);
			b_rotations++;
		}
	}
}

void	push_to_b4(t_push_swap *push_swap, int *a_rotations, int *b_rotations)
{
	while (*a_rotations != 0)
	{
		if (*a_rotations > 0)
		{
			if (*b_rotations > 0)
			{
				rr(push_swap);
				*b_rotations -= 1;
			}
			else
				ra(push_swap);
			*a_rotations -= 1;
		}
		else if (*a_rotations < 0)
		{
			if (*b_rotations < 0)
			{
				rrr(push_swap);
				*b_rotations += 1;
			}
			else
				rra(push_swap);
			*a_rotations += 1;
		}
	}
}

void	push_to_b3(int *a_rotations, int *b_rots, int opp_a, int opp_b)
{
	int	small;

	if (*a_rotations >= 0)
	{
		small = *a_rotations + abs(*b_rots);
		if (get_big_small(*a_rotations + opp_b, small, 1) < small)
		{
			*b_rots = opp_b;
			small = get_big_small(*a_rotations + opp_b, small, 1);
		}
		else if (get_big_small(abs(opp_a) + abs(*b_rots), small, 1) < small)
			*a_rotations = opp_a;
	}
	else
	{
		small = abs(*a_rotations) + *b_rots;
		if (get_big_small(abs(*a_rotations) + abs(opp_b), small, 1) < small)
		{
			*b_rots = opp_b;
			small = get_big_small(abs(*a_rotations) + abs(opp_b), small, 1);
		}
		if (get_big_small(opp_a + *b_rots, small, 1) < small)
			*a_rotations = opp_a;
	}
}
