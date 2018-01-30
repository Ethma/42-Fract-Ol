/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:11:22 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/30 16:00:20 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# define WIN_H 600
# define WIN_W 600
int					ft_input(char *str);
void		mandelbrot(t_stock *stock, t_map *map);

typedef struct 		s_stock
{
			void	*window;
			void	*mlx;
			void	*img;
			int		i;
}					t_stock;

typedef struct		s_map
{
			double	x;
			double	y;
			double	xx;
			double	yy;
}					t_map;
#endif