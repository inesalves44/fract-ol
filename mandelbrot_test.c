/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:22:46 by idias-al          #+#    #+#             */
/*   Updated: 2023/01/20 23:22:48 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
    int ImageHeight = 500;
    int ImageWidth = 500;
    double MinRe = -2.0;
    double MaxRe = 1.0;
    double MinIm = -1.2;
    double MaxIm = MinIm+(MaxRe-MinRe)*ImageHeight/ImageWidth;
    double Re_factor = (MaxRe-MinRe)/(ImageWidth-1);
    double Im_factor = (MaxIm-MinIm)/(ImageHeight-1);
    unsigned MaxIterations = 30;
    void	*mlx;
	void	*mlx_win;
    t_data  img;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, ImageHeight, ImageWidth, "MandelBrot");
    img.img = mlx_new_image(mlx, ImageHeight, ImageWidth);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    for(unsigned y=0; y<ImageHeight; ++y)
    {
        double c_im = MaxIm - y*Im_factor;
        for(unsigned x=0; x<ImageWidth; ++x)
        {
            double c_re = MinRe + x*Re_factor;
            double Z_re = c_re, Z_im = c_im;
            bool isInside = true;
            for(unsigned n=0; n<MaxIterations; ++n)
            {
                double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
                if(Z_re2 + Z_im2 > 4)
                {
                    isInside = false;
                    break;
                }
                Z_im = 2*Z_re*Z_im + c_im;
                Z_re = Z_re2 - Z_im2 + c_re;
            }
            if(isInside) 
            {
                my_mlx_pixel_put(&img, x, y, 0x00FF0000);
            }
        }
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}