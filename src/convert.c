#include "fractol.h"


void map_screen_to_complex(int x, int y, t_fractol_values *values)
{
    // Mapeamento de pixel (x, y) da tela para o plano complexo (a, b)
    values->real = (x / (double)HEIGHT) * (values->a_max - values->a_min) + values->a_min;
    values->imag = (y / (double)WIDTH) * (values->b_max - values->b_min) + values->b_min;
}


int	color_by_iterations(int n, int max_iter)
{
	if (n >= max_iter)
		return (0x000000); // dentro do conjunto → preto
	return (0x003366 * (n % 10)); // azul escuro com variação
}

int mandelbrot(t_mlx *mlx)
{
    int max_iter = mlx->values->max_iter;  // Número máximo de iterações
    double real = 0.0;
    double imag = 0.0;
    int n = 0;

    // Iteração da equação
    while (real * real + imag * imag <= 4 && n < max_iter)
    {
        double temp_real = real * real - imag * imag + mlx->values->real;
        imag = 2 * real * imag + mlx->values->imag;
        real = temp_real;
        n++;
    }

    return n;  // Retorna o número de iterações até a "fuga"
}


void render_fractal(t_mlx *mlx)
{
	int	x;
	int	y;
	int	n;
	int	color;

	x = 0;
	while (x < HEIGHT)  // Itera por todos os pixels da tela
	{
		y = 0;
		while (y < WIDTH)
		{
            // Mapeia o ponto (x, y) da tela para o plano complexo
			map_screen_to_complex(x, y, mlx->values);

            // Calcula o número de iterações do ponto (a, b)
			n = mandelbrot(mlx);

            // Atribui uma cor de acordo com o número de iterações
			color = color_by_iterations(n, mlx->values->max_iter);

            // Desenha o ponto na tela usando a MiniLibX
			my_mlx_pixel_put(mlx, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}
