/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:26:36 by aperron           #+#    #+#             */
/*   Updated: 2024/02/07 15:08:17 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	check_duplicates(t_stack *stack)
{
	t_stack	*node;

	while (stack)
	{
		node = stack->next;
		while (node)
		{
			if (node->value == stack->value)
				exit_with_error_message("Duplicates in input!");
			node = node->next;
		}
		stack = stack->next;
	}
}

t_push_swap	*init_push_swap(const char *argv[], int argc)
{
	int			index;
	t_push_swap	*stacks;

	stacks = malloc(sizeof(t_push_swap));
	if (!stacks)
		exit_with_error_message("Failed to allocate push_swap");
	stacks->b = NULL;
	stacks->a = NULL;
	index = 1;
	while (index < argc)
	{
		new_stack_back(&stacks->a, my_atoi((char *)argv[index]));
		index++;
	}
	check_duplicates(stacks->a);
	return (stacks);
}
