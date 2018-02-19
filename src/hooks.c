/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:06:17 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/19 11:30:04 by mabessir         ###   ########.fr       */
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
	if (stock->juli == 1)
		mlx_string_put(stock->mlx, stock->window, 0, 20,
		0xFFFFFF, "Press Space to activate/desactivate Julia");
	if (i == 49)
	{
		stock->move = stock->move == 'Y' ? 'N' : 'Y';
		stock->pressure = 0;
	}
}

void	ft_recalc(t_stock *stock)
{
	if (stock->identifier == 1)
		mandelbrot(stock);
	else if (stock->identifier == 2 && stock->pressure == 1)
		julia(stock, 0.285, 0.01, stock->color);
	else if (stock->identifier == 2)
		julia(stock, CA, CB, stock->color);
	else if (stock->identifier == 3)
		burningship(stock);
	else if (stock->identifier == 4)
		frog(stock);
	if (stock->identifier == 5)
		slip(stock);
}

int		key_hook(int keycode, t_stock *stock)
{
	if (keycode == 53)
		keykey2(53, stock);
	if (keycode == 123)
		keykey2(123, stock);
	if (keycode == 124)
		keykey2(124, stock);
	if (keycode == 125)
		keykey2(125, stock);
	if (keycode == 126)
		keykey2(126, stock);
	if (keycode == 83 || keycode == 18)
		keykey(83, stock);
	if (keycode == 84 || keycode == 19)
		keykey(84, stock);
	if (keycode == 85 || keycode == 20)
		keykey(85, stock);
	if (keycode == 86 || keycode == 21)
		keykey(86, stock);
	if (keycode == 49)
		keykey(49, stock);
	if (keycode == 15)
		keykey2(15, stock);
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
	if (key == 4)
		stock->zoom *= 1.1;
	if (key == 5)
	{
		stock->zoom *= 0.9;
		if (stock->zoom == 0)
			stock->zoom += 0.1;
		mlx_clear_window(stock->mlx, stock->window);
	}
	if (key == 1)
	{
		stock->borne1 = ft_map(-2, 2, x);
		stock->borne2 = ft_map(-2, 2, y);
	}
	if (key == 2)
		stock->zoom -= 0.1;
	mlx_clear_window(stock->mlx, stock->window);
	ft_recalc(stock);
	return (0);
}
