/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:03:53 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/02 15:50:59 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define y1 stock->y2
#define x1 stock->x2

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

t_color		ft_color(t_color *color, int n)
{
	if (n > 4)
		n = 0;
	if (n == 0)
		*color = (t_color){.a = 0xb2bec3, .b = 0xe84393, .c = 0x636e72,
		.d = 0xff7675, .e = 0xfdcb6e, .f = 0xfd79a8, .g = 0xfab1a0,
		.h = 0xdfe6e9, .i = 0xa29bfe, .j = 0x74b9ff, .k = 0};
	if (n == 1)
		*color = (t_color){.a = 0xFFB990, .b = 0xFFA06A, .c = 0xFF7F32,
		.d = 0xFF6A13, .e = 0xD86018, .f = 0xfd79a8, .g = 0xfab1a0,
		.h = 0xdfe6e9, .i = 0xa29bfe, .j = 0x74b9ff, .k = 0x9B3259};
	if (n == 2)
		*color = (t_color){.a = 0xb2bec3, .b = 0xe84393, .c = 0x636e72,
		.d = 0xff7675, .e = 0xfdcb6e, .f = 0xfd79a8, .g = 0xfab1a0,
		.h = 0xdfe6e9, .i = 0xa29bfe, .j = 0x74b9ff, .k = 0};
	if (n == 3)
		*color = (t_color){.a = 0xb2bec3, .b = 0xe84393, .c = 0x636e72,
		.d = 0xff7675, .e = 0xfdcb6e, .f = 0xfd79a8, .g = 0xfab1a0,
		.h = 0xdfe6e9, .i = 0xa29bfe, .j = 0x74b9ff, .k = 0};
	return (color[n]); 
}

void	ft_draw(t_stock *stock, int i, int n)
{
	t_color		color;

	ft_color(&color, 1);
	if (n == 100)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.k);
	if (n >= 90 && n <= 99)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.j);
	if (n >= 80 && n <= 89)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.i);
	if (n >= 70 && n <= 79)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.h);
	if (n >= 60 && n <= 69)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.g);
	if (n >= 50 && n <= 59)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.f);
	if (n >= 40 && n <= 49)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.e);
	if (n >= 30 && n <= 39)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.d);
	if (n >= 20 && n <= 29)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.c);
	if (n >= 10 && n <= 19)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.b);
	if (n < 10)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.a);
}