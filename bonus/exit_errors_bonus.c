/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:51:39 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 21:16:37 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

int	esc_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->add != 0)
		mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	ft_comments(int a)
{
	if (a == 0)
		ft_printf("these are the possible fractals:\n1) Mandelbrot\n2) Julia\n\n");
	ft_printf("Options for executing the program:\n\n");
	ft_printf("\tIf you want to change window size execute the program:");
	ft_printf("./fractol FRACTAL iwSIZE ihSIZE\n");
	if (a == 1 || a == 0)
	{
		ft_printf("\n\tFor Julia set you can also change the");
		ft_printf("initial parameters this way:\n");
		ft_printf("\t  This can be done executing the program");
		ft_printf("this way: ./fractol FRACTAL cxDOUBLE cyDOUBLE\n");
		ft_printf("\t  NOTE: you can still change the window");
		ft_printf("size with iw and ih\n");
	}
	ft_printf("NOTE: you can put the arguments (except fractal) in what");
	ft_printf("order you would like, just make sure you have the prefixes");
	ft_printf("rigth (i.e. ih, iw).\n");
	ft_printf("LIMITS: iw > 0 and iw < 1080, ih > 0 and ih < 1980\n");
	if (a == 1 || a == 2)
	{
		ft_printf("\nOptions while executing:\n");
		ft_printf("\tMouse wheel zoomin and zoomout in the center\n");
		ft_printf("\tESC closes window\n");
	}
}
