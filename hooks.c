/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:06:17 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/02 16:01:41 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	keykey(int i, t_stock *stock)
{
	if (i == 124)
	{
		stock->width += 10;
		mlx_clear_window(stock->mlx, stock->window);
		mlx_destroy_image(stock->mlx, stock->img);
		mandelbrot(stock);
		mlx_put_image_to_window(stock->mlx, stock->window,
		stock->img, stock->x, stock->y);
	}
	if (i == 125)
	{
		stock->height += 10;
		mlx_clear_window(stock->mlx, stock->window);
		mlx_put_image_to_window(stock->mlx, stock->window,
		stock->img, stock->x, stock->y);
	}
}

int		key_hook(int keycode, t_stock *stock)
{
	if (keycode == 53)
	{
		mlx_destroy_image(stock->mlx, stock->img);
		mlx_destroy_window(stock->mlx, stock->window);
		ft_exit_finish("Exit Success", 2, stock);
	}
	if (keycode == 123)
	{
		stock->x -= 10;
		mlx_clear_window(stock->mlx, stock->window);
		mlx_put_image_to_window(stock->mlx, stock->window,
		stock->img, stock->x, stock->y);
	}
	if (keycode == 126)
	{
		stock->y -= 10;
		mlx_clear_window(stock->mlx, stock->window);
		mlx_put_image_to_window(stock->mlx,
		stock->window, stock->img, stock->x, stock->y);
	}
	if (keycode == 124)
		keykey(124, stock);
	if (keycode == 125)
		keykey(125, stock);
	return (0);
}
