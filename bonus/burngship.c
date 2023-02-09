/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burngship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:58:42 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/09 10:58:43 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

/*int	change_mandelbrot(t_vars *vars)
{
	vars->fract.maxit = 150;
	vars->fract.y = -1;
	vars->fract.color = vars->aux.color;
	vars->fract.max_x += vars->fract.offx;
	vars->fract.min_x += vars->fract.offx;
	vars->fract.max_y += vars->fract.offy;
	vars->fract.min_y += vars->fract.offy;
	return (0);
}*/

int	do_burnship(t_fract b, t_vars *vars, t_data img)
{
	while (++b.y < b.heigth)
	{
		b.x = -1;
		while (++b.x < b.width)
		{
			b.c_x = screentocomplex(vars, b.x, b.y, 0);
			b.c_y = screentocomplex(vars, b.x, b.y, 1);
			b.prev_z_x = 0;
			b.prev_z_y = 0;
			b.n = -1;
			while (++b.n < b.maxit)
			{
				b.prev_z_y = fabs(b.prev_z_y);
				b.prev_z_x = fabs(b.prev_z_x);
				b.z_x = (b.prev_z_x * b.prev_z_x) - (b.prev_z_y * b.prev_z_y) + b.c_x;
				b.z_y = 2 * b.prev_z_y * b.prev_z_x + b.c_y;
				if ((b.z_y * b.z_y + b.z_x * b.z_x) > 4)
					break ;
				b.prev_z_x = b.z_x;
				b.prev_z_y = b.z_y;
			}
			get_color(b, img);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}

/*t_fract	initialize(t_vars *vars)
{
	t_fract	burns;

	burns.width = vars->imgw;
	burns.heigth = vars->imgh;
	burns.min_x = -2.05859375;
	burns.max_x = 1.05859375;
	burns.min_y = -1.05859375;
	burns.max_y = 1.05859375;
	burns.maxit = 150;
	burns.y = -1;
	burns.color = 1;
	burns.offx = 0;
	burns.offy = 0;
	return (burns);
}*/
