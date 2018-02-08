/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:05:52 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/08 13:58:40 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define zr map.zr
#define zi map.zi
#define tmp map.tmp
#define y stock->y2
#define x stock->x2
#define tabint stock->tabint

void		mandelbrot(t_stock *stock)
{
	int		n;
	double	pos;
	int		maxiter;
	t_map	map;

	maxiter = 100;
	init_stock_map(stock, &map);
	y = -1;
	while (++y < stock->height)
	{
		tabint[y] = (int *)malloc(sizeof(int) * WIN_W);
		x = -1;
		map.cb = ft_map(stock, -2 , 2, y); 
		while (++x < stock->width)
		{
			map.ca = ft_map(stock, -2 , 2, x);
			ft_map(stock, -2, 2, x);
			zr = 0;
			zi = 0;
			n = 0;
			while (n < maxiter)
			{
				tmp = zr;
				zr = zr * zr - zi * zi + map.ca;
				zi = 2 * tmp * zi + map.cb;
				if ((zr * zr - zi * zi) > 4.0)
					break;
				n++;
			}
			tabint[y][x] = n;
			ft_draw(stock, 0, n);
		}
	}
    ft_end(stock);
}