/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:04:10 by aperron           #+#    #+#             */
/*   Updated: 2024/02/10 16:39:15 by aperron          ###   ########.fr       */
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
	if (value == 0)
		neg = 1;
	return (value * neg);
}

int	abs(int value)
{
	if (value == -2147483648)
		exit_with_error_message("Absolute value of -2147483648 too big");
	if (value < 0)
		return (-value);
	else
		return (value);
}

int	get_big_small(int value1, int value2, int smallest)
{
	if (smallest == 1)
	{
		if (value1 < value2)
			return (value1);
		return (value2);
	}
	if (value1 > value2)
		return (value1);
	return (value2);
}

void	display_push_swap(t_push_swap *push_swap)
{
	t_stack	*a;
	t_stack	*b;
	int		index;

	index = 0;
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
