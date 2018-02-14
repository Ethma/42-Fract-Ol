/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:06:17 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/14 15:14:31 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define CA stock->ca
#define CB stock->cb

void	keykey(int i, t_stock *stock)
{
	if (i == 83)
		ft_redraw(stock, 0);
	if (i == 84)
		ft_redraw(stock, 1);
	if (i == 85)
		ft_redraw(stock, 2);
	if (i == 86)
		ft_redraw(stock, 3);
	mlx_put_image_to_window(stock->mlx, stock->window,
	stock->img, 0, 0);
	mlx_string_put(stock->mlx, stock->window, 0, 0,
	0xFFFFFF, "Change color :NUM PAD 1 TO 4");
	if (stock->juli == 1 && stock->move == 'N')
		mlx_string_put(stock->mlx, stock->window, 0, 20,
		0xFFFFFF, "Press Space to activate Julia");
}

int		key_hook(int keycode, t_stock *stock)
{
	if (keycode == 53)
	{
		mlx_destroy_image(stock->mlx, stock->img);
		mlx_destroy_window(stock->mlx, stock->window);
		ft_exit_finish("Exit Success", 2);
	}
	if (keycode == 83)
		keykey(83, stock);
	if (keycode == 84)
		keykey(84, stock);
	if (keycode == 85)
		keykey(85, stock);
	if (keycode == 86)
		keykey(86, stock);
	if (keycode == 49)
		stock->move = stock->move == 'Y' ? 'N' : 'Y';
	if (stock->juli == 1 && stock->move == 'Y')
		mlx_string_put(stock->mlx, stock->window, 0, 40,
		0xFFFFFF, "Press Space to stop Julia");
	return (0);
}

int		mouse(int x, int y, t_stock *stock)
{
	if (x > 0 & y > 0 && x < WIN_W && y < WIN_H && stock->move == 'Y')
	{
		CA = (double)x / (double)WIN_W * 4 - 2;
		CB = (double)y / (double)WIN_H * 4 - 2;
		mlx_clear_window(stock->mlx, stock->window);
		julia(stock, CA, CB, stock->color);
	}
	return (0);
}

int		mouse_hook(int key, int x, int y, t_stock *stock)
{
	x = 0;
	y = 0;
	if (key == 1)
	{
		stock->zzom = 1;
		stock->xx = ft_map(-2, 2, x);
		stock->yy = ft_map(-2, 2, y);
		mlx_clear_window(stock->mlx, stock->window);
		mandelbrot(stock);
	}
	if (key == 2)
	{
		stock->zzom = 0;
		stock->xx = ft_map(-2, 2, x);
		stock->yy = ft_map(-2, 2, y);
		mlx_clear_window(stock->mlx, stock->window);
		mandelbrot(stock);
	}
	return (0);
}