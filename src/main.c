/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:27:23 by aperron           #+#    #+#             */
/*   Updated: 2024/02/07 11:58:56 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_push_swap	*stacks;

	check_input(argc, argv);
	stacks = init_push_swap(argv, argc);
	display_push_swap(stacks);
	sa(stacks);
	display_push_swap(stacks);
	pb(stacks);
	display_push_swap(stacks);
	pb(stacks);
	display_push_swap(stacks);
	pb(stacks);
	display_push_swap(stacks);
	sb(stacks);
	display_push_swap(stacks);
	ss(stacks);
	display_push_swap(stacks);
	pa(stacks);
	display_push_swap(stacks);
	ra(stacks);
	display_push_swap(stacks);
	rb(stacks);
	display_push_swap(stacks);
	rr(stacks);
	display_push_swap(stacks);
	rra(stacks);
	display_push_swap(stacks);
	rrb(stacks);
	display_push_swap(stacks);
	rrr(stacks);
	display_push_swap(stacks);
	ft_printf("end\n");
	return (0);
}
