/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:48:11 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/06 15:10:49 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define zr map.zr
#define zi map.zi
#define tmp map.tmp
#define y stock->y2
#define x stock->x2
#define tabint stock->tabint

void		ft_end(t_stock *stock)
{
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img, 0, 0);
	mlx_key_hook(stock->window, key_hook, stock);
//	mlx_mouse_hook(stock->window, mouse_hook, stock);
	//mlx_hook(stock->window, 6, 6L >> 1L, mouse, stock);
	mlx_loop(stock->mlx);
}

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