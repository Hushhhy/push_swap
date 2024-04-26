/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:32:09 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/24 14:14:42 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_ra(t_frst *stack, int text)
{
    t_stack *tmp;

    if (stack->size_a < 2)
        return ;
    tmp = stack->a;
    stack->a = ft_lstlast(stack->a);
    stack->a->next = tmp;
    stack->a = tmp->next;
    tmp->next = NULL;
    if (text)
        write(1, "ra\n", 3);
}

void    ft_rb(t_frst *stack, int text)
{
    t_stack *tmp;

    if (stack->size_b < 2)
        return ;
    tmp = stack->b;
    stack->b = ft_lstlast(stack->b);
    stack->b->next = tmp;
    stack->b = tmp->next;
    tmp->next = NULL;
    if (text)
        write(1, "rb\n", 3);
}
