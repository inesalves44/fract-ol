#include "./mlx/mlx.h"
#include <stdio.h>
#include <math.h>

#define PI 3.1415926

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x;
	int y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	x = 1;
	y = 1;
	/*while (x < 50)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y = 0;
		while (y < 50)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}*/

	x = 250;
	y = 250;
	int r = 2;
	double angulo = 0;
	while (angulo < 360)
	{
		x = x + r * sin(angulo/(2 * PI));
		y = y - r * (1 - cos(angulo/(2 * PI)));
		if (y < 0 || x < 0)
			break;
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);

		angulo++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}