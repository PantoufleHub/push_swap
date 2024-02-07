/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:04:10 by aperron           #+#    #+#             */
/*   Updated: 2024/02/07 11:57:14 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	exit_with_error_message(char *message)
{
	ft_printf("Error\n");
	ft_printf(message);
	ft_printf("\n");
	exit(0);
}

long	my_atoi(char *str)
{
	long	value;
	long	index;
	int		neg;

	if (ft_strlen(str) == 0)
		return (0);
	index = 0;
	neg = 1;
	if (str[0] == '-')
	{
		neg = -1;
		index = 1;
	}
	value = 0;
	while (index < (long)ft_strlen(str))
	{
		value *= 10;
		value += str[index] - '0';
		index++;
	}
	return (value * neg);
}

void	display_stack(const char *title, t_stack *stack)
{
	int	index;

	index = 1;
	ft_printf("%s\n", title);
	ft_printf("--------------\n");
	while (stack)
	{
		ft_printf("Value %d: %d\n", index, stack->value);
		stack = stack->next;
		index++;
	}
	ft_printf("--------------\n");
}

void	display_push_swap(t_push_swap *push_swap)
{
	t_stack	*a;
	t_stack	*b;
	int		index;

	index = 1;
	a = push_swap->a;
	b = push_swap->b;
	ft_printf("Stacks:\n");
	ft_printf("--I----A-----B---\n");
	while (a || b)
	{
		if (!a && b)
			ft_printf("| %d |     |  %d  |\n", index, b->value);
		else if (a && !b)
			ft_printf("| %d |  %d  |     |\n", index, a->value);
		else
			ft_printf("| %d |  %d  |  %d  |\n", index, a->value, b->value);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		index++;
	}
	ft_printf("-----------------\n");
}

void	new_stack_front(t_stack **stack, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = value;
	new->next = *stack;
	*stack = new;
}
