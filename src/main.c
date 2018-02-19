/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:06:41 by mabessir          #+#    #+#             */
/*   Updated: 2018/02/19 11:42:07 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_create_img(t_stock *stock)
{
	stock->mlx = mlx_init();
	stock->window = mlx_new_window(stock->mlx, WIN_W, WIN_H, "Kevin");
	stock->img = mlx_new_image(stock->mlx, WIN_W, WIN_H);
	stock->move = 'N';
	stock->zoom = 1;
	stock->pressure = 1;
	stock->borne1 = -2;
	stock->borne2 = 2;
}

void	ft_input2(t_stock *stock, int i)
{
	if (i == 1)
	{
		ft_create_img(stock);
		slip(stock);
	}
	if (i == 2)
	{
		ft_create_img(stock);
		frog(stock);
	}
}

int		ft_input(t_stock *stock, char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
	{
		ft_create_img(stock);
		mandelbrot(stock);
	}
	if (ft_strcmp(str, "Julia") == 0)
	{
		ft_create_img(stock);
		julia(stock, 0.285, 0.01, 0);
	}
	if (ft_strcmp(str, "Burningship") == 0)
	{
		ft_create_img(stock);
		burningship(stock);
	}
	if (ft_strcmp(str, "Tricorne") == 0)
		ft_input2(stock, 1);
	if (ft_strcmp(str, "Frog") == 0)
		ft_input2(stock, 2);
	return (-1);
}

int		main(int ac, char **av)
{
	t_stock	stock;

	if (ac != 2)
	{
		ft_putendl("usage : ./fractol fractales");
		return (0);
	}
	if (ft_strcmp(av[1], "fractales") == 0)
	{
		ft_putendl("Mandelbrot | Julia | Burningship | Frog | Tricorne");
		return (0);
	}
	if (ft_input(&stock, av[1]) == -1)
	{
		ft_putendl("This fractol doesn't exist");
		return (0);
	}
	return (0);
}
