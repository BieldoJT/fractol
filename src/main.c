#include "fractol.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
	if (argc != 2 || (ft_strncmp(argv[1], "mandelbrot", 10) != 0
		&& ft_strncmp(argv[1], "julia", 5) != 0))
	{
		ft_printf("Usage: ./fractol mandelbrot | julia\n");
		return (1);
	}

	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->values = malloc(sizeof(t_fractol_values));

	init_mlx(mlx);
	init_values(mlx->values);
	if (ft_strncmp(argv[1], "julia", 5) == 0)
		mlx->values->fractal_type = 1;


	//my_mlx_pixel_put(mlx, 400,300, 0xFF0000);
	render_fractal(mlx);


	mlx_key_hook(mlx->win_ptr, my_key_func, mlx);
	//mlx_hook(mlx->win_ptr,2, 1L<<0, my_key_func, mlx); //permite repetição do botão
	mlx_hook(mlx->win_ptr, 17, 0, destroy, mlx);
	mlx_loop_hook(mlx->mlx_ptr, update_animation, mlx);
	mlx_loop(mlx->mlx_ptr);
	return 0;

}
