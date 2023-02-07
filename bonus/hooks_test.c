/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:00:32 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/06 22:00:36 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

void	do_zoom(t_vars *vars, int x, int y, double zoom)
{
	double	w;
	double	h;
	double	nw;
	double	nh;


	w = (vars->mandb.max_x - vars->mandb.min_x) * (vars->aux.zoom);
	h = (vars->mandb.max_y - vars->mandb.min_y) * (vars->aux.zoom);
	nw = (vars->mandb.max_x - vars->mandb.min_x) * (vars->aux.zoom * zoom);
	nh = (vars->mandb.max_y - vars->mandb.min_y) * (vars->aux.zoom * zoom);
	vars->mandb.offx -= ((double)x / vars->imgw) * (nw - w);
	vars->mandb.offy -= ((double)y / vars->imgh) * (nh - h);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	static double	zoom;

	if (zoom == 0)
		zoom = 1;
	if (mousecode == 1)
	{
		zoom /= 0.9;
		do_zoom(vars, x, y, zoom);
		printf("offx: %f\n", vars->mandb.offx);
		printf("offy: %f\n", vars->mandb.offy);
		change_mandelbrot(vars);
			if (vars->add >= 1)
				mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_mandelbrot(vars->mandb, vars, vars->aux.new_img);
		vars->add++;
	}
	return (0);
}
