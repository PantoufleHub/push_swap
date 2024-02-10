/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:33:40 by aperron           #+#    #+#             */
/*   Updated: 2024/02/10 18:35:56 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# include "../libft/libft.h"

# include "structure.h"

int				abs(int value);

int				biggest_value(t_stack *stack);

void			bubble_sort(t_push_swap *push_swap);

void			check_input(int argc, const char *argv[]);

void			display_push_swap(t_push_swap *push_swap);

void			exit_with_error_message(char *message);

void			free_pushswap(t_push_swap *push_swap);

int				get_big_small(int value1, int value2, int smallest);

int				get_ideal_index(t_stack *b, int value);

int				get_rotations(t_stack *b, int value);

int				index_biggest(t_stack *stack);

int				index_smallest(t_stack *stack);

t_push_swap		*init_push_swap(const char *argv[], int argc);

int				is_finished(t_push_swap *push_swap);

int				is_sorted(t_stack *stack);

long			my_atoi(char *str);

int				nb_in_stack(t_stack	*stack);

void			new_stack_back(t_stack **stack, int value);

void			new_stack_front(t_stack **stack, int value);

void			push(t_stack **src, t_stack **dest);

void			push_to_b(t_push_swap *push_swap, int index);

void			push_to_a(t_push_swap *push_swap);

void			reverse_rotate(t_stack **stack);

void			rotate(t_stack **stack);

int				smallest_value(t_stack *stack);

void			sort(t_push_swap *push_swap);

void			sort_for_3(t_push_swap *push_swap);

void			swap(t_stack **stack);

void			turk_sort(t_push_swap *push_swap);

int				value_index(t_stack *stack, int index);

void			sa(t_push_swap *push_swap);

void			sb(t_push_swap *push_swap);

void			ss(t_push_swap *push_swap);

void			pa(t_push_swap *push_swap);

void			pb(t_push_swap *push_swap);

void			ra(t_push_swap *push_swap);

void			rb(t_push_swap *push_swap);

void			rr(t_push_swap *push_swap);

void			rra(t_push_swap *push_swap);

void			rrb(t_push_swap *push_swap);

void			rrr(t_push_swap *push_swap);

#endif