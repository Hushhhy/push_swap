/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:53:27 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/26 12:53:30 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra_rb(t_frst *stack, long long cost_ra, long long cost_rb)
{
    while (cost_ra != 0 && cost_rb != 0)
    {
        ft_rr(stack, 1);
        cost_ra--;
        cost_rb--;
    }
    while (cost_ra != 0)
    {
        ft_ra(stack, 1);
        cost_ra--;
    }
    while (cost_rb != 0)
    {
        ft_rb(stack, 1);
        cost_rb--;
    }
    ft_pa(stack, 1);
}

void    rra_rb(t_frst *stack, long long cost_rra, long long cost_rb)
{
    while (cost_rra != 0)
    {
        ft_rra(stack, 1);
        cost_rra--;
    }
    while (cost_rb != 0)
    {
        ft_rb(stack, 1);
        cost_rb--;
    }
    ft_pa(stack, 1);
}

void    ra_rrb(t_frst *stack, long long cost_ra, long long cost_rrb)
{
    while (cost_ra != 0)
    {
        ft_ra(stack, 1);
        cost_ra--;
    }
    while (cost_rrb != 0)
    {
        ft_rrb(stack, 1);
        cost_rrb--;
    }
    ft_pa(stack, 1);
}

void    rra_rrb(t_frst *stack, long long cost_rra, long long cost_rrb)
{
    while (cost_rra != 0 && cost_rrb != 0)
    {
        ft_rrr(stack, 1);
        cost_rra--;
        cost_rrb--;
    }
    while (cost_rra != 0)
    {
        ft_rra(stack, 1);
        cost_rra--;
    }
    while (cost_rrb != 0)
    {
        ft_rrb(stack, 1);
        cost_rrb--;
    }
    ft_pa(stack, 1);
}