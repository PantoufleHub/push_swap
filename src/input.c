/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:53:01 by aperron           #+#    #+#             */
/*   Updated: 2024/02/07 15:02:38 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	check_int(const char *input)
{
	long	value;

	value = my_atoi((char *)input);
	if (value > 2147483647)
		exit_with_error_message("Values must be integers!");
	if (value < -2147483648)
		exit_with_error_message("Values must be integers!");
}

void	check_numeric(const char *input)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = ft_strlen(input);
	while (index < len)
	{
		if (!ft_isdigit(input[index]))
		{
			if (index != 0 || (index == 0 && input[index] != '-')
				|| (len == 1 && input[index] == '-'))
				exit_with_error_message("Non-numerical values");
		}
		index++;
	}
}

void	check_input(int argc, const char *argv[])
{
	int	arg_nb;

	if (argc < 2)
		exit(0);
	arg_nb = 1;
	while (arg_nb < argc)
	{
		check_numeric(argv[arg_nb]);
		check_int(argv[arg_nb]);
		arg_nb++;
	}
}
