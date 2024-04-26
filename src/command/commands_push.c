/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:31:45 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/26 14:25:39 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_frst *stack, int text)
{
	t_stack	*tmp;

	if (stack->size_b < 1)
		return ;
	tmp = stack->a;
	stack->a = stack->b;
	if (stack->size_b > 1)
	{
		ft_lastnode(stack->b)->next = stack->b->next;
		stack->b = stack->b->next;
	}
	else
		stack->b = NULL;
	stack->a->next = tmp;
	ft_lastnode(tmp)->next = stack->a;
	stack->size_a += 1;
	stack->size_b -= 1;
	if (text)
		write(1, "pa\n", 3);
}

void	ft_pb(t_frst *stack, int text)
{
	t_stack	*tmp;

	if (stack->size_a < 1)
		return ;
	if (stack->size_b == 0)
		tmp = NULL;
	else
		tmp = stack->b;
	stack->b = stack->a;
	ft_lastnode(stack->a)->next = stack->a->next;
	stack->a = stack->a->next;
	stack->b->next = tmp;
	if (tmp)
		ft_lastnode(tmp)->next = stack->b;
	else
		stack->b->next = stack->b;
	stack->size_b += 1;
	stack->size_a -= 1;
	if (text)
		write(1, "pb\n", 3);
}
