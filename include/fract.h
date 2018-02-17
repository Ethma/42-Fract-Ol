/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mendy <Mendy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:11:22 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/16 11:47:10 by Mendy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include "../minilibx_macos/mlx.h"
# include <math.h>
# define WIN_H 800
# define WIN_W 800

typedef struct	s_stock
{
	void		*window;
	void		*mlx;
	void		*img;
	int			i;
	double		zoom;
	int			zzom;
	double		start_x;
	double		start_y;
	int			x;
	int			y;
	int			height;
	int			width;
	int			x2;
	int			y2;
	int			index;
	int			**tabint;
	int			juli;
	double		ca;
	double		cb;
	int			xx;
	int			xxx;
	int			yy;
	int			yyy;
	char		move;
	int			ra;
	int			identifier;
	int			color;
	double		value;
	int			pressure;
	int			borne1;
	int			borne2;
}				t_stock;

typedef struct	s_map
{
	double		xx;
	double		yy;
	double		ca;
	double		cb;
	double		zr;
	double		zi;
	double		tmp;
}				t_map;

typedef	struct	s_color
{
	int			a;
	int			b;
	int			c;
	int			d;
	int			e;
	int			f;
	int			g;
	int			h;
	int			i;
	int			j;
	int			k;
}				t_color;

int				ft_input(t_stock *stock, char *str);
void			ft_create_img(t_stock *stock);
void			init_stock_map(t_stock *stock, t_map *map);
double			ft_map(double new_min, double new_max, double value);
void			mandelbrot(t_stock *stock);
void			julia(t_stock *stock, double x, double y, int z);
void			frog(t_stock *stock);
void			slip(t_stock *stock);
void			tricorne(t_stock *stock);
void			burningship(t_stock *stock);
void			ft_end(t_stock *stock);
void			mlx_pixel_put_to_image(void *img, int x, int y, int color);
void			ft_draw(t_stock *stock, int i, int n);
t_color			ft_color(t_color *color, int n);
void			ft_coloors(t_stock *stock, t_color color, int n);
void			ft_clean(t_stock *stock);
void			ft_redraw(t_stock *stock, int i);
void			ft_recalc(t_stock *stock);
int				mouse_hook(int key, int x, int y, t_stock *stock);
int				key_hook(int keycode, t_stock *stock);
int				mouse(int x, int y, t_stock *stock);
int				ft_exit_finish(char *str, int i);

#endif
