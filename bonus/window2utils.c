/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 01:14:22 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/13 01:14:24 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

void	doingfirstsquare(t_vars vars)
{
	int	x;
	int	y;

	x = 1;
	while (x < 140)
	{
		y = 40;
		while (y < 100)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFFFF0000);
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 5, 60, 0xFFFFFFFF, "Press Here");
	mlx_string_put(vars.mlx, vars.win2, 5, 70, 0xFFFFFFFF, "or");
	mlx_string_put(vars.mlx, vars.win2, 5, 80, 0xFFFFFFFF, "Press 'r' button.");
}

void	doingsecondsquare(t_vars vars)
{
	int	x;
	int	y;

	x = 150;
	while (x < 298)
	{
		y = 40;
		while (y < 100)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFF00FF00);
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 155, 60, 0x00000000, "Press Here");
	mlx_string_put(vars.mlx, vars.win2, 155, 70, 0x00000000, "or");
	mlx_string_put(vars.mlx, vars.win2, 155, 80, 0x00000000, \
	"Press 'g' button.");
}

void	doingthirdsquare(t_vars vars)
{
	int	x;
	int	y;

	x = 1;
	while (x < 140)
	{
		y = 105;
		while (y < 165)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFF0000FF);
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 5, 125, 0xFFFFFFFF, "Press Here");
	mlx_string_put(vars.mlx, vars.win2, 5, 135, 0xFFFFFFFF, "or");
	mlx_string_put(vars.mlx, vars.win2, 5, 145, 0xFFFFFFFF, \
	"Press 'b' button.");
}

void	doingfourthsquare(t_vars vars)
{
	int	x;
	int	y;

	x = 150;
	while (x < 298)
	{
		y = 105;
		while (y < 165)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, \
			0x00000001 * ((x + y) * 8000));
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 155, 125, 0xFFFFFFFF, "Press Here");
	mlx_string_put(vars.mlx, vars.win2, 155, 135, 0xFFFFFFFF, "or");
	mlx_string_put(vars.mlx, vars.win2, 155, 145, 0xFFFFFFFF, \
	"Press 'p' button.");
	mlx_string_put(vars.mlx, vars.win2, 155, 155, 0xFFFFFFFF, \
	"Also press SPACE.");
}
