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
	vars.win2 =  mlx_new_window(vars.mlx, 300, 300, "FRACTOL");
	mlx_string_put(vars.mlx, vars.win2, 1, 10, 0xFFFFFFFF, "Welcome to the fractal bonus!");
	mlx_string_put(vars.mlx, vars.win2, 1, 25, 0xFFFFFFFF, "Please choose one of these fractals:");
	mlx_string_put(vars.mlx, vars.win2, 1, 40, 0xFFFFFFFF, "1) Mandelbrot");
	mlx_string_put(vars.mlx, vars.win2, 1, 55, 0xFFFFFFFF, "2) Julia");
	mlx_string_put(vars.mlx, vars.win2, 1, 70, 0xFFFFFFFF, "3) Burningship");
	mlx_string_put(vars.mlx, vars.win2, 1, 85, 0xFFFFFFFF, "Please put the input in the terminal!");
	ft_printf("Please put the input: ");
	str = get_next_line(0);
	checking_fractal(str, argv, vars);
	doing_events(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
