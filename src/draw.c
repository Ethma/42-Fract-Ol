/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:03:53 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/09 18:26:43 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#define y1 stock->y2
#define x1 stock->x2
#define tabint stock->tabint

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
	if (n == 0)
		*color = (t_color){.a = 0xb2bec3, .b = 0xe84393, .c = 0x636e72,
		.d = 0xff7675, .e = 0xfdcb6e, .f = 0xfd79a8, .g = 0xfab1a0,
		.h = 0xdfe6e9, .i = 0xa29bfe, .j = 0x74b9ff, .k = 0xf1cbff};
	if (n == 1)
		*color = (t_color){.a = 0xFFB990, .b = 0xFFA06A, .c = 0xFF7F32,
		.d = 0xFF6A13, .e = 0xD86018, .f = 0xfd79a8, .g = 0xfab1a0,
		.h = 0xdfe6e9, .i = 0xa29bfe, .j = 0x74b9ff, .k = 0xf1cbff};
	if (n == 2)
		*color = (t_color){.a = 0x545E56, .b = 0x875053, .c = 0x084C61,
		.d = 0x2E86AB, .e = 0xF0A202, .f = 0xBEBBBB, .g = 0x011936,
		.h = 0xCD8B76, .i = 0xFAA916, .j = 0xF7EBEC, .k = 0xf1cbff};
	if (n == 3)
		*color = (t_color){.a = 0xFF9999, .b = 0xFFCC99, .c = 0xFFFF99,
		.d = 0xCCFF99, .e = 0x99FF99, .f = 0x99FFCC, .g = 0x99FFFF,
		.h = 0x99CCFF, .i = 0x999FF, .j = 0xCC99FF, .k = 0xf1cbff};
	return (color[n]); 
}

void	ft_draw(t_stock *stock, int i, int n)
{
	t_color		color;

	ft_color(&color, i);
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
	if (n < 10 && n >= 0)
		mlx_pixel_put_to_image(stock->img, x1, y1, color.a);
}

void	ft_redraw(t_stock *stock, int i)
{
	int	x;
	int	y;

	y = -1;
	y1 = 0;
	while (++y < WIN_H)
	{
		x = -1;
		x1 = 0;
		while (++x < WIN_W)
		{
			ft_draw(stock, i, tabint[y][x]);
			x1++;
		}
		y1++;
	}
}

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