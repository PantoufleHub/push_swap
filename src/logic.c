/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:03:57 by aperron           #+#    #+#             */
/*   Updated: 2024/02/07 15:38:43 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	smallest;

	smallest = -2147483648;
	while (stack)
	{
		if (stack->value < smallest)
			return (0);
		smallest = stack->value;
		stack = stack->next;
	}
	return (1);
}

int	nb_in_stack(t_stack	*stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	finished(t_push_swap *push_swap)
{
	if (nb_in_stack(push_swap->b))
		return (0);
	if (!is_sorted(push_swap->a))
		return (0);
	return (1);
}

int	index_smallest(t_stack *stack)
{
	int	smallest;
	int	smallest_index;
	int	index;

	smallest = 2147483647;
	index = 0;
	while (stack)
	{
		if (stack->value <= smallest)
		{
			smallest = stack->value;
			smallest_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (smallest_index);
}

int	bubble_sort(t_push_swap *push_swap)
{
	int	moves;

	moves = 0;
	while (!finished(push_swap))
	{
		if (push_swap->b && is_sorted(push_swap->a)
			&& (!push_swap->a || push_swap->a->value > push_swap->b->value))
			pa(push_swap);
		else if (index_smallest(push_swap->a))
		{
			if (index_smallest(push_swap->a) <= nb_in_stack(push_swap->a) / 2)
				ra(push_swap);
			else
				rra(push_swap);
		}
		else
			pb(push_swap);
		moves++;
		display_push_swap(push_swap);
	}
	return (moves);
}
