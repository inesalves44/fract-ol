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

#include "../incs/fractol_bonus.h"

int	key_hook(int keycode, t_vars *vars)
{
	static int		a;
	double	left;
	double	rigth;
	double	up;
	double	down;

	if (a == 0)
		a = 0;
	left = 0;
	rigth = 0;
	up = 0;
	down = 0;
	if (keycode == ESC)
		esc_window(vars);
	if (vars->isfractal == 'm' || vars->isfractal == 'b')
	{
		if(keycode == SPACE)
			a += 250;
		else if (keycode == ARR_LEFT)
			left = 0.05;
		else if (keycode == ARR_RIGHT)
			rigth = 0.05;
		else if (keycode == ARR_DOWN)
			down = 0.05;
		else if (keycode == ARR_UP)
			up = 0.05;
		vars->aux.color = a;
		vars->fract.offx += rigth - left;
		vars->fract.offy +=  up - down;
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
		if(keycode == SPACE)
			a += 250;
		else if (keycode == ARR_LEFT)
			left = 0.05;
		else if (keycode == ARR_RIGHT)
			rigth = 0.05;
		else if (keycode == ARR_DOWN)
			down =0.05;
		else if (keycode == ARR_UP)
			up =0.05;
		vars->aux.color = a;
		vars->fract.offx += rigth - left;
		vars->fract.offy +=  up - down;
		change_julia(vars);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_julia(vars->fract, vars, vars->aux.new_img);
		vars->add++;
	}
	return(0);
}

int	doing_events(t_vars *vars)
{
	mlx_mouse_hook(vars->win, &mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, &esc_window, vars);
	mlx_key_hook(vars->win, &key_hook, vars);
	return (0);
}
