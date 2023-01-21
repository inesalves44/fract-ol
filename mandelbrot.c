
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

void    initialize_mandelbrot(t_mandelbrot *mandelbrot, int imgh, int imgw)
{
    mandelbrot->minx = -2.0;
    mandelbrot->maxx = 1.0;
    mandelbrot->miny = -1.2;
    mandelbrot->maxy = mandelbrot->miny + (mandelbrot->maxx-mandelbrot->minx) * (imgh / imgw);
    mandelbrot->y_factor = (mandelbrot->maxy - mandelbrot->miny) / (imgw - 1);
    mandelbrot->x_factor = (mandelbrot->maxx - mandelbrot->minx) / (imgh - 1);
    mandelbrot->maxit = 30;
    mandelbrot->x = 0;
    mandelbrot->y = 0;
    mandelbrot->n = 0;
    mandelbrot->isinside = true;
}

int main()
{
    void	*mlx;
	void	*mlx_win;
    bool    isinside;
    t_data  img;
    t_mandelbrot    mandelbrot;
    int imgh = 500;
    int imgw = 500;
    initialize_mandelbrot(&mandelbrot, imgh, imgw);
    mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, imgh, imgw, "MandelBrot");
    img.img = mlx_new_image(mlx, imgh, imgw);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    while (mandelbrot.y++ < imgh)
    {
        mandelbrot.c_y = mandelbrot.maxy - mandelbrot.y * mandelbrot.y_factor;
        while (mandelbrot.x++ < imgw)
        {
            mandelbrot.c_x = mandelbrot.minx + mandelbrot.x * mandelbrot.x_factor;
            mandelbrot.z_y = mandelbrot.c_y;
            mandelbrot.z_x = mandelbrot.c_x;
            isinside = true;
            while (mandelbrot.n < mandelbrot.maxit)
            {
                mandelbrot.z_y2 = mandelbrot.z_y * mandelbrot.z_y;
                mandelbrot.z_x2 = mandelbrot.z_x * mandelbrot.z_x;
                if (mandelbrot.z_y2 + mandelbrot.z_x2 > 4)
                {
                    isinside = false;
                    break ;
                }
                mandelbrot.z_y = 2 * mandelbrot.z_y * mandelbrot.z_x + mandelbrot.c_y;
                mandelbrot.z_x = mandelbrot.z_x2 - mandelbrot.z_y2 + mandelbrot.c_x;
                ++mandelbrot.n;
            }
            if (isinside)
                my_mlx_pixel_put(&img, mandelbrot.x, mandelbrot.y, 0x00FF0000);
        }
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

                /*printf("value of x: %d | ", mandelbrot.x);
                printf("value of c_x: %f | ", mandelbrot.c_x);
                printf("value of z_x: %f | ", mandelbrot.z_x);
                printf("value of z_x2: %f | ", mandelbrot.z_x2);
                printf("value of n: %d", mandelbrot.n);
                printf("\n");
                printf("\n");*/