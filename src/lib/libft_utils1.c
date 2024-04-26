/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:57:50 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/26 14:14:34 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(long long nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->data = nbr;
	new->next = 0;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*head;

	head = lst;
	while (lst && lst->next != head)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*addback;

	addback = ft_lstlast(*lst);
	addback->next = new;
	new->next = *lst;
}

void	ft_swap(t_stack *a, t_stack *b)
{
	long long	c;

	c = a->data;
	a->data = b->data;
	b->data = c;
}
