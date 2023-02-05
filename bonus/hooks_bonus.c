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

double	zoom_fractal(int mousecode, t_vars *vars)
{
	if (vars->ismandel == 1)
	{
		if (mousecode == SCROLL_DOWN)
			vars->aux.zoom *= 0.9;
		else if (mousecode == SCROLL_UP)
			vars->aux.zoom *= 1.1;
		change_mandelbrot(vars);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_mandelbrot(vars->mandb, vars, vars->aux.new_img);
	}
	else
	{
		if (mousecode == SCROLL_DOWN)
			vars->aux.zoom *= 1.1;
		else if (mousecode == SCROLL_UP)
			vars->aux.zoom *= 0.9;
		change_julia(vars);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_julia(vars->julia, vars, vars->aux.new_img);
	}
	return (vars->aux.zoom);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	static double	zoom;

	if (zoom == 0)
		zoom = 1;
	if (mousecode == SCROLL_DOWN || mousecode == SCROLL_UP)
	{
		vars->aux.zoom = zoom;
		vars->julia.movex = x * 3.23554 / vars->imgw;
		vars->julia.movey = y * 3.14856 / vars->imgh;
		zoom = zoom_fractal(mousecode, vars);
		vars->add++;
	}
	else if (mousecode == 1)
	{
		if (!vars->ismandel)
		{
			vars->julia.c_x = x * 3.23554 / vars->imgw - 1.5;
			vars->julia.c_y = y * 3.14856 / vars->imgh - 1.5;
			change_julia(vars);
			if (vars->add >= 1)
				mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
			initialize_img(&vars->aux.new_img, vars);
			do_julia(vars->julia, vars, vars->aux.new_img);
		}
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	static int		a;
	static double	left;
	static double	rigth;
	static double	up;
	static double	down;

	if (a == 0)
		a = 0;
	if (left == 0)
		left = 0;
	if (rigth == 0)
		rigth = 0;
	if (up == 0)
		up = 0;
	if (down == 0)
		down = 0;
	if (keycode == ESC)
		esc_window(vars);
	if (keycode == SPACE)
	{
		if (vars->ismandel == 1)
		{
			a += 100;
			vars->aux.color = a;
			change_mandelbrot(vars);
			if (vars->add >= 1)
				mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
			initialize_img(&vars->aux.new_img, vars);
			do_mandelbrot(vars->mandb, vars, vars->aux.new_img);
		}
		else
		{
			a += 100;
			vars->aux.color = a;
			change_julia(vars);
			if (vars->add >= 1)
				mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
			initialize_img(&vars->aux.new_img, vars);
			do_julia(vars->julia, vars, vars->aux.new_img);
		}

	}
	if (keycode == ARR_LEFT)
	{
		left -= 0.05;
		vars->julia.movex = rigth + left;
		vars->julia.movey = up + down;
		change_julia(vars);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_julia(vars->julia, vars, vars->aux.new_img);
	}
	if (keycode == ARR_RIGHT)
	{
		rigth += 0.05;
		vars->julia.movex = rigth + left;
		vars->julia.movey = up + down;
		change_julia(vars);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_julia(vars->julia, vars, vars->aux.new_img);
	}
	if (keycode == ARR_DOWN)
	{
		down -= 0.05;
		vars->julia.movex = rigth + left;
		vars->julia.movey = up + down;
		change_julia(vars);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_julia(vars->julia, vars, vars->aux.new_img);
	}
	if (keycode == ARR_UP)
	{
		up += 0.05;
		vars->julia.movex = rigth + left;
		vars->julia.movey = up + down;
		change_julia(vars);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_julia(vars->julia, vars, vars->aux.new_img);
	}
	return (0);
}

int	doing_events(t_vars *vars)
{
	mlx_mouse_hook(vars->win, &mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, &esc_window, vars);
	mlx_key_hook(vars->win, &key_hook, vars);
	return (0);
}
