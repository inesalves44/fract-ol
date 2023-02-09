/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:34:21 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 20:12:26 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

int	change_mandelbrot(t_vars *vars)
{
	vars->fract.maxit = 150;
	vars->fract.y = -1;
	vars->fract.color = vars->aux.color;
	vars->fract.max_x += vars->fract.offx;
	vars->fract.min_x += vars->fract.offx;
	vars->fract.max_y += vars->fract.offy;
	vars->fract.min_y += vars->fract.offy;
	return (0);
}

int	do_mandelbrot(t_fract m, t_vars *vars, t_data img)
{
	while (++m.y < m.heigth)
	{
		m.x = -1;
		while (++m.x < m.width)
		{
			m.c_x = screentocomplex(vars, m.x, m.y, 0);
			m.c_y = screentocomplex(vars, m.x, m.y, 1);
			m.prev_z_x = 0 ;
			m.prev_z_y = 0;
			m.n = -1;
			while (++m.n < m.maxit)
			{
				m.z_x = (m.prev_z_x * m.prev_z_x) - \
						(m.prev_z_y * m.prev_z_y) + m.c_x;
				m.z_y = 2 * m.prev_z_y * m.prev_z_x + m.c_y;
				if ((m.z_y * m.z_y + m.z_x * m.z_x) > 4)
					break ;
				m.prev_z_x = m.z_x;
				m.prev_z_y = m.z_y;
			}
			get_color(m, img);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}
