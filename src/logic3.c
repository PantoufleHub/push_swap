/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:47:43 by aperron           #+#    #+#             */
/*   Updated: 2024/02/11 00:53:34 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	get_ideal_index(t_stack *b, int value)
{
	int	index;
	int	bigger_found;

	index = 0;
	bigger_found = 0;
	while (b)
	{
		if (b->value > value)
			bigger_found = 1;
		if (bigger_found && b->value < value)
			break ;
		b = b->next;
		index++;
	}
	return (index);
}

// Get how many rotations to b to get ideal value on top of b
// positive if rotations negative if reverse rotations
int	get_rotations(t_stack *b, int value)
{
	int	nb;

	nb = 0;
	if (value < smallest_value(b) || value > biggest_value(b))
		nb = (index_biggest(b));
	else
		nb = get_ideal_index(b, value);
	if (nb > nb_in_stack(b) / 2)
		nb -= nb_in_stack(b);
	return (nb);
}

// Get how many moves to push value at index in stack a
// to correct position in stack b
int	get_nb_moves(t_push_swap *push_swap, int index)
{
	int	nb_moves;
	int	a_rotations;
	int	b_rotations;
	int	a_tot;
	int	b_tot;

	b_rotations = get_rotations(push_swap->b, value_index(push_swap->a, index));
	a_rotations = index;
	if (index > nb_in_stack(push_swap->a) / 2)
		a_rotations -= nb_in_stack(push_swap->a);
	a_tot = nb_in_stack(push_swap->a);
	b_tot = nb_in_stack(push_swap->b);
	nb_moves = get_nb_moves2(a_rotations, b_rotations, a_tot, b_tot);
	// ft_printf("\nOop--\n");
	// display_push_swap(push_swap);
	// ft_printf("Index: %d, nbMoves:%d\n", index, nb_moves);
	return (nb_moves);
}

void	push_easiest(t_push_swap *push_swap)
{
	int	index;
	int	least_moves;
	int	least_index;

	index = 0;
	least_moves = 2147483647;
	least_index = 0;
	while (index < nb_in_stack(push_swap->a))
	{
		if (get_nb_moves(push_swap, index) < least_moves)
		{
			least_moves = get_nb_moves(push_swap, index);
			least_index = index;
		}
		index++;
	}
	push_to_b(push_swap, least_index);
}

void	turk_sort(t_push_swap *push_swap)
{
	int	rot;

	pb(push_swap);
	pb(push_swap);
	while (nb_in_stack(push_swap->a) > 3)
		push_easiest(push_swap);
	// ft_printf("\n-- Sorting for 3 --\n");
	sort_for_3(push_swap);
	// ft_printf("\n-- Pushing to A --\n");
	// display_push_swap(push_swap);
	push_to_a(push_swap);
	rot = index_smallest(push_swap->a);
	if (rot > nb_in_stack(push_swap->a) / 2)
		rot -= nb_in_stack(push_swap->a);
	while (rot != 0)
	{
		if (rot < 0)
		{
			rra(push_swap);
			rot++;
		}
		else
		{
			ra(push_swap);
			rot--;
		}
	}
}
