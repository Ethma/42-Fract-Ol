/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:14:37 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/19 11:32:51 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

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
