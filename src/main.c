#include "fractol.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	ft_printf("hello world\n");

	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->values = malloc(sizeof(t_fractol_values));

	init_mlx(mlx);
	init_values(mlx->values);


	//my_mlx_pixel_put(mlx, 400,300, 0xFF0000);
	render_fractal(mlx);


	mlx_key_hook(mlx->win_ptr, my_key_func, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_zoom, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, destroy, mlx);
	mlx_loop(mlx->mlx_ptr);
	return 0;

}
