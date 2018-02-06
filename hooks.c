/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:06:17 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/05 16:02:29 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	keykey(int i, t_stock *stock)
{
	int y;

	y = 0;
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
}

int		key_hook(int keycode, t_stock *stock)
{
	if (keycode == 53)
	{
		mlx_destroy_image(stock->mlx, stock->img);
		mlx_destroy_window(stock->mlx, stock->window);
		ft_exit_finish("Exit Success", 2, stock);
	}
	if (keycode == 83)
		keykey(83, stock);
	if (keycode == 84)
		keykey(84, stock);
	if (keycode == 85)
		keykey(85, stock);
	if (keycode == 86)
		keykey(86, stock);
	return (0);
}