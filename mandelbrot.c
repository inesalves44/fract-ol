
#include "./mlx/mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "incs/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int esc_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars, t_data *img, t_mandelbrot mandelbrot)
{
	if (keycode == 65307)
        esc_window(vars);
    else
    {
        ft_putnbr(keycode);
        ft_printf("\n");
    }
	return (0);
}

/*void	mouse_zoom(t_mandelbrot *f, double zoom, int x, int y)
{
	(void)x;
	(void)y;
	f->center_r = f->min_r - f->max_r;
	f->center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (f->center_r - zoom * f->center_r) / 2;
	f->min_r = f->max_r + zoom * f->center_r;
	f->min_i = f->min_i + (f->center_i - zoom * f->center_i) / 2;
	f->max_i = f->min_i + zoom * f->center_i;
	return ;
}*/

int	mouse_hook(int mousecode, t_vars *vars, t_data *img, t_mandelbrot mandelbrot)
{
	if (mousecode == 4)
    {
        //mouse_zoom();
    }
	return (0);
}

void    get_color(t_data img, t_mandelbrot mandelbrot, t_vars vars)
{
    int color;
    int i = 0;

    i = mandelbrot.maxit;
    color = 0xFF000000;
    while (i >= 0)
    {
        if (i == mandelbrot.n)
        {
            my_mlx_pixel_put(&img, mandelbrot.x, mandelbrot.y, color);
            break;
        }
        color += 500 * (i + mandelbrot.a);
        i--; 
    }
}

void    initialize_mandelbrot(t_mandelbrot *mandelbrot, int imgh, int imgw)
{
    mandelbrot->min_x = -2.0;
    mandelbrot->max_x = 1.0;
    mandelbrot->min_y = -1.2;
    mandelbrot->max_y = mandelbrot->min_y + (mandelbrot->max_x - mandelbrot->min_x) * imgh / imgw;
    mandelbrot->y_factor = (mandelbrot->max_y - mandelbrot->min_y) / (imgw - 1);
    mandelbrot->x_factor = (mandelbrot->max_x - mandelbrot->min_x) / (imgh - 1);
    mandelbrot->maxit = 150;
    mandelbrot->x = 0;
    mandelbrot->y = 0;
    mandelbrot->n = 0;
    mandelbrot->isinside = 0;
    mandelbrot->a = 0;
}

int    do_mandelbrot(t_mandelbrot mandelbrot, t_vars vars, t_data img)
{
     while (mandelbrot.y++ < vars.imageheigth)
    {
        mandelbrot.c_y = mandelbrot.max_y - mandelbrot.y * mandelbrot.y_factor;
        mandelbrot.x = 0;
        while (mandelbrot.x++ < vars.imagewidth)
        {
            mandelbrot.c_x = mandelbrot.min_x + mandelbrot.x * mandelbrot.x_factor;
            mandelbrot.z_y = mandelbrot.c_y;
            mandelbrot.z_x = mandelbrot.c_x;
            mandelbrot.n = -1;
            mandelbrot.isinside = 0;
            while (++mandelbrot.n < mandelbrot.maxit)
            {
                mandelbrot.z_y2 = mandelbrot.z_y * mandelbrot.z_y;
                mandelbrot.z_x2 = mandelbrot.z_x * mandelbrot.z_x;
                if (mandelbrot.z_y2 + mandelbrot.z_x2 > 4)
                {
                    mandelbrot.isinside = 1;
                    break ;
                }
                mandelbrot.z_y = 2 * mandelbrot.z_y * mandelbrot.z_x + mandelbrot.c_y;
                mandelbrot.z_x = mandelbrot.z_x2 - mandelbrot.z_y2 + mandelbrot.c_x;
            }
            get_color(img, mandelbrot, vars);
        }
    }
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    return (0);
}

int main()
{
    t_vars  vars;
    t_data  img;
    t_mandelbrot    mandelbrot;
    vars.imageheigth = 800;
    vars.imagewidth = 800;
    initialize_mandelbrot(&mandelbrot, vars.imageheigth, vars.imagewidth);
    vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.imageheigth, vars.imagewidth, "MandelBrot");
    img.img = mlx_new_image(vars.mlx, vars.imageheigth, vars.imagewidth);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    do_mandelbrot(mandelbrot, vars, img);
    //mlx_loop_hook(vars.mlx, &do_mandelbrot, &vars);
    mlx_hook(vars.win, 17, 0, &esc_window, &vars);
    mlx_mouse_hook(vars.mlx, &mouse_hook, &vars);
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);

    mlx_destroy_image(vars.mlx, img.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}