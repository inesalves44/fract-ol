/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:53:04 by idias-al          #+#    #+#             */
/*   Updated: 2023/01/20 21:53:07 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include ".././mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "../ft_printf/incs/ft_printf.h"
# include "../ft_printf/incs/get_next_line.h"

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_data;

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
    int     imagewidth;
    int     imageheigth;
}				t_vars;

typedef struct  s_mandelbrot
{
    double          min_x;
    double          max_x;
    double          min_y;
    double          max_y;
    double          y_factor;
    double          x_factor;
    double          c_y;
    double          c_x;
    double          z_y;
    double          z_x;
    double          z_y2;
    double          z_x2;
    unsigned int    n;
    unsigned int    maxit;
    unsigned int    x;
    unsigned int    y;
    int             isinside;
    int             a;
}               t_mandelbrot;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int key_hook(int keycode, t_vars *vars, t_data *img, t_mandelbrot *mandelbrot);
void    do_mandelbrot(t_mandelbrot mandelbrot, t_vars vars, t_data img);
#endif