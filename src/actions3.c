/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:41:32 by aperron           #+#    #+#             */
/*   Updated: 2024/02/07 11:43:45 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rra(t_push_swap *push_swap)
{
	reverse_rotate(&push_swap->a);
	ft_printf("rra\n");
}

void	rrb(t_push_swap *push_swap)
{
	reverse_rotate(&push_swap->b);
	ft_printf("rrb\n");
}

void	rrr(t_push_swap *push_swap)
{
	reverse_rotate(&push_swap->a);
	reverse_rotate(&push_swap->b);
	ft_printf("rrr\n");
}
