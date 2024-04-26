/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:31:45 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/24 15:31:20 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_pa(t_frst *stack, int text)
{
    t_stack *tmp;

    if (stack->size_b < 1)
        return ;
    tmp = stack->a;
    stack->a = stack->b;
    stack->b = stack->b->next;
    stack->a->next = tmp;
    stack->size_a += 1;
    stack->size_b -= 1;
    if (text)
        write(1, "pa\n", 3);
}

void    ft_pb(t_frst *stack, int text)
{
    t_stack *tmp;
    
    if (stack->size_a < 1)
        return ;
    if (stack->size_b == 0)
        tmp = NULL;
    else
        tmp = stack->b;
    stack->b = stack->a;
    stack->a = stack->a->next;
    stack->b->next = tmp;
    stack->size_b += 1;
    stack->size_a -= 1;
    if (text)
        write(1, "pb\n", 3);
}