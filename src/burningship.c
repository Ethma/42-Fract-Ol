/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:11:33 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/19 13:42:14 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define ZR map->zr
#define ZI map->zi
#define TMP map->tmp
#define Y stock->y2
#define X stock->x2
#define TAB stock->tabint
#define ZOOM stock->zoom

static int	ft_calc(t_map *map)
{
	int n;
	int maxiter;

	n = 0;
	maxiter = 100;
	ZR = 0;
	ZI = 0;
	while (n < maxiter)
	{
		TMP = ZR;
		ZR = fabs(ZR * ZR - ZI * ZI + map->ca);
		ZI = fabs(2 * TMP * ZI + map->cb);
		if ((ZR * ZR - ZI * ZI) > 4)
			return (n);
		n++;
	}
	return (n);
}

void		burningship(t_stock *stock)
{
	int		n;
	t_map	map;

	if (stock->ra == 0)
		init_stock_map(stock, &map);
	stock->juli = 0;
	stock->identifier = 3;
	Y = -1;
	while (++Y < stock->height)
	{
		TAB[Y] = (int *)malloc(sizeof(int) * WIN_W);
		X = -1;
		map.cb = ft_map(-2, 2, Y) / ZOOM;
		while (++X < stock->width)
		{
			map.ca = ft_map(-2, 2, X) / ZOOM;
			n = ft_calc(&map);
			TAB[Y][X] = n;
			ft_draw(stock, stock->color, n);
		}
	}
	ft_end(stock);
}
