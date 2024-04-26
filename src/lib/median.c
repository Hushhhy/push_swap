/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:42:08 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/26 13:31:24 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stackcp(t_stack *stack)
{
	t_stack	*cp;
	t_stack	*tmp;

	cp = ft_lstnew(stack->data);
	tmp = stack->next;
	while (tmp != stack)
	{
		ft_lstadd_back(&cp, ft_lstnew(tmp->data));
		tmp = tmp->next;
	}
	return (cp);
}

long long   median_finder(t_frst *stack)
{
    t_stack     *cp;
    t_stack     *tmp;
    long long   median_calc;
    long long   median_in_stack;
    long long   rtn;

	median_in_stack = 0;
	cp = stackcp(stack->a);
	tmp = cp;
	quicksort(tmp, 0, stack->size_a - 1);
	median_calc = (stack->size_a / 2);
	while (median_in_stack < median_calc)
	{
		tmp = tmp->next;
		median_in_stack++;
	}
	rtn = tmp->data;
	ft_lstfree(&cp);
	free(cp);
	return (rtn);tmp = tmp->next;
}

void	sort_a(t_frst *stack)
{
	if (stack->size_a == 1)
		return ;
	else if (stack->size_a == 2 && stack->a->data < stack->a->next->data)
		return ;
	else if (stack->size_a == 2 && stack->a->data > stack->a->next->data)
		ft_ra(stack, 1);
	else
	{
		if (stack->a->data > stack->a->next->data
			&& stack->a->data > stack->a->next->next->data)
			ft_ra(stack, 1);
		else if (stack->a->next->data > stack->a->data
			&& stack->a->next->data > stack->a->next->next->data)
			ft_rra(stack, 1);
		if (stack->a->data > stack->a->next->data)
			ft_sa(stack, 1);
	}
}

void    median(t_frst *stack)
{
    long long   median;
    long long   i;

    median = 0;
    while (stack->size_a > 3)
    {
        median = median_finder(stack);
        i = 0;
        while (i < stack->size_a)
        {
            if (stack->a->data < median)
                ft_pb(stack, 1);
            else
            {
                i++;
                ft_ra(stack, 1);
            }
        }
    }
    sort_a(stack);
}
