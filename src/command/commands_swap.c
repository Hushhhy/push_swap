/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:32:19 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/24 15:07:04 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sa(t_frst *stack, int text)
{
    t_stack *tmp;
    t_stack *last;

    last = ft_lstlast(stack->a);
    if (stack->size_a < 2)
        return ;
    tmp = stack->a;
    stack->a = stack->a->next;
    tmp->next = stack->a->next;
    last->next = stack->a;
    stack->a->next = tmp;
    if (text)
        write(1, "sa\n", 3);
}

void    ft_sb(t_frst *stack, int text)
{
    t_stack *tmp;

    if (stack->size_b < 2)
        return ;
    tmp = stack->b;
    stack->b = stack->b->next;
    tmp->next = stack->b->next;
    if (text)
        write(1, "sb\n", 3);
}