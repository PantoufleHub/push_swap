/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperron <aperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:33:40 by aperron           #+#    #+#             */
/*   Updated: 2024/02/07 11:29:08 by aperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# include "../libft/libft.h"

# include "structure.h"

void			check_input(int argc, const char *argv[]);

void			display_push_swap(t_push_swap *push_swap);

void			exit_with_error_message(char *message);

t_push_swap		*init_push_swap(const char *argv[], int argc);

long			my_atoi(char *str);

void			new_stack_back(t_stack **stack, int value);

void			new_stack_front(t_stack **stack, int value);

void			push(t_stack **src, t_stack **dest);

void			reverse_rotate(t_stack **stack);

void			rotate(t_stack **stack);

void			swap(t_stack **stack);

#endif