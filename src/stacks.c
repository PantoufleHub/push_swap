/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:54:21 by aperron           #+#    #+#             */
/*   Updated: 2024/02/07 10:48:49 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	new_stack_back(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp)
		{
			if (tmp->next)
				tmp = tmp->next;
			else
			{
				tmp->next = new;
				break ;
			}
		}
	}
}

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		exit_with_error_message("Unable to swap stack!");
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	*stack = tmp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src)
		exit_with_error_message("Pushing empty stack!");
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	rotate(t_stack *stack)
{
	stack = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	stack = NULL;
}
