/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:14:37 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/19 13:56:31 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	screenhelp(t_stock *stock)
{
	mlx_put_image_to_window(stock->mlx, stock->window,
	stock->img, 0, 0);
	mlx_string_put(stock->mlx, stock->window, 0, 0,
	0xFFFFFF, "Change color :NUM PAD 1 TO 4");
	mlx_string_put(stock->mlx, stock->window, 0, 40,
	0xFFFFFF, "R for RESET");
	mlx_string_put(stock->mlx, stock->window, 0, 60,
	0xFFFFFF, "+ / - to change fractale");
	if (stock->juli == 1)
	{
		mlx_string_put(stock->mlx, stock->window, 0, 20,
		0xFFFFFF, "Press Space to activate/desactivate Julia");
	}
}

void	keykey2(int i, t_stock *stock)
{
	if (i == 124)
		stock->x += 10;
	if (i == 125)
		stock->y += 10;
	if (i == 123)
		stock->x -= 10;
	if (i == 126)
		stock->y -= 10;
	if (i == 53)
	{
		mlx_destroy_image(stock->mlx, stock->img);
		mlx_destroy_window(stock->mlx, stock->window);
		ft_freetabint2d(stock->tabint, WIN_H);
		ft_exit_finish("Exit Success", 2);
	}
	if (i == 15)
	{
		stock->zoom = 1;
		stock->borne1 = -2;
		stock->borne2 = 2;
		ft_recalc(stock);
	}
	mlx_clear_window(stock->mlx, stock->window);
	mlx_put_image_to_window(stock->mlx, stock->window,
	stock->img, stock->x, stock->y);
}

void	keykey3(int i, t_stock *stock)
{
	if (i == 78 || i == 27)
	{
		stock->identifier--;
		if (stock->identifier == 0)
			stock->identifier = 6;
		ft_recalc(stock);
	}
	if (i == 69 || i == 24)
	{
		stock->identifier++;
		if (stock->identifier == 7)
			stock->identifier = 1;
		stock->move = 'N';
		ft_recalc(stock);
	}
}
