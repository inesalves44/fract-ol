/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burngship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:58:42 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/09 10:58:43 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

int	finish_burnship(t_fract b, t_data img)
{
	while (++b.n < b.maxit)
	{
		b.prev_z_y = fabs(b.prev_z_y);
		b.prev_z_x = fabs(b.prev_z_x);
		b.z_x = (b.prev_z_x * b.prev_z_x) - (b.prev_z_y * b.prev_z_y) + b.c_x;
		b.z_y = 2 * b.prev_z_y * b.prev_z_x + b.c_y;
		if ((b.z_y * b.z_y + b.z_x * b.z_x) > 4)
			break ;
		b.prev_z_x = b.z_x;
		b.prev_z_y = b.z_y;
	}
	if (b.colorsch == 'r' && b.n != b.maxit)
		my_mlx_pixel_put(&img, b.x, b.y, get_r(b.n));
	else if (b.colorsch == 'b' && b.n != b.maxit)
		my_mlx_pixel_put(&img, b.x, b.y, get_b(b.n));
	else if (b.colorsch == 'g' && b.n != b.maxit)
		my_mlx_pixel_put(&img, b.x, b.y, get_g(b.n));
	else if (b.colorsch == 'p' && b.n != b.maxit)
		get_color(b, img);
	else if (b.n == b.maxit)
		my_mlx_pixel_put(&img, b.x, b.y, 0x000000);
	return (0);
}
