/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:23:20 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/24 14:02:45 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ending(t_frst *stack)
{
    long long   min;
    long long   pos;
    long long   i;

    min = min_a(stack);
    pos = 0;
    while (stack->a->data != min)
        pos++;
    i = 0;
    if (pos < stack->size_a - pos)
    {
        while (i < pos)
        {
            ft_ra(stack, 1);
            i++;
        }
        return ;
    }
    while (i < stack->size_a - pos)
    {
        ft_rra(stack, 1);
        i++;
    }
}
