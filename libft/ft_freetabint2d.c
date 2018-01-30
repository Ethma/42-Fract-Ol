/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetabint2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:04:55 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/17 16:06:05 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetabint2d(int **tab, int size)
{
	int i;

	i = 0;
	while (size)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
		size--;
	}
	free(tab);
}
