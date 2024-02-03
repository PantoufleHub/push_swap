/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:53:01 by aperron           #+#    #+#             */
/*   Updated: 2024/02/03 21:28:31 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	check_int(const char *input)
{
	long	value;

	value = my_atoi((char *)input);
	if (value > 2147483647)
		exit_with_error_message("Value bigger than int!");
	if (value < -2147483648)
		exit_with_error_message("Value smaller than int!");
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
			if (index != 0 || (index == 0 && input[index] != '-'))
				exit_with_error_message("Non-numerical values");
		}
		index++;
	}
}

void	check_duplicates(int argc, const char *argv[])
{
	char		*input;
	int			index;
	int			index2;
	size_t		len;

	index = 0;
	index2 = 0;
	while (index < argc - 1)
	{
		index2 = index + 1;
		input = (char *)argv[index];
		while (index2 < argc)
		{
			len = ft_strlen(input);
			if (ft_strlen(argv[index2]) > len)
				len = ft_strlen(argv[index2]);
			if (!ft_strncmp(argv[index2], input, len))
				exit_with_error_message("Duplicates in input!");
				index2++;
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
	check_duplicates(argc, argv);
	while (arg_nb < argc)
	{
		check_numeric(argv[arg_nb]);
		check_int(argv[arg_nb]);
		arg_nb++;
	}
}
