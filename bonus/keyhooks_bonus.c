/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:45:57 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 15:50:55 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

int	switchingfractals(int keycode, t_vars *vars)
{
	if (keycode == 115)
		vars->isfractal = 'b';
	else if (keycode == 109)
		vars->isfractal = 'm';
	else if (keycode == 106)
		vars->isfractal = 'j';
	vars->fract = initialize(vars);
	initother(&vars->fract, &vars->aux);
	if (vars->add >= 1)
		mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
	initialize_img(&vars->aux.new_img, vars);
	writing_to2window(*vars);
	if (vars->isfractal == 'm' || vars->isfractal == 'b')
		do_mdb_burns(vars->fract, vars, vars->aux.new_img);
	else
		do_julia(vars->fract, vars, vars->aux.new_img);
	vars->add++;
	return (0);
}

int	checking_keycode(int keycode, t_vars *vars)
{
	if (keycode == SPACE)
	{
		vars->aux.color += 250;
		vars->fract.color = 'p';
	}
	else if (keycode == ARR_LEFT)
		vars->aux.left = (-0.05) * vars->fract.zoom;
	else if (keycode == ARR_RIGHT)
		vars->aux.rigth = 0.05 * vars->fract.zoom;
	else if (keycode == ARR_DOWN)
		vars->aux.down = (-0.05) * vars->fract.zoom;
	else if (keycode == ARR_UP)
		vars->aux.up = 0.05 * vars->fract.zoom;
	else if (keycode == 114)
		vars->fract.colorsch = 'r';
	else if (keycode == 98)
		vars->fract.colorsch = 'b';
	else if (keycode == 103)
		vars->fract.colorsch = 'g';
	else if (keycode == 112)
		vars->fract.colorsch = 'p';
	else if (keycode == 106 || keycode == 109 || keycode == 115)
		switchingfractals(keycode, vars);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		esc_window(vars);
	else
		checking_keycode(keycode, vars);
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
	mlx_mouse_hook(vars->win2, &mouse_hook2, vars);
	mlx_hook(vars->win, 17, 0, &esc_window, vars);
	mlx_hook(vars->win2, 17, 0, &esc_window, vars);
	mlx_key_hook(vars->win, &key_hook, vars);
	mlx_key_hook(vars->win2, &key_hook, vars);
	return (0);
}
