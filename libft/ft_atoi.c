/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:08:31 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/15 15:13:20 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	long long int	res;
	int				neg;

	i = 0;
	res = 0;
	neg = 0;
	if (ft_isascii(str[i]) == 0)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-res);
	return (res);
}
