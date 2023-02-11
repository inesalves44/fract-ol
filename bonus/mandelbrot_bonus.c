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
	if (vars->fract.colorsch == 'p')
		vars->fract.color += vars->aux.color;
	vars->fract.offx = vars->aux.offx;
	vars->fract.offy = vars->aux.offy;
	vars->fract.max_x += vars->fract.offx + vars->aux.left + vars->aux.rigth;
	vars->fract.min_x += vars->fract.offx + vars->aux.left + vars->aux.rigth;
	vars->fract.max_y += vars->fract.offy + vars->aux.up + vars->aux.down;
	vars->fract.min_y += vars->fract.offy + vars->aux.up + vars->aux.down;
	vars->aux.left = 0;
	vars->aux.rigth = 0;
	vars->aux.down = 0;
	vars->aux.offx = 0;
	vars->aux.offy = 0;
	return (0);
}

int	finish_mand(t_fract m, t_data img)
{
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
	if (m.colorsch == 'r' && m.n != m.maxit)
		my_mlx_pixel_put(&img, m.x, m.y, get_r(m.n));
	else if (m.colorsch == 'b' && m.n != m.maxit)
		my_mlx_pixel_put(&img, m.x, m.y, get_b(m.n));
	else if (m.colorsch == 'g' && m.n != m.maxit)
		my_mlx_pixel_put(&img, m.x, m.y, get_g(m.n));
	else if (m.colorsch == 'p' && m.n != m.maxit)
		get_color(m, img);
	else if (m.n == m.maxit)
		my_mlx_pixel_put(&img, m.x, m.y, 0x000000);
	return (0);
}

int	do_mdb_burns(t_fract m, t_vars *vars, t_data img)
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
			if (vars->isfractal == 'm')
				finish_mand(m, img);
			else if (vars->isfractal == 'b')
				finish_burnship(m, img);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}
