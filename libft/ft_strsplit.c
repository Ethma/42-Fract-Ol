/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:21:35 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/15 15:19:46 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count(const char *str, char c)
{
	size_t	i;
	size_t	count;
	int		counter;

	i = 0;
	count = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c && counter == 1)
			counter = 0;
		if (str[i] != c && counter == 0)
		{
			counter = 1;
			count++;
		}
		i++;
	}
	return (count);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == NULL || !(tab = (char **)malloc(sizeof(char*) *
	(ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			k = 0;
			while (s[i + k] && (s[i + k] != c))
				k++;
			tab[j++] = ft_strsub(s, i, k);
			i = i + k;
		}
	}
	tab[j] = NULL;
	return (tab);
}
