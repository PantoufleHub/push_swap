/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:36:34 by aperron           #+#    #+#             */
/*   Updated: 2024/02/07 11:43:00 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ra(t_push_swap *push_swap)
{
	rotate(&push_swap->a);
	ft_printf("ra\n");
}

void	rb(t_push_swap *push_swap)
{
	rotate(&push_swap->b);
	ft_printf("rb\n");
}

void	rr(t_push_swap *push_swap)
{
	rotate(&push_swap->a);
	rotate(&push_swap->b);
	ft_printf("rr\n");
}
