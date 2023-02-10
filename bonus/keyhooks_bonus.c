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
	if (keycode == ESC)
		esc_window(vars);
	else if (keycode == SPACE)
		vars->aux.color += 250;
	else if (keycode == ARR_LEFT)
		vars->fract.offx -= 0.05 * vars->fract.zoom;
	else if (keycode == ARR_RIGHT)
		vars->fract.offx += 0.05 * vars->fract.zoom;
	else if (keycode == ARR_DOWN)
		vars->fract.offy -= 0.05 * vars->fract.zoom;
	else if (keycode == ARR_UP)
		vars->fract.offy += 0.05 * vars->fract.zoom;
	if (vars->isfractal == 'm' || vars->isfractal == 'b')
		change_mandelbrot(vars);
	else
		change_julia(vars);
	if (vars->add >= 1)
		mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
	initialize_img(&vars->aux.new_img, vars);
	if (vars->isfractal == 'm' || vars->isfractal == 'b')
		do_mdb_burns(vars->fract, vars, vars->aux.new_img);
	else
		do_julia(vars->fract, vars, vars->aux.new_img);
	vars->add++;
	return (0);
}

int	doing_events(t_vars *vars)
{
	mlx_mouse_hook(vars->win, &mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, &esc_window, vars);
	mlx_key_hook(vars->win, &key_hook, vars);
	return (0);
}
