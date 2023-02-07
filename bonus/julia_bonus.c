/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:20 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 19:48:58 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

int	change_julia(t_vars *vars)
{
	vars->julia.zoom = vars->aux.zoom;
	vars->julia.color = vars->aux.color;
	vars->julia.maxit = 300;
	vars->julia.x = -1;
	vars->julia.y = -1;
	vars->julia.n = 0;
	return (0);
}

int	do_julia(t_julia j, t_vars *vars, t_data img)
{
	while (++j.y < j.heigth)
	{
		j.x = -1;
		while (++j.x < j.width)
		{
			j.z_x = 1.5 * (j.x - j.width / 2) / (0.5 * j.zoom * j.width) + j.movex;
			j.z_y = (j.y - j.heigth / 2) / (0.5 * j.zoom * j.heigth) + j.movey;
			j.n = -1;
			while (++j.n < j.maxit)
			{
				j.prev_z_x = j.z_x;
				j.prev_z_y = j.z_y;
				j.z_x = (j.prev_z_x * j.prev_z_x) - \
						(j.prev_z_y * j.prev_z_y) + j.c_x;
				j.z_y = 2 * j.prev_z_y * j.prev_z_x + j.c_y;
				if ((j.z_y * j.z_y + j.z_x * j.z_x) > 4)
					break ;
			}
			get_color_julia(j, img);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}

double	checkinputc(char *argv[], char a)
{
	int		i;
	double	c;

	i = 2;
	c = -100000;
	while (argv[i])
	{
		if (argv[i][0] == 'c' && argv[i][1] == 'x' && a == 'x')
			c = ft_atod(argv[i] + 2);
		else if (argv[i][0] == 'c' && argv[i][1] == 'y' && a == 'y')
			c = ft_atod(argv[i] + 2);
		if (c != -100000)
			break ;
		i++;
	}
	if (c != -100000 && (c > 1 || c < -2))
	{
		ft_printf("\nThe values won't show much. ");
		ft_printf("cy and cx should be between (-2, 1)\n");
	}
	if (argv[2] && c != -100000)
		return (c);
	return (-100000);
}

t_julia	initialize_julia(char *argv[])
{
	t_julia	julia;

	julia.width = check_windowinput(argv, 'w', 1);
	if (!julia.width)
		julia.width = IMG_W;
	julia.heigth = check_windowinput(argv, 'h', 1);
	if (!julia.heigth)
		julia.heigth = IMG_H;
	julia.zoom = 1;
	julia.c_y = checkinputc(argv, 'y');
	if (julia.c_y == -100000)
		julia.c_y = CY_JULIA;
	julia.c_x = checkinputc(argv, 'x');
	if (julia.c_x == -100000)
		julia.c_x = CX_JULIA;
	julia.maxit = 300;
	julia.y = -1;
	julia.color = 1;
	julia.movex = 0;
	julia.movey = 0;
	return (julia);
}
