/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:06:41 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/08 13:57:12 by mabessir         ###   ########.fr       */
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
	if (ft_strcmp(str, "Burningsheep") == 0)
		return (3);
	if (ft_strcmp(str, "Slip") == 0)
		return (4);
	if (ft_strcmp(str, "Tricorne") == 0)
		return (5);
	return (-1);
}		

int		main(int ac, char **av)
{
	int		choice_projection;
	t_stock	stock;

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
	if ((choice_projection = ft_input(av[1])) == -1)
	{
		ft_putendl("This fractol doesn't exist");
		return (0);
	}
	ft_create_img(&stock);
	if (choice_projection == 1)
		mandelbrot(&stock);
	if (choice_projection == 2)
		julia(&stock);
	if (choice_projection == 5)
		tricorne(&stock);
	return (0);
}