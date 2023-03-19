/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractinit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:55 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 15:10:44 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

void	prep_julia(t_fract *fractol)
{
	fractol->max_x = 2;
	fractol->max_y = 1.5;
	fractol->min_x = -2;
	fractol->min_y = -1.5;
	fractol->maxit = 300;
	fractol->c_y = CY_JULIA;
	fractol->c_x = CX_JULIA;
}

t_fract	initialize(t_vars *vars)
{
	t_fract	fractol;

	fractol.width = vars->imgw;
	fractol.heigth = vars->imgh;
	if (vars->isfractal == 'j')
		prep_julia(&fractol);
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
	fractol.colorsch = 'b';
	return (fractol);
}

void	initother(t_fract *fract, t_aux *aux)
{
	aux->color = 0;
	aux->zoom = 1;
	aux->offx = 0;
	aux->offy = 0;
	aux->left = 0;
	aux->rigth = 0;
	aux->up = 0;
	aux->down = 0;
	fract->color = 0;
	fract->offx = 0;
	fract->offy = 0;
	fract->zoom = 1;
	fract->y = -1;
}

int	ft_fractal(int a, char *argv[], t_vars vars, char *str)
{
	(void)argv;
	if (a == 1)
		vars.isfractal = 'm';
	else if (a == 3)
		vars.isfractal = 'b';
	else
		vars.isfractal = 'j';
	initialize_mlx(&vars, argv);
	initialize_img(&vars.img, &vars);
	vars.fract = initialize(&vars);
	initother(&vars.fract, &vars.aux);
	if (a == 1 || a == 3)
		do_mdb_burns(vars.fract, &vars, vars.img);
	else
		do_julia(vars.fract, &vars, vars.img);
	writing_to2window(vars);
	free (str);
	doing_events(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

int	checking_fractal(char *str, char *argv[], t_vars vars)
{
	char	*str1;

	if (!ft_strncmp(str, "mandelbrot", 10) || !ft_strncmp(str, "1", 1))
		ft_fractal(1, argv, vars, str);
	else if (!ft_strncmp(str, "julia", 5) || !ft_strncmp(str, "2", 1))
		ft_fractal(2, argv, vars, str);
	else if (!ft_strncmp(str, "burning ship", 11) \
		|| !ft_strncmp(str, "3", 1))
		ft_fractal(3, argv, vars, str);
	if (!ft_strncmp(str, "quit", 4))
	{
		free(str);
		esc_window2(&vars);
	}
	else
	{
		ft_printf("No known fractals. Please input again:\n");
		ft_printf("Fractal input: ");
		str1 = get_next_line(0);
		checking_fractal(str1, argv, vars);
		return (1);
	}
	return (0);
}
