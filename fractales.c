/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:48:11 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/31 15:37:50 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define zr map->zr
#define zi map->zi
#define tmp map->tmp

void		init_stock_map(t_stock *stock, t_map *map)
{
	stock->START_X = 0;
	stock->START_Y = 0.0;
	map->y = 0;
	map->x = 0;
}

void		ft_map_x(t_map *map, t_stock *stock, double x)
{
	map->x = (x - 0) / (WIN_W - 0);
	map->x = (2 + 2) * map->x - 2;
}

void		ft_map_y(t_map *map, t_stock *stock, double y)
{
	map->y = (y - 0) / (WIN_H - 0);
	map->y = ((2 + 2) * map->y) - 2;
}
void		mandelbrot(t_stock *stock, t_map *map)
{
	int		n;
	double	pos;
	double	y;
	double	x;


	init_stock_map(stock, map);
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		ft_map_y(map, stock, y);
		map->cb = map->y;
		while (++x < WIN_W)
		{
			ft_map_x(map, stock, x);
			map->ca = map->x;
			zr = 0;
			zi = 0;
			n = 0;
			while (n < 800)
			{
				tmp = zr;
				zr = zr * zr - zi * zi + map->ca;
				zi = 2 * tmp * zi + map->cb;
				if ((zr * zr - zi * zi) > 4.0)
					break;
				n++;
			}
		if (n == 800)
			mlx_pixel_put_to_image(stock->img, x, y, 0);
		else
			mlx_pixel_put_to_image(stock->img, x, y, 0xFFFFFF);
		}
	}
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img, 0, 0);
	mlx_key_hook(stock->window, key_hook, stock);
//	mlx_mouse_hook(stock->window, mouse_hook, stock);
	//mlx_hook(stock->window, 6, 6L >> 1L, mouse, stock);
	mlx_loop(stock->mlx);
}