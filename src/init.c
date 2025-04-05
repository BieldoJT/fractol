#include "fractol.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,HEIGHT,WIDTH, "janelaaaaa");
	mlx-> img = mlx_new_image(mlx->mlx_ptr, HEIGHT, WIDTH);
	mlx->addr = mlx_get_data_addr(mlx->img,&mlx->bits_per_pixel,\
		&mlx->line_length,&mlx->endian);
}

void	init_values(t_fractol_values *values)
{
	values->a_min = -2.0;
    values->a_max = 2.0;
    values->b_min = -2.0;
    values->b_max = 2.0;
	values->max_iter = 300;

    // Define a "velocidade" de movimento (como se move um pouco por vez)
    values->move_step = 0.1;
}
