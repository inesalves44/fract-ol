#include "./mlx/mlx.h"
#include "incs/fractol.h"
#include <stdio.h>
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == 1)
	{
		ft_putnbr(mousecode);
	}
	else if (mousecode == 4)
	{
		ft_putnbr(mousecode);
	}
    return(0);
}

int esc_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	drawing_square(t_data img, int i, t_vars vars)
{
	int x;
	int y;

	x = 50;
	y = 50;
	int color = 0x00ff0000 + i * 1000;
	while (x < 100)
	{
		y = 50;
		while (y < 100)
		{
			color += 5000 * i;
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		x++;
	}
}

int	key_hook(int keycode, t_vars *vars, t_data *img)
{
	static int i;

	i = 1;
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 32)
	{
		i++;
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = mlx_new_window(vars->mlx, 500, 500, "Squareeeeee");
		img->img = mlx_new_image(vars->mlx, 500, 500);
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
		drawing_square(*img, i, *vars);
		mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
		mlx_hook(vars->win, 17, 0, &esc_window, vars);
		mlx_key_hook(vars->win, &key_hook, vars);
		mlx_mouse_hook(vars->win, &mouse_hook, vars);
		mlx_loop(vars->mlx);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int x;
	int y;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Squareeeeee");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	drawing_square(img, 1, vars);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 0, &esc_window, &vars);
	mlx_key_hook(vars.win, &key_hook, &vars);
	mlx_mouse_hook(vars.win, &mouse_hook, &vars);
	mlx_loop(vars.mlx);
	
	mlx_destroy_image(vars.mlx, img.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}