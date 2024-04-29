/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:24:54 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/29 17:20:32 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*partition_utils(t_stack *stack, long long lrp)
{
	t_stack		*tmp;
	long long	i;

	i = 0;
	tmp = stack;
	while (i < lrp)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

long long	partition(t_stack *stack, long long lp, long long rp)
{
	t_stack		*tmp;
	long long	pivot;
	long long	i;
	long long	j;

	pivot = partition_utils(stack, rp)->data;
	tmp = partition_utils(stack, lp);
	stack = tmp;
	i = lp;
	j = lp;
	while (j < rp)
	{
		if (tmp->data <= pivot)
		{
			ft_swap(stack, tmp);
			stack = stack->next;
			i++;
		}
		tmp = tmp->next;
		j++;
	}
	ft_swap(stack, tmp);
	return (i);
}

void	quicksort(t_stack *stack, long long lp, long long rp)
{
	long long	pivot;

	if (lp < rp)
	{
		pivot = partition(stack, lp, rp);
		quicksort(stack, lp, pivot - 1);
		quicksort(stack, pivot + 1, rp);
	}
}
