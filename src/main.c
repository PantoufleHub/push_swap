/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:27:23 by aperron           #+#    #+#             */
/*   Updated: 2024/02/07 09:56:16 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_push_swap	*stacks;

	check_input(argc, argv);
	stacks = init_push_swap(argv, argc);
	display_push_swap(stacks);
	push(&stacks->a, &stacks->b);
	display_push_swap(stacks);
	push(&stacks->a, &stacks->b);
	display_push_swap(stacks);
	push(&stacks->a, &stacks->b);
	display_push_swap(stacks);
	push(&stacks->b, &stacks->a);
	display_push_swap(stacks);
	push(&stacks->b, &stacks->a);
	display_push_swap(stacks);
	push(&stacks->b, &stacks->a);
	display_push_swap(stacks);
	return (0);
}
