/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:06:17 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/19 14:02:43 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define CA stock->ca
#define CB stock->cb

static const t_toto g_myfunc[] =
{
	{53, keykey2},
	{123, keykey2},
	{124, keykey2},
	{125, keykey2},
	{126, keykey2},
	{83, keykey},
	{84, keykey},
	{85, keykey},
	{86, keykey},
	{15, keykey2},
	{49, keykey},
};

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
	screenhelp(stock);
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
	if (stock->identifier == 6)
		fish(stock);
}

int		key_hook(int keycode, t_stock *stock)
{
	int i;

	i = -1;
	while (g_myfunc[++i].i)
	{
		if (g_myfunc[i].i == keycode)
		{
			g_myfunc[i].f(keycode, stock);
		}
	}
	if (keycode == 49 && stock->juli == 1)
	{
		stock->move = stock->move == 'Y' ? 'N' : 'Y';
		stock->pressure = 0;
	}
	if (keycode == 18)
		keykey(83, stock);
	if (keycode == 19)
		keykey(84, stock);
	if (keycode == 20)
		keykey(85, stock);
	if (keycode == 21)
		keykey(86, stock);
	keykey3(keycode, stock);
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
	if (key == 4)
		stock->zoom *= 1.1;
	if (key == 5)
	{
		stock->zoom *= 0.9;
		if (stock->zoom == 0)
			stock->zoom += 0.1;
		mlx_clear_window(stock->mlx, stock->window);
	}
	mlx_clear_window(stock->mlx, stock->window);
	ft_recalc(stock);
	return (0);
}
