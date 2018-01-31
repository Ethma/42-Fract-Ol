/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:03:53 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/31 13:16:06 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			mlx_pixel_put_to_image(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		i;

	if (x >= WIN_W || y >= WIN_H)
		return ;
	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	i = x * (bpp / 8) + y * sizeline;
	data[i] = color % 256;
	color /= 256;
	data[i + 1] = color % 256;
	color /= 256;
	data[i + 2] = color % 256;
	color /= 256;
	data[i + 3] = 0;
	color /= 256;
}