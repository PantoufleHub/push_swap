/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:03:57 by aperron           #+#    #+#             */
/*   Updated: 2024/02/08 11:17:40 by aperron          ###   ########.fr       */
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

int	is_finished(t_push_swap *push_swap)
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

int	index_biggest(t_stack *stack)
{
	int	biggest;
	int	biggest_index;
	int	index;

	biggest = -2147483648;
	index = 0;
	while (stack)
	{
		if (stack->value >= biggest)
		{
			biggest = stack->value;
			biggest_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (biggest_index);
}
