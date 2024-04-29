/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:11:49 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/29 17:21:52 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	max_num(long long nbr0, long long nbr1)
{
	if (nbr0 > nbr1)
		return (nbr0);
	return (nbr1);
}

long long	optimal_cost(long long ra, long long rra, long long rb,
														long long rrb)
{
	long long	ra_rb;
	long long	ra_rrb;
	long long	rra_rb;
	long long	rra_rrb;

	ra_rb = max_num(ra, rb);
	ra_rrb = ra + rrb;
	rra_rb = rra + rb;
	rra_rrb = max_num(rra, rrb);
	if (ra_rb <= ra_rrb && ra_rb <= rra_rb && ra_rb <= rra_rrb)
		return (1);
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rb && ra_rrb <= rra_rrb)
		return (2);
	else if (rra_rb <= ra_rb && rra_rb <= ra_rrb && rra_rb <= rra_rrb)
		return (3);
	else
		return (4);
}

void	operations(t_frst *stack, long long nbr)
{
	long long	ra;
	long long	rb;
	long long	rra;
	long long	rrb;
	long long	opti;

	ra = cost_ra(stack, nbr);
	rb = cost_rb(stack, nbr);
	rra = cost_rra(stack, nbr);
	rrb = cost_rrb(stack, nbr);
	opti = optimal_cost(ra, rra, rb, rrb);
	if (opti == 1)
		ra_rb(stack, ra, rb);
	else if (opti == 2)
		ra_rrb(stack, ra, rrb);
	else if (opti == 3)
		rra_rb(stack, rra, rb);
	else
		rra_rrb(stack, rra, rrb);
}

long long	cost_finder(t_frst *stack, long long nbr)
{
	long long	ra;
	long long	rb;
	long long	rra;
	long long	rrb;
	long long	opti;

	ra = cost_ra(stack, nbr);
	rb = cost_rb(stack, nbr);
	rra = cost_rra(stack, nbr);
	rrb = cost_rrb(stack, nbr);
	opti = optimal_cost(ra, rra, rb, rrb);
	if (opti == 1)
		return (max_num(ra, rb));
	else if (opti == 2)
		return (ra + rrb);
	else if (opti == 3)
		return (rra + rb);
	else
		return (max_num(rra, rrb));
}

void	cost(t_frst *stack)
{
	long long	*cost;
	long long	i;
	long long	min_pos;

	while (stack->size_b != 0)
	{
		min_pos = 0;
		cost = malloc(sizeof(long long) * stack->size_b);
		if (!cost)
			return (error_free(stack));
		i = 0;
		// printf("%lld\n", stack->size_b);
		while (i < stack->size_b)
		{
			cost[i] = cost_finder(stack, partition_utils(stack->b, i)->data);
			if (cost[i] < cost[min_pos])
				min_pos = i;
			i++;
		}
		operations(stack, partition_utils(stack->b, min_pos)->data);
		free(cost);
	}
	ending(stack);
}
