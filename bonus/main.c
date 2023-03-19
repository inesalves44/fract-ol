/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:02:41 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/11 10:02:45 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

void	writeoptions(t_vars vars)
{
	if (vars.isfractal == 'j')
	{
		mlx_string_put(vars.mlx, vars.win2, 1, 10, 0xFFFFFFFF, \
		"Here we have the Julia set!");
		mlx_string_put(vars.mlx, vars.win2, 1, 260, 0xFFFFFFFF, \
		"J1)You can use the left mouse button to change");
		mlx_string_put(vars.mlx, vars.win2, 1, 275, 0xFFFFFFFF, \
		"the Julia inputs.");
	}
	else if (vars.isfractal == 'm')
		mlx_string_put(vars.mlx, vars.win2, 1, 10, 0xFFFFFFFF, \
		"Here we have the Mandelbrot set!");
	else if (vars.isfractal == 'b')
		mlx_string_put(vars.mlx, vars.win2, 1, 10, 0xFFFFFFFF, \
		"Here we have the Burning ship set!");
}

void	writeinwindow(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win2, 1, 10, 0xFFFFFFFF, \
	"Welcome to the fractal bonus!");
	mlx_string_put(vars->mlx, vars->win2, 1, 30, 0xFFFFFFFF, \
	"Please choose one of these fractals:");
	mlx_string_put(vars->mlx, vars->win2, 1, 60, 0xFFFFFFFF, "1) Mandelbrot");
	mlx_string_put(vars->mlx, vars->win2, 1, 75, 0xFFFFFFFF, "2) Julia");
	mlx_string_put(vars->mlx, vars->win2, 1, 90, 0xFFFFFFFF, "3) Burning ship");
	mlx_string_put(vars->mlx, vars->win2, 1, 120, 0xFFFFFFFF, \
	"Please put the input in the terminal!");
	mlx_string_put(vars->mlx, vars->win2, 1, 150, 0xFFFFFFFF, \
	"If you want to change the window size");
	mlx_string_put(vars->mlx, vars->win2, 1, 165, 0xFFFFFFFF, \
	"please rerun the program with iwSIZE ihSIZE");
	mlx_string_put(vars->mlx, vars->win2, 1, 180, 0xFFFFFFFF, \
	"If you want to quit write quit!");
}

void	clear_window2(t_vars vars)
{
	if (!vars.win2)
	{
		free(vars.win2);
		free(vars.mlx);
		ft_printf("MLX window init failure.");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	char	*str;

	(void)argc;
	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		ft_printf("Mlx initialization failure.");
		exit(EXIT_FAILURE);
	}
	vars.win2 = mlx_new_window(vars.mlx, 300, 420, "FRACTOL");
	clear_window2(vars);
	writeinwindow(&vars);
	ft_printf("Please choose the fractal: ");
	str = get_next_line(0);
	if (!ft_strncmp(str, "quit", 4))
	{
		free(str);
		esc_window2(&vars);
	}
	checking_fractal(str, argv, vars);
	doing_events(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
