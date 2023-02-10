/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:55 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 15:10:44 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

void	prep_julia(t_fract *fractol, char *argv[])
{
	fractol->max_x = 2;
	fractol->max_y = 1.5;
	fractol->min_x = -2;
	fractol->min_y = -1.5;
	fractol->maxit = 300;
	fractol->c_y = checkinputc(argv, 'y');
	if (fractol->c_y == -100000)
		fractol->c_y = CY_JULIA;
	fractol->c_x = checkinputc(argv, 'x');
	if (fractol->c_x == -100000)
		fractol->c_x = CX_JULIA;
}

t_fract	initialize(t_vars *vars, char *argv[])
{
	t_fract	fractol;

	fractol.width = vars->imgw;
	fractol.heigth = vars->imgh;
	if (vars->isfractal == 'j')
		prep_julia(&fractol, argv);
	else if (vars->isfractal == 'm' || vars->isfractal == 'b')
	{
		fractol.min_x = -2.05859375;
		fractol.min_y = -1.05859375;
		fractol.max_y = 1.05859375;
		fractol.max_x = 1.05859375;
		fractol.maxit = 150;
		if (vars->isfractal == 'b')
		{
			fractol.max_x = 2.05859375;
			fractol.min_y = -1.55859375;
			fractol.max_y = 1.55859375;
		}
	}
	return (fractol);
}

int	ft_fractal(int a, char *argv[])
{
	t_vars	vars;

	if (a == 1)
		vars.isfractal = 'm';
	else if (a == 3)
		vars.isfractal = 'b';
	else
		vars.isfractal = 'j';
	initialize_mlx(&vars, argv);
	initialize_img(&vars.img, &vars);
	vars.aux.color = 1;
	vars.aux.zoom = 1;
	vars.fract = initialize(&vars, argv);
	vars.fract.y = -1;
	vars.fract.color = 1;
	vars.fract.offx = 0;
	vars.fract.offy = 0;
	vars.fract.zoom = 1;
	if (a == 1 || a == 3)
		do_mdb_burns(vars.fract, &vars, vars.img);
	else
		do_julia(vars.fract, &vars, vars.img);
	doing_events(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	checking_fractal(char *argv[])
{
	if (!ft_strncmp(argv[1], "mandelbrot", 10) || !ft_strncmp(argv[1], "1", 1))
	{
		ft_comments(2);
		ft_fractal(1, argv);
	}
	else if (!ft_strncmp(argv[1], "julia", 5) || !ft_strncmp(argv[1], "2", 1))
	{
		ft_comments(1);
		ft_fractal(2, argv);
	}
	else if (!strncmp(argv[1], "burningship", 11) \
		|| !ft_strncmp(argv[1], "3", 1))
	{
		ft_comments(2);
		ft_fractal(3, argv);
	}
	else
	{
		ft_printf("No known fractals.\n");
		ft_comments(0);
	}
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		ft_comments(0);
	else
		checking_fractal(argv);
	return (0);
}
