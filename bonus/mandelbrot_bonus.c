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
	vars->mandb.zoom = vars->aux.zoom;
	vars->mandb.maxit = 150;
	vars->mandb.y = -1;
	vars->mandb.color = vars->aux.color;
	return (0);
}

double	screentocomplex(t_vars *vars, int x, int y, int i)
{
	double	number;

	if (i == 0)
		number = (((double)x / vars->imgw) * (vars->mandb.max_x - vars->mandb.min_x)) * vars->aux.zoom + vars->mandb.min_x + vars->mandb.offx;//1.5 * ((double)x - vars->imgw / 2) / (0.5 * vars->aux.zoom * vars->imgw) + vars->mandb.offx;
	else
		number = (((double)y / vars->imgh) * (vars->mandb.max_y - vars->mandb.min_y)) * vars->aux.zoom + vars->mandb.min_y + vars->mandb.offy; //((double)y - vars->imgh / 2) / (0.5 * vars->aux.zoom *vars->imgh) + vars->mandb.offy;
	return (number);
}


int	do_mandelbrot(t_mdb m, t_vars *vars, t_data img)
{
	while (++m.y < m.heigth)
	{
		m.x = -1;
		while (++m.x < m.width)
		{
			m.c_x = screentocomplex(vars, m.x, m.y, 0);
			m.c_y = screentocomplex(vars, m.x, m.y, 1);
			m.prev_z_x = 0;
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
void	change_minmax(t_mdb *m)
{
	double w;
	double h;

	w = m->max_x - m->min_x;
	h = m->max_y - m->min_y;
	if (w / h >= (float)m->width / m->heigth)
	{
		m->min_y = -(w * m->heigth / m->width / 2);
		m->max_y = w * m->heigth / m->width / 2;
	}
	else
	{
		m->min_x = -(h * m->width / m->heigth / 2);
		m->max_x = (h * m->width / m->heigth / 2);
	}
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
	m.min_x = -2.05859375;
	m.max_x = 1.05859375;
	m.min_y = -1.05859375;
	m.max_y = 1.05859375;
	change_minmax(&m);
	m.maxit = 150;
	m.y = -1;
	m.color = 1;
	m.offx = -0.37109375;
	m.offy = 0;
	return (m);
}
//printf("new min_y: %f\n", vars->mandb.min_y);
//printf("new min_y: %f\n", vars->mandb.max_y);
//(-2.0) * vars->aux.zoom - vars->mandb.movex;
//(1.0) * vars->aux.zoom - vars->mandb.movex;
//(-1.2) * vars->aux.zoom - vars->mandb.movey;
/*(1.5) * vars->aux.zoom - vars->mandb.movey; vars->mandb.min_y + (vars->mandb.max_x - vars->mandb.min_x) * vars->mandb.heigth / vars->mandb.width;*/
//printf("y factor: %f\n", vars->mandb.y_factor);
	//m.min_x = -2.0;//-2.0;
	//m.max_x = 1.0; //1.0;
	//m.min_y = -1.5;
	//m.max_y = 1.5;//m.min_y + (m.max_x - m.min_x) * m.heigth / m.width;
	//m.y_factor = (m.max_y - m.min_y) / (m.heigth - 1); //(1.5 - (-1.5)) / (m.heigth - 1);
	//m.x_factor =  (m.max_x - m.min_x) / (m.width - 1);//(1 - (-2)) / (m.width - 1);
