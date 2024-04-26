/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:52:41 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/26 14:22:27 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_argsec(char **av)
{
	if (ft_space(av))
		exit(write(2, "Error\n", 6));
}

void	ft_lstfree(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!*a)
		return ;
	head = *a;
	while ((*a)->next != head)
		*a = (*a)->next;
	tmp = (*a)->next;
	(*a)->next = NULL;
	*a = tmp;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

int	is_sorted(t_frst stack)
{
	t_stack	*tmp;
	t_stack	*head;

	tmp = stack.a;
	head = stack.a;
	while (tmp->next && tmp->next != head)
	{	
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	error_free(t_frst *stack)
{
	int	i;

	i = 0;
	ft_lstfree(&stack->a);
	if (stack->size_b > 0)
		ft_lstfree(&stack->b);
	free(stack->a);
	free(stack->b);
	free(stack->jstr);
	if (stack->spl)
	{
		while (stack->spl[i])
			free(stack->spl[i++]);
	}
	free(stack->spl);
	error();
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
