/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:53:04 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 15:07:15 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include ".././mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "../ft_printf/incs/ft_printf.h"
# include "../ft_printf/incs/get_next_line.h"

# if __linux
#  define ESC 65307
#  define SCROLL_UP 5
#  define SCROLL_DOWN 4
#  define ARR_UP 65364
#  define ARR_DOWN 65362
#  define ARR_RIGHT 65363
#  define ARR_LEFT 65361
#  define SPACE 32
# else
#  define ESC 53
#  define SCROLL_UP 5
#  define SCROLL_DOWN 4
#  define ARR_UP 125
#  define ARR_DOWN 126
#  define ARR_RIGHT 124
#  define ARR_LEFT 123
# endif

# ifndef IMG_H
#  define IMG_H 450
# endif

# ifndef IMG_W
#  define IMG_W 600
# endif

# ifndef CX_JULIA
#  define CX_JULIA -0.7
# endif

# ifndef CY_JULIA
#  define CY_JULIA  0.27015
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractal
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	c_y;
	double	c_x;
	double	z_y;
	double	z_x;
	double	prev_z_y;
	double	prev_z_x;
	int		n;
	int		maxit;
	int		x;
	int		y;
	int		width;
	int		heigth;
	int		color;
	double	offx;
	double	offy;
	double	zoom;
	char	colorsch;
}	t_fract;

typedef struct s_aux
{
	int		color;
	float	offx;
	float	offy;
	double	left;
	double	rigth;
	double	up;
	double	down;
	double	zoom;
	t_data	new_img;
}	t_aux;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*win2;
	int		imgw;
	int		imgh;
	int		add;
	char	isfractal;
	t_data	img;
	t_fract	fract;
	t_aux	aux;
}	t_vars;

/*Fractinit*/
void	prep_julia(t_fract *fractol);
t_fract	initialize(t_vars *vars);
int		ft_fractal(int a, char *argv[], t_vars vars, char *str);
void	initother(t_fract *fract, t_aux *aux);
int		checking_fractal(char *str, char *argv[], t_vars vars);

/*Main*/
void	writeoptions(t_vars vars);
void	writeinwindow(t_vars *vars);

/*Exit functions*/
int		esc_window(t_vars *vars);
int		esc_window2(t_vars *vars);
void	writing_to2window(t_vars vars);
void	doingsquare_fract3(t_vars vars);
void	doingsquare_fract1(t_vars vars);

/*Julia*/
int		change_julia(t_vars *vars);
int		do_julia(t_fract julia, t_vars *vars, t_data img);
double	checkinputc(char *argv[], char a);

/*Mandelbrot*/
int		do_mdb_burns(t_fract m, t_vars *vars, t_data img);
int		finish_mand(t_fract m, t_data img);
int		change_mandelbrot(t_vars *vars);

/*Burningship*/
int		finish_burnship(t_fract b, t_data img);

/*pixel in an image*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	get_color(t_fract mandelbrot, t_data img);
void	get_color_julia(t_fract julia, t_data img);
double	screentocomplex(t_vars *vars, int x, int y, int i);

/*Color*/
int		get_r(int m);
int		get_g(int m);
int		get_b(int m);

/*fractol_utils*/
double	ft_atod(char *str);
int		check_windowinput(char *argv[], char a, int j);

/*Hook functions*/
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int mousecode, int x, int y, t_vars *vars);
int		doing_events(t_vars *vars);
void	do_zoom(t_vars *vars, int x, int y);
int		mouse_hook2(int mousecode, int x, int y, t_vars *vars);

/*Initialize functions*/
int		initialize_mlx(t_vars *vars, char *argv[]);
int		initialize_img(t_data *img, t_vars *vars);

/*Window2*/
void	doingfirstsquare(t_vars vars);
void	doingsecondsquare(t_vars vars);
void	doingthirdsquare(t_vars vars);
void	doingfourthsquare(t_vars vars);
void	doingsquare_fract2(t_vars vars);
#endif
