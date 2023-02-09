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
	double	c_x;
	double	c_y;
	double	newc_x;
	double	newc_y;

	c_x = screentocomplex(vars, x, y, 0);
	c_y = screentocomplex(vars, x, y, 1);
	vars->aux.zoom = zoom;
	newc_x = screentocomplex(vars, x, y, 0);
	newc_y = screentocomplex(vars, x, y, 1);
	vars->fract.offx = (c_x - newc_x);
	vars->fract.offy = (c_y - newc_y);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	static double	zoom;

	if (zoom == 0)
		zoom = 1;
	if (vars->isfractal == 'm' || vars->isfractal == 'b')
	{
		if (mousecode == SCROLL_DOWN)
			zoom *= 0.9;
		else if (mousecode == SCROLL_UP)
			zoom /= 0.9;
		do_zoom(vars, x, y, zoom);
		change_mandelbrot(vars);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		if (vars->isfractal == 'm')
			do_mandelbrot(vars->fract, vars, vars->aux.new_img);
		else
			do_burnship(vars->fract, vars, vars->aux.new_img);
		vars->add++;
	}
	else if (vars->isfractal == 'j')
	{
		if (mousecode == SCROLL_DOWN)
			zoom *= 0.9;
		else if (mousecode == SCROLL_UP)
			zoom /= 0.9;
		else if (mousecode == 1)
		{
			vars->fract.c_x = screentocomplex(vars, x, y, 0);
			vars->fract.c_y = screentocomplex(vars, x, y, 1);
		}
		do_zoom(vars, x, y, zoom);
		change_julia(vars);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_julia(vars->fract, vars, vars->aux.new_img);
		vars->add++;
	}
	return (0);
}
