/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:05:25 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/19 12:13:00 by mabessir         ###   ########.fr       */
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
#define B1 stock->borne1
#define B2 stock->borne2

static int	ft_calc(t_map *map)
{
	int n;
	int maxiter;

	n = 0;
	maxiter = 100;
	while (n < maxiter)
	{
		TMP = ZR;
		ZR = ZR * ZR - ZI * ZI + map->ca;
		ZI = 2 * TMP * ZI + map->cb;
		if ((ZR * ZR - ZI * ZI) >= 4.0)
			return (n);
		n++;
	}
	return (n);
}

void		julia(t_stock *stock, double x, double y, int z)
{
	int		n;
	t_map	map;

	if (stock->ra == 0)
		init_stock_map(stock, &map);
	stock->juli = 1;
	stock->identifier = 2;
	Y = -1;
	while (++Y < stock->height)
	{
		TAB[Y] = (int *)malloc(sizeof(int) * WIN_W);
		X = -1;
		while (++X < stock->width)
		{
			map.zr = ft_map(B1, B2, X) / ZOOM;
			map.zi = ft_map(B1, B2, Y) / ZOOM;
			map.ca = x;
			map.cb = y;
			n = ft_calc(&map);
			TAB[Y][X] = n;
			ft_draw(stock, z, n);
		}
	}
	ft_end(stock);
}
