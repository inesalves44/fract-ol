/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:09:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/10 22:43:29 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

int	get_window(t_vars *vars, char *argv[])
{
	vars->imgh = check_windowinput(argv, 'h', 0);
	if (!vars->imgh)
		vars->imgh = IMG_H;
	vars->imgw = check_windowinput(argv, 'w', 0);
	if (!vars->imgw)
		vars->imgw = IMG_W;
	return (0);
}

int	initialize_mlx(t_vars *vars, char *argv[])
{
	get_window(vars, argv);
	vars->add = 0;
	if (vars->isfractal == 'm')
		vars->win = mlx_new_window(vars->mlx, vars->imgw, vars->imgh, \
				"MandelBrot");
	else if (vars->isfractal == 'b')
		vars->win = mlx_new_window(vars->mlx, vars->imgw, vars->imgh, \
				"Burning Ship");
	else
		vars->win = mlx_new_window(vars->mlx, vars->imgw, vars->imgh, "Julia");
	if (!vars->win)
	{
		free(vars->win);
		free(vars->mlx);
		ft_printf("MLX window init failure.");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	initialize_img(t_data *img, t_vars *vars)
{
	img->img = mlx_new_image(vars->mlx, vars->imgw, vars->imgh);
	if (!img->img)
	{
		ft_printf("Image mlx creation failed");
		free(vars->mlx);
		free(vars->win);
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
			&img->line_length, &img->endian);
	if (!img->addr)
	{
		ft_printf("Image mlx creation failed");
		free(img->img);
		free(img->addr);
		free(vars->mlx);
		free(vars->win);
		exit(EXIT_FAILURE);
	}
	return (0);
}
