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
	//free(vars->mlx);
	exit(0);
}

int	esc_window2(t_vars *vars)
{
	esc_window(vars);
	mlx_destroy_window(vars->mlx, vars->win2);
	free(vars->mlx);
	exit(0);
}

void	writing_to2window(t_vars vars)
{
	int	x;
	int	y;

	x = 1;
	y = 13;
	mlx_clear_window(vars.mlx, vars.win2);
	while (x < 140)
	{
		y = 13;
		while (y < 71)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
	x = 150;
	while (x < 298)
	{
		y = 11;
		while (y < 71)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
	x = 1;
	while (x < 140)
	{
		y = 80;
		while (y < 140)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
	x = 150;
	while (x < 298)
	{
		y = 80;
		while (y < 140)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
	if (vars.isfractal == 'j')
	{
		mlx_string_put(vars.mlx, vars.win2, 1, 10, 0xFFFFFFFF, "Here we have the Julia set!");
	}
}
