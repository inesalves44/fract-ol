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

#include "../incs/fractol_bonus.h"

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
		color += 111 * (i * 2) * mandelbrot.color;
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
			color += 100 * (i * 2) * julia.color;
		else if (julia.n > 100 && julia.n <= 200)
			color += 200 * (i * 3) * julia.color;
		else if (julia.n > 50 && julia.n <= 100)
			color += 300 * (i * 4) * julia.color;
		else if (julia.n <= 50)
			color += 400 * (i + 1) * julia.color;
		i--;
	}
	my_mlx_pixel_put(&img, julia.x, julia.y, color);
}
