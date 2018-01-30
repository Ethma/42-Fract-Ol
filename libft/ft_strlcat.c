/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:34:59 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/14 11:08:08 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	if (n == 0)
		return (ft_strlen(src));
	i = 0;
	while (dest[i] && i < n)
		i++;
	j = i;
	while (src[i - j] && i < n - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (i < n)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
