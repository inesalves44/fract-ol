
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

int	key_hook(int keycode, t_vars *vars, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
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
        color += 500 * (i + 0);
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
}

void    do_mandelbrot()
{
    
}

int main()
{
    t_vars  vars;
    t_data  img;
    t_mandelbrot    mandelbrot;
    int imgh = 800;
    int imgw = 800;
    initialize_mandelbrot(&mandelbrot, imgh, imgw);
    vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, imgh, imgw, "MandelBrot");
    img.img = mlx_new_image(vars.mlx, imgh, imgw);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    while (mandelbrot.y++ < imgh)
    {
        mandelbrot.c_y = mandelbrot.max_y - mandelbrot.y * mandelbrot.y_factor;
        mandelbrot.x = 0;
        while (mandelbrot.x++ < imgw)
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
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}