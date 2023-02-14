/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors_bonus.c                                :+:      :+:    :+:   */
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
	mlx_destroy_window(vars->mlx, vars->win2);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	esc_window2(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win2);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	doingsquare_fract1(t_vars vars)
{
	int	x;
	int	y;

	x = 1;
	while (x < 140)
	{
		y = 310;
		while (y < 350)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 5, 320, 0x00000000, "For Mandelbrot");
	mlx_string_put(vars.mlx, vars.win2, 5, 330, 0x00000000, "or");
	mlx_string_put(vars.mlx, vars.win2, 5, 340, 0x00000000, \
	"Press 'm' button.");
	doingsquare_fract3(vars);
	doingsquare_fract2(vars);
}

void	doingsquare_fract3(t_vars vars)
{
	int	x;
	int	y;

	x = 150;
	while (x < 298)
	{
		y = 310;
		while (y < 350)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 155, 320, 0x00000000, "For Julia");
	mlx_string_put(vars.mlx, vars.win2, 155, 330, 0x00000000, "or");
	mlx_string_put(vars.mlx, vars.win2, 155, 340, 0x00000000, \
	"Press 'j' button.");
}

void	writing_to2window(t_vars vars)
{
	mlx_clear_window(vars.mlx, vars.win2);
	doingfirstsquare(vars);
	doingsecondsquare(vars);
	doingthirdsquare(vars);
	doingfourthsquare(vars);
	mlx_string_put(vars.mlx, vars.win2, 1, 30, 0xFFFFFFFF, \
	"You can choose one of these colors:");
	mlx_string_put(vars.mlx, vars.win2, 1, 190, 0xFFFFFFFF, "Other Options:");
	writeoptions(vars);
	mlx_string_put(vars.mlx, vars.win2, 1, 205, 0xFFFFFFFF, \
	"1)You can zoom in and out with the mousewheel");
	mlx_string_put(vars.mlx, vars.win2, 1, 225, 0xFFFFFFFF, \
	"2)You can move the image with the arrows.");
	mlx_string_put(vars.mlx, vars.win2, 1, 245, 0xFFFFFFFF, \
	"3)Exit the window with ESC and the x on the window.");
	mlx_string_put(vars.mlx, vars.win2, 1, 300, 0xFFFFFFFF, \
	"4)To switch between fractals press here:");
	doingsquare_fract1(vars);
}
