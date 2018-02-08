/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:05:25 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/08 16:45:35 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define ZR map->zr
#define ZI map->zi
#define TMP map->tmp
#define Y stock->y2
#define X stock->x2
#define TAB stock->tabint

static int	ft_test(t_stock *stock, t_map *map)
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
		if ((ZR * ZR - ZI * ZI) > 4.0)
			return (n);
		n++;
	}
	return (n);
}

void		julia(t_stock *stock)
{
	int		n;
	double	pos;
	t_map	map;

	init_stock_map(stock, &map);
	stock->juli = 1;
	Y = -1;
	while (++Y < stock->height)
	{
		TAB[Y] = (int *)malloc(sizeof(int) * WIN_W);
		X = -1;
		while (++X < stock->width)
		{
			map.zr = ft_map(stock, -2, 2, X);
			map.zi = ft_map(stock, -2, 2, Y);
			map.ca = 0.285;
			map.cb = 0.01;
			n = ft_test(stock, &map);
			TAB[Y][X] = n;
			ft_draw(stock, 0, n);
		}
	}
	ft_end(stock);
}
