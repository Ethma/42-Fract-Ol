/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:11:22 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/31 15:37:36 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# define WIN_H 1080
# define WIN_W 1080

typedef struct 		s_stock
{
			void	*window;
			void	*mlx;
			void	*img;
			int		i;
			double START_X;
			double START_Y;
			double ZOOM;
}					t_stock;

typedef struct		s_map
{
			double	x;
			double	y;
			double	ca;
			double	cb;
			double	zr;
			double	zi;
			double	tmp;
}					t_map;

int			ft_input(char *str);
int			key_hook(int keycode, t_stock *stock);
int			ft_exit_finish(char *str, int i, t_stock *stock);
void		mandelbrot(t_stock *stock, t_map *map);
void		ft_map_x(t_map *map, t_stock *stock, double x);
void		ft_map_y(t_map *map, t_stock *stock, double y);
void		init_stock_map(t_stock *stock, t_map *map);
void		mlx_pixel_put_to_image(void *img, int x, int y, int color);

#endif