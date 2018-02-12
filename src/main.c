/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:06:41 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/12 14:52:03 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_create_img(t_stock *stock)
{
	stock->mlx = mlx_init();
	stock->window = mlx_new_window(stock->mlx, WIN_W, WIN_H, "Kevin");
	stock->img = mlx_new_image(stock->mlx, WIN_W, WIN_H);
	stock->move = 'N';
}

int		ft_input(t_stock *stock, char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		mandelbrot(stock);
	if (ft_strcmp(str, "Julia") == 0)
		julia(stock, 0.285, 0.01, 0);
	if (ft_strcmp(str, "Burningship") == 0)
		burningship(stock);
	if (ft_strcmp(str, "Slip") == 0)
	{
		ft_create_img(stock);
		return (4);
	}
	if (ft_strcmp(str, "Tricorne") == 0)
		;
	return (-1);
}

int		main(int ac, char **av)
{
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
	if (ft_input(&stock, av[1]) == -1)
	{
		ft_putendl("This fractol doesn't exist");
		return (0);
	}
	return (0);
}
