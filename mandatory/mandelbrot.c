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

#include "../incs/fractol.h"

int	change_mandelbrot(t_vars *vars, double zoom)
{
	vars->mandb.zoom = zoom;
	vars->mandb.min_x = -2.0 * zoom;
	vars->mandb.max_x = (1.0) * zoom;
	vars->mandb.min_y = (-1.5) * zoom;
	vars->mandb.maxit = 150;
	vars->mandb.y = -1;
	vars->mandb.max_y = vars->mandb.min_y \
		+ (vars->mandb.max_x - vars->mandb.min_x) \
		* vars->mandb.heigth / vars->mandb.width;
	vars->mandb.y_factor = (vars->mandb.max_y - \
		vars->mandb.min_y) / (vars->mandb.heigth - 1);
	vars->mandb.x_factor = (vars->mandb.max_x - \
		vars->mandb.min_x) / (vars->mandb.width - 1);
	return (0);
}

int	do_mandelbrot(t_mdb m, t_vars *vars, t_data img)
{
	while (++m.y < m.heigth)
	{
		m.c_y = m.max_y - m.y * m.y_factor;
		m.x = -1;
		while (++m.x < m.width)
		{
			m.c_x = m.min_x + m.x * m.x_factor;
			m.z_y = m.c_y;
			m.z_x = m.c_x;
			m.n = -1;
			while (++m.n < m.maxit)
			{
				m.z_y2 = m.z_y * m.z_y;
				m.z_x2 = m.z_x * m.z_x;
				if (m.z_y2 + m.z_x2 > 4)
					break ;
				m.z_y = 2 * m.z_y * m.z_x + m.c_y;
				m.z_x = m.z_x2 - m.z_y2 + m.c_x;
			}
			get_color(m, img);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}

t_mdb	initialize_mandelbrot(char *argv[])
{
	t_mdb	m;

	m.width = check_windowinput(argv, 'w', 1);
	if (!m.width)
		m.width = IMG_W;
	m.heigth = check_windowinput(argv, 'h', 1);
	if (!m.heigth)
		m.heigth = IMG_H;
	m.zoom = 1;
	m.min_x = -2.0;
	m.max_x = 1.0;
	m.min_y = -1.2;
	m.max_y = m.min_y + (m.max_x - \
		m.min_x) * m.heigth / m.width;
	m.y_factor = (m.max_y - m.min_y) / (m.heigth - 1);
	m.x_factor = (m.max_x - m.min_x) / (m.width - 1);
	m.maxit = 150;
	m.y = -1;
	return (m);
}
