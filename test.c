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
	int xcentro = 250;
	int ycentro = 250;
	int r = 250;
	double angulo = 0;
	x = 0;
	y = 0;
	while (angulo <= 90)
	{
		if (angulo == 0)
		{
			y = r + ycentro;
			x = xcentro;
		}
		else if (angulo == 90)
		{
			x = xcentro + r;
			y = ycentro;
		}
		else 
		{
			y = ycentro + r * sin(angulo/(PI));
			x = xcentro + r * cos(angulo/(PI));
		}
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		angulo++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}