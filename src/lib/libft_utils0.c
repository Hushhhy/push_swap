/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:11:54 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/26 14:10:26 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_putstr_fd(char *s, int fd);
size_t		numlen(long nbr);
char		*ft_itoa(int n);
char		*pre_conv(int len);
long long	ft_atoll(const char *str);

long long	ft_atoll(const char *str)
{
	long long	i;
	long long	min;
	long long	result;

	i = 0;
	min = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - 48;
	}
	return (result * min);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = numlen(nbr);
	result = pre_conv(len);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = 0;
	return (result);
}

char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

size_t	numlen(long nbr)
{
	int	num;

	num = 0;
	if (nbr < 0)
	{
		num++;
		nbr = -nbr;
	}
	if (nbr == 0)
		num++;
	while (nbr != 0)
	{
		nbr /= 10;
		num++;
	}
	return (num);
}
