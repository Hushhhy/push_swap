/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:33:27 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/24 14:43:57 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lastnode(t_stack *head);
void	ft_lst(t_stack **head, int nb);

void	null_init(t_frst *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->jstr = NULL;
	stack->spl = NULL;
}

void	ft_lst(t_stack **head, int nb)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		exit(0);
	a->next = a;
	if (!*head)
		*head = a;
	ft_lastnode(*head)->next = a;
	a->data = nb;
	a->next = *head;
}

t_stack	*ft_lastnode(t_stack *head)
{
	t_stack	*a;

	a = head;
	while (a->next != head)
		a = a->next;
	return (a);
}

int	ft_lstsize(t_stack *stack)
{
	int		i;
	t_stack	*tmp;
	t_stack	*head;

	i = 0;
	tmp = stack;
	head = stack;
	i++;
	tmp = tmp->next;
	while (tmp != head)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
