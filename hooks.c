#include "./mlx/mlx.h"
#include <stdio.h>
#include "incs/fractol.h"

int	key_hook(int keycode, t_vars *vars, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

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

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int yini;
	int xini;
	int x;
	int y;

	vars.imagewidth = 480;
	vars.imageheigth = 640;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.imageheigth, vars.imagewidth, "Hello world!");
	img.img = mlx_new_image(vars.mlx, vars.imageheigth, vars.imagewidth);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	yini = 20;
	xini = 20;
	int color = 0x00FF000000;
	while (y < (yini + 100))
	{
		x = xini;
		while (x < (xini + 100))
		{
			color += 1000;
            my_mlx_pixel_put(&img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	
}