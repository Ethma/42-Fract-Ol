/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:48:11 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/05 16:09:01 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define zr map.zr
#define zi map.zi
#define tmp map.tmp
#define y stock->y2
#define x stock->x2
#define tabint stock->tabint

void		ft_end()

void		init_stock_map(t_stock *stock, t_map *map)
{
	stock->START_X = 0;
	stock->START_Y = 0.0;
	map->yy = 0;
	map->xx = 0;
	stock->height = WIN_H;
	stock->width = WIN_W;
	tabint = (int **)malloc(sizeof(int *) * (WIN_H));
}

double		ft_map(t_stock *stock, double new_min, double new_max, double value)
{
	double	new;

	new = (value - 0) / (WIN_H - 0);
	new = ((new_max - new_min) * new) + new_min;
	return (new);
}

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
				zr = 2 * (zr * zr - zi * zi + map.ca);
				zi = -2 * tmp * zi + map.cb;
				if ((zr * zr - zi * zi) > 4.0)
					break;
				n++;
			}
			tabint[y][x] = n;
			ft_draw(stock, 0, n);
		}
	}
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img, 0, 0);
	mlx_key_hook(stock->window, key_hook, stock);
//	mlx_mouse_hook(stock->window, mouse_hook, stock);
	//mlx_hook(stock->window, 6, 6L >> 1L, mouse, stock);
	mlx_loop(stock->mlx);
}

void	julia(t_stock *stock)
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
		while (++x < stock->width)
		{
			zr = ft_map(stock, -2 , 2, x);
			zi = ft_map(stock, -2 , 2, y); 
			map.ca = 0.285;
			map.cb = 0.01;
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
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img, 0, 0);
	mlx_key_hook(stock->window, key_hook, stock);
//	mlx_mouse_hook(stock->window, mouse_hook, stock);
	//mlx_hook(stock->window, 6, 6L >> 1L, mouse, stock);
	mlx_loop(stock->mlx);
}