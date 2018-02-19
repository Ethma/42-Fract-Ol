/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:48:11 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/19 13:41:30 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define TAB stock->tabint

void		ft_end(t_stock *stock)
{
	mlx_put_image_to_window(stock->mlx, stock->window, stock->img, 0, 0);
	if (stock->juli == 1)
		mlx_hook(stock->window, 6, 6L >> 1L, mouse, stock);
	mlx_key_hook(stock->window, key_hook, stock);
	mlx_string_put(stock->mlx, stock->window, 0, 0,
	0xFFFFFF, "Change color :NUM PAD 1 TO 4");
	mlx_string_put(stock->mlx, stock->window, 0, 40,
	0xFFFFFF, "R for RESET");
	if (stock->juli == 1)
		mlx_string_put(stock->mlx, stock->window, 0, 20,
		0xFFFFFF, "Press Space to activate/desactivate Julia");
	mlx_mouse_hook(stock->window, mouse_hook, stock);
	mlx_loop(stock->mlx);
}

void		init_stock_map(t_stock *stock, t_map *map)
{
	stock->start_x = 0.0;
	stock->start_y = 0.0;
	map->yy = 0;
	map->xx = 0;
	stock->yyy = 2;
	stock->yy = -2;
	stock->xx = -2;
	stock->xxx = 2;
	stock->height = WIN_H;
	stock->width = WIN_W;
	stock->juli = 0;
	TAB = (int **)malloc(sizeof(int *) * (WIN_H));
	stock->ra = 1;
}

double		ft_map(double new_min, double new_max, double value)
{
	double	new;

	new = (value - 0) / (WIN_H - 0);
	new = ((new_max - new_min) * new) + new_min;
	return (new);
}
