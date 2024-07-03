/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:10:42 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/03 11:29:45 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_toolong(char **split);
void	ft_limit(char **split, char *str);
char	**ft_argvsplit(int ac, char **av);

char	**ft_argvsplit(int ac, char **av)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**split;

	i = 1;
	ft_error(av);
	str = ft_strjoin("", av[1]);
	if (!str)
		return (NULL);
	while (++i < ac)
	{
		tmp = str;
		str = ft_strjoin(str, av[i]);
		free(tmp);
		if (!str)
			return (NULL);
	}
	split = ft_split(str, ' ');
	free(str);
	ft_toolong(split);
	return (split);
}

void	ft_toolong(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		ft_limit(split, split[i]);
		j = i + 1;
		while (split[j] && ft_atoll(split[i]) != ft_atoll(split[j]))
			j++;
		if (split[j] != 0 && (ft_atoll(split[i]) == ft_atoll(split[j])))
		{
			free(split);
			exit(write(2, "Error\n", 6));
		}
		i++;
	}
}

void	ft_limit(char **split, char *str)
{
	int		nb;
	char	*itoa;
	int		i;

	i = 0;
	nb = ft_atoll(str);
	itoa = ft_itoa(nb);
	if (ft_atoll(itoa) > 2147483647 || ft_atoll(itoa) < -2147483648)
	{
		free(str);
		ft_free(split);
		exit(write(2, "Error\n", 6));
	}
	while (str[i] == '+' || (str[i] == '0' && str[i + 1] != '\0'))
		i++;
	if (ft_strcmp(str + i, itoa) != 0)
	{
		free(itoa);
		ft_free(split);
		exit(write(2, "Error\n", 6));
	}
	free(itoa);
}
