/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:06:41 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/31 14:38:23 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_create_img(t_stock *stock)
{
	stock->mlx = mlx_init();
	stock->window = mlx_new_window(stock->mlx, WIN_W, WIN_H, "Kevin");
	stock->img = mlx_new_image(stock->mlx, WIN_W, WIN_H); 
}

int		ft_input(char *str)
{
	if (ft_strcmp(str,"Mandelbrot") == 0)
		return (1);
	if (ft_strcmp(str, "Julia") == 0)
		return (2);
	if (ft_strcmp(str, "") == 0)
		return (3);
	return (-1);
}		

int		main(int ac, char **av)
{
	int		i;
	t_stock	stock;
	t_map	map;

	if (ac != 2)
	{
		ft_putendl("usage : ./fractol Mandelbrot | Julia | Other");
		return (0);
	}
	if (ft_strcmp(av[1], "name") == 0)
	{
		ft_putendl("Mandelbrot | Julia | Other");
		return (0);
	}
	if ((i = ft_input(av[1])) == -1)
		ft_putendl("This fractol doesn't exist");
	ft_create_img(&stock);
	if (i == 1)
		mandelbrot(&stock, &map);
	return (0);
}