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

void	writing_to2window(t_vars vars)
{
	mlx_clear_window(vars.mlx, vars.win2);
	doingfirstsquare(vars);
	doingsecondsquare(vars);
	doingthirdsquare(vars);
	doingfourthsquare(vars);
	mlx_string_put(vars.mlx, vars.win2, 1, 30, 0xFFFFFFFF, \
	"You can choose one of these colors:");
	mlx_string_put(vars.mlx, vars.win2, 1, 180, 0xFFFFFFFF, "Other Options:");
	if (vars.isfractal == 'j')
	{
		mlx_string_put(vars.mlx, vars.win2, 1, 10, 0xFFFFFFFF, \
		"Here we have the Julia set!");
		mlx_string_put(vars.mlx, vars.win2, 1, 215, 0xFFFFFFFF, \
		"You can use the left mouse button to change");
		mlx_string_put(vars.mlx, vars.win2, 1, 225, 0xFFFFFFFF, \
		"the Julia inputs.");
	}
	mlx_string_put(vars.mlx, vars.win2, 1, 195, 0xFFFFFFFF, \
	"You can zoom in and out with the mousewheel");
	mlx_string_put(vars.mlx, vars.win2, 1, 205, 0xFFFFFFFF, \
	"You can move the image with the arrows.");
}
