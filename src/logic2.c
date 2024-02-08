/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:27:03 by aperron           #+#    #+#             */
/*   Updated: 2024/02/08 16:05:01 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// void	bubble_sort(t_push_swap *push_swap)
// {
// 	while (!finished(push_swap))
// 	{
// 		if (push_swap->b && is_sorted(push_swap->a)
// 			&& (!push_swap->a || push_swap->a->value > push_swap->b->value))
// 			pa(push_swap);
// 		else if (index_smallest(push_swap->a))
// 		{
// 			if (index_smallest(push_swap->a) <= nb_in_stack(push_swap->a) / 2)
// 				ra(push_swap);
// 			else
// 				rra(push_swap);
// 		}
// 		else
// 			pb(push_swap);
// 	}
// }

int	value_at_index(t_stack *stack, int index)
{
	while (index-- > 0)
		stack = stack->next;
	return (stack->value);
}

void	sort_for_3(t_push_swap *push_swap)
{
	t_stack	**a;

	a = &push_swap->a;
	if ((index_smallest(*a) == 2 && index_biggest(*a) == 0)
		|| (index_smallest(*a) == 0 && index_biggest(*a) == 1))
		sa(push_swap);
	if (index_smallest(*a) == 2)
		rra(push_swap);
	else if (index_biggest(*a) == 0)
		ra(push_swap);
	else
		sa(push_swap);
}

void	sort(t_push_swap *push_swap)
{
	if (is_finished(push_swap))
		return ;
	if (nb_in_stack(push_swap->a) == 2)
		sa(push_swap);
	else if (nb_in_stack(push_swap->a) == 3)
		sort_for_3(push_swap);
	else
	{
		turk_sort(push_swap);
		ft_printf("pourt\n");
	}
}

int	biggest_value(t_stack *stack)
{
	return (value_at_index(stack, index_biggest(stack)));
}

int	smallest_value(t_stack *stack)
{
	return (value_at_index(stack, index_smallest(stack)));
}
