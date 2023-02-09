/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:45:57 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 15:50:55 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

double	zoom_fractal(int mousecode, t_vars *vars, double zoom)
{
	if (vars->ismandel == 1)
	{
		if (mousecode == SCROLL_DOWN)
			zoom *= 0.9;
		else if (mousecode == SCROLL_UP)
			zoom *= 1.1;
		change_mandelbrot(vars, zoom);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.img);
		initialize_img(&vars->aux, vars);
		do_mandelbrot(vars->mandb, vars, vars->aux);
	}
	else
	{
		if (mousecode == SCROLL_DOWN)
			zoom *= 1.1;
		else if (mousecode == SCROLL_UP)
			zoom *= 0.9;
		change_julia(vars, zoom);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.img);
		initialize_img(&vars->aux, vars);
		do_julia(vars->julia, vars, vars->aux);
	}
	return (zoom);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	static double	zoom;

	(void)x;
	(void)y;
	if (zoom == 0)
		zoom = 1;
	if (vars->ismandel == 1)
	{
		if (mousecode == SCROLL_DOWN || mousecode == SCROLL_UP)
		{
			zoom = zoom_fractal(mousecode, vars, zoom);
			vars->add++;
		}
	}
	else
	{
		if (mousecode == SCROLL_DOWN || mousecode == SCROLL_UP)
		{
			zoom = zoom_fractal(mousecode, vars, zoom);
			vars->add++;
		}
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		esc_window(vars);
	return (0);
}

int	doing_events(t_vars *vars)
{
	mlx_mouse_hook(vars->win, &mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, &esc_window, vars);
	mlx_key_hook(vars->win, &key_hook, vars);
	return (0);
}
