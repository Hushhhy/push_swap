/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:25:19 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/26 14:22:03 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	min_a(t_frst *stack)
{
	long long	i;
	long long	min;
	t_stack		*tmp;

	i = 1;
	min = stack->a->data;
	tmp = stack->a;
	while (i < stack->size_a)
	{
		tmp = tmp->next;
		if (tmp->data < min)
			min = tmp->data;
		i++;
	}
	return (min);
}

long long	cost_ra(t_frst *stack, long long nbr)
{
	const long long	min = min_a(stack);
	long long		i;
	t_stack			*tmp;
	t_stack			*tmp2;

	tmp = stack->a;
	i = 0;
	if (min > nbr)
		while (partition_utils(stack->a, i)->data != min)
			i++;
	else
	{
		tmp2 = partition_utils(stack->a, stack->size_a - 1);
		while (tmp->data < nbr || nbr < tmp2->data)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
			i++;
			if (!tmp2->next)
				tmp2 = stack->a;
		}
	}
	return (i);
}

long long	cost_rra(t_frst *stack, long long nbr)
{
	long long	min;
	long long	ptr1;
	long long	ptr2;

	ptr1 = stack->size_a - 1;
	min = min_a(stack);
	if (min > nbr)
	{
		while (partition_utils(stack->a, ptr1)->data != min)
			ptr1--;
		ptr1--;
	}
	else
	{
		ptr2 = 0;
		while (partition_utils(stack->a, ptr2)->data < nbr
			|| nbr < partition_utils(stack->a, ptr1)->data)
		{
			ptr1--;
			ptr2--;
			if (ptr2 == -1)
				ptr2 = stack->size_a - 1;
		}
	}
	return (stack->size_a - 1 - ptr1);
}

long long	cost_rb(t_frst *stack, long long nbr)
{
	t_stack		*tmp;
	long long	i;

	tmp = stack->b;
	i = 0;
	while (tmp->data != nbr)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

long long	cost_rrb(t_frst *stack, long long nbr)
{
	long long	ptr;

	ptr = stack->size_b - 1;
	while (partition_utils(stack->b, ptr)->data != nbr)
		ptr--;
	return (stack->size_b - ptr);
}
