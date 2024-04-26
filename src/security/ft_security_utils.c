/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:55:40 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/17 12:58:19 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_onlyspace(char *av);

bool	ft_space(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_onlyspace(av[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	ft_onlyspace(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	ft_error(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			exit(write(2, "Error\n", 6));
		i++;
	}
}
