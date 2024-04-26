/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:32:09 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/26 14:26:01 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_frst *stack, int text)
{
	if (stack->size_a < 2)
		return ;
	stack->a = stack->a->next;
	if (text)
		write(1, "ra\n", 3);
}

void	ft_rb(t_frst *stack, int text)
{
	if (stack->size_b < 2)
		return ;
	stack->b = stack->b->next;
	if (text)
		write(1, "rb\n", 3);
}
