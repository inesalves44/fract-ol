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

/*double	zoom_fractal(int mousecode, t_vars *vars, int x, int y)
{
	(void)x;
	(void)y;
	if (vars->ismandel == 1)
	{
		if (mousecode == SCROLL_DOWN)
			vars->aux.zoom *= 0.9;
		else if (mousecode == SCROLL_UP)
			vars->aux.zoom *= 1.1;
		change_mandelbrot(vars);
		printf("----------------------------------------------------------------\n");
			printf("cx center: %f\n", vars->mandb.prev_c_x);
			printf("cy center: %f\n", vars->mandb.prev_c_y);
			printf("x: %d\n", x);
			printf("y: %d\n", y);
			printf("move x: %f\n", vars->mandb.movex);
			printf("move y: %f\n", vars->mandb.movey);
			printf("new minx: %f\n", vars->mandb.min_x);
			printf("new max: %f\n", vars->mandb.max_x);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_mandelbrot(vars->mandb, vars, vars->aux.new_img);
	}
	else
	{
		if (mousecode == SCROLL_DOWN)
			vars->aux.zoom *= 0.9;
		else if (mousecode == SCROLL_UP)
			vars->aux.zoom *= 1.1;
		change_julia(vars);
		if (vars->add >= 1)
			mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
		initialize_img(&vars->aux.new_img, vars);
		do_julia(vars->julia, vars, vars->aux.new_img);
	}
	return (vars->aux.zoom);
}*/

/*int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	static double	zoom;

	if (zoom == 0)
		zoom = 1;
	if (mousecode == SCROLL_UP) //mousecode == SCROLL_DOWN ||
	{
		vars->aux.zoom = zoom;
		if (x <= vars->imgw / 2)
		{
			vars->julia.movex -= x * 3.23554 / vars->imgw;
		}
		else if (x > vars->imgw / 2)
			vars->julia.movex += x * 3.23554 / vars->imgw - 1.5;
		if (y <= vars->imgh / 2)
			vars->julia.movey -= y * 3.14856 / vars->imgh;
		else if (y <= vars->imgh / 2)
			vars->julia.movey += y * 3.14856 / vars->imgh - 1.5;
		zoom = zoom_fractal(mousecode, vars, x, y);
		vars->add++;
	}
	else if (mousecode == SCROLL_DOWN)
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
			vars->add++;
		}
		else
		{
			zoom *= 0.9;
			vars->aux.zoom = zoom;
			if (x != vars->imgw / 2)
			{
				if (x < vars->imgw / 2)
					vars->mandb.movex = - (vars->imgw / 2 -(double)x) * (vars->mandb.max_x - vars->mandb.min_x) / (vars->imgw);
				else
					vars->mandb.movex = (vars->imgw / 2 -(double)x) * (vars->mandb.max_x - vars->mandb.min_x) / (vars->imgw);
			}
			else
				vars->mandb.movex = 0;
			if (y != vars->imgw / 2)
			{
				if (y < vars->imgh / 2)
					vars->mandb.movey = (vars->imgh / 2 -(double)y) * (vars->mandb.max_y - vars->mandb.min_y) / (vars->imgh);
				else
					vars->mandb.movey = (vars->imgh / 2 -(double)y) * (vars->mandb.max_y - vars->mandb.min_y) / (vars->imgh);
			}
			else
				vars->mandb.movey = 0;
			change_mandelbrot(vars);
			printf("x: %d\n", x);
			printf("y: %d\n", y);
			printf("move x: %f\n", vars->mandb.movex);
			printf("move y: %f\n", vars->mandb.movey);
			printf("new minx: %f\n", vars->mandb.min_x);
			printf("new max: %f\n", vars->mandb.max_x);
			printf("new miny: %f\n", vars->mandb.min_y);
			printf("new maxy: %f\n", vars->mandb.max_y);
			if (vars->add >= 1)
				mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
			initialize_img(&vars->aux.new_img, vars);
			do_mandelbrot(vars->mandb, vars, vars->aux.new_img);
			vars->add++;
			vars->xaux = x;
			vars->yaux = y;
			//printf("xaux : %d\n", vars->xaux);
			//printf("yaux : %d\n", vars->yaux);
		}
	}
	else if (mousecode == 1)
	{
		printf("%d\n", x);
		double test_x = vars->mandb.min_x + ((vars->mandb.max_x - vars->mandb.min_x) * (double)x) / vars->imgw;
		printf("mouse x coordinate: %f\n", vars->mandb.min_x + ((vars->mandb.max_x - vars->mandb.min_x) * (double)x) / vars->imgw);
		printf("%d\n", y);
		double	test_y = vars->mandb.max_y - ((vars->mandb.max_y - vars->mandb.min_y) * (double)y) / vars->imgh;
		printf("mouse y coordinate: %f\n", vars->mandb.max_y - ((vars->mandb.max_y - vars->mandb.min_y) * (double)y) / vars->imgh);
		test_x += vars->prev_c_x + (test_x * 0.9);
		test_y += vars->prev_c_y + (test_y * 0.9);
	}
	return (0);
}*/

/*int	key_hook(int keycode, t_vars *vars)
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
			a += 250;
			vars->aux.color = a;
			change_mandelbrot(vars);
			if (vars->add >= 1)
				mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
			initialize_img(&vars->aux.new_img, vars);
			do_mandelbrot(vars->mandb, vars, vars->aux.new_img);
			vars->add++;
		}
		else
		{
			a += 80000;
			vars->aux.color = a;
			change_julia(vars);
			if (vars->add >= 1)
				mlx_destroy_image(vars->mlx, vars->aux.new_img.img);
			initialize_img(&vars->aux.new_img, vars);
			do_julia(vars->julia, vars, vars->aux.new_img);
			vars->add++;
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
		vars->add++;
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
		vars->add++;
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
		vars->add++;
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
		vars->add++;
	}
	return (0);
}*/

int	doing_events(t_vars *vars)
{
	mlx_mouse_hook(vars->win, &mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, &esc_window, vars);
	//mlx_key_hook(vars->win, &key_hook, vars);
	return (0);
}

			/*printf("----------------------------------------------------------------\n");
			printf("cx center: %f\n", vars->mandb.prev_c_x);
			printf("cy center: %f\n", vars->mandb.prev_c_y);
			printf("x: %d\n", x);
			printf("y: %d\n", y);
			printf("move x: %f\n", vars->mandb.movex);
			printf("move y: %f\n", vars->mandb.movey);
			printf("new minx: %f\n", vars->mandb.min_x);
			printf("new minx: %f\n", vars->mandb.min_x);*/
