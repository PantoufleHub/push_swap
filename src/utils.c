/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:04:10 by aperron           #+#    #+#             */
/*   Updated: 2024/02/03 21:30:14 by aperron          ###   ########.fr       */
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
