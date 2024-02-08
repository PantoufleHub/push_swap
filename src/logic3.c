/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:47:43 by aperron           #+#    #+#             */
/*   Updated: 2024/02/08 16:13:22 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// Get how many rotations to b to get ideal value on top of b
// positive if rotations negative if reverse rotations
// int	get_rotations(t_stack *b, int value)
// {
	
// }

// Get how many moves to push value at index in stack a
// to correct position in stack b
// returns positive if rotate negative if reverse rotate
// int	get_nb_moves(t_push_swap *push_swap, int index)
// {
	
// }

void	turk_sort(t_push_swap *push_swap)
{
	pb(push_swap);
	pb(push_swap);
	while (nb_in_stack(push_swap->a))
	{
		// calc easiest to push b
		// rotate a and b accordingly
		// push b
		pb(push_swap);
	}
	while (!is_finished(push_swap))
		pa(push_swap);
}
