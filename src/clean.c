/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:55:51 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/15 17:56:19 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_clean(t_stock *stock)
{
	int	x;
	int	y;

	y = -1;
	while (++y < stock->height)
	{
		x = -1;
		while (++x < stock->width)
			mlx_pixel_put_to_image(stock->img, x, y, 0);
	}
}
