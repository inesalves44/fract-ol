/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:55 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 15:10:44 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

t_fract	initialize(t_vars *vars, char *argv[])
{
	t_fract	fractol;

	fractol.width = vars->imgw;
	fractol.heigth = vars->imgh;
	if (vars->isfractal == 'j')
	{
		fractol.max_x = 2;
		fractol.max_y = 1.5;
		fractol.min_x = -2;
		fractol.min_y = -1.5;
		fractol.maxit = 300;
		fractol.c_y = checkinputc(argv, 'y');
		if (fractol.c_y == -100000)
			fractol.c_y = CY_JULIA;
		fractol.c_x = checkinputc(argv, 'x');
		if (fractol.c_x == -100000)
			fractol.c_x = CX_JULIA;
	}
	else if (vars->isfractal == 'm')
	{
		fractol.min_x = -2.05859375;
		fractol.max_x = 1.05859375;
		fractol.min_y = -1.05859375;
		fractol.max_y = 1.05859375;
		fractol.maxit = 150;
	}
	else
	{
		fractol.min_x = -2.05859375;
		fractol.max_x = 2.05859375;
		fractol.min_y = -1.5859375;
		fractol.max_y = 1.5859375;
		fractol.maxit = 150;
	}
	fractol.y = -1;
	fractol.color = 1;
	fractol.offx = 0;
	fractol.offy = 0;
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
	if (a == 1)
		do_mandelbrot(vars.fract, &vars, vars.img);
	else if (a == 3)
		do_burnship(vars.fract, &vars, vars.img);
	else
		do_julia(vars.fract, &vars, vars.img);
	doing_events(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc < 2)
		ft_comments(0);
	else
	{
		str = create_string(argv[1]);
		if (!ft_strncmp(str, "mandelbrot", 10) || !ft_strncmp(str, "1", 1))
		{
			free(str);
			ft_comments(2);
			ft_fractal(1, argv);
		}
		else if (!ft_strncmp(str, "julia", 5) || !ft_strncmp(str, "2", 1))
		{
			free(str);
			ft_comments(1);
			ft_fractal(2, argv);
		}
		else if (!strncmp(str, "burningship", 11) || !ft_strncmp(str, "2", 1))
		{
			free(str);
			ft_comments(1);
			ft_fractal(3, argv);
		}
		else
			ft_printf("No known fractal.\n");
	}
	return (0);
}
