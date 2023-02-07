/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:25:38 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/04 15:55:55 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_color(t_mdb mandelbrot, t_data img)
{
	int	color;
	int	i;

	i = mandelbrot.maxit;
	color = 0x00000000;
	while (i)
	{
		if (i == mandelbrot.n)
		{
			my_mlx_pixel_put(&img, mandelbrot.x, mandelbrot.y, color);
			break ;
		}
		color += 111 * (i * 2);
		i--;
	}
	my_mlx_pixel_put(&img, mandelbrot.x, mandelbrot.y, color);
}

void	get_color_julia(t_julia julia, t_data img)
{
	int	color;
	int	i;

	i = julia.maxit;
	color = 0x00000000;
	while (i)
	{
		if (i == julia.n)
		{
			my_mlx_pixel_put(&img, julia.x, julia.y, color);
			break ;
		}
		else if (julia.n > 200)
			color += 50 + (i);
		else if (julia.n > 100 && julia.n <= 200)
			color += (500 + 1) + (i);
		else if (julia.n > 50 && julia.n <= 100)
			color += (7000 + 5) + (i - 49);
		else if (julia.n <= 50)
			color += (8050 + 10) + (i);
		i--;
	}
	my_mlx_pixel_put(&img, julia.x, julia.y, color);
}
