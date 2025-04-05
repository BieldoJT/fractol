#include "fractol.h"


void map_screen_to_complex(int x, int y, t_fractol_values *values)
{
    // Mapeamento de pixel (x, y) da tela para o plano complexo (a, b)
    values->real = (x / (double)HEIGHT) * (values->a_max - values->a_min) + values->a_min;
    values->imag = (y / (double)WIDTH) * (values->b_max - values->b_min) + values->b_min;
}


int	color_by_iterations(int n, int max_iter, int offset, int palette)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (n >= max_iter)
		return (0x000000);
	t = (double)(n + offset) / (double)max_iter;
	if (palette == 0)
	{
		r = (int)(sin(5.0 * t + 0) * 127 + 128);
		g = (int)(sin(5.0 * t + 2) * 127 + 128);
		b = (int)(sin(5.0 * t + 4) * 127 + 128);
	}
	else if (palette == 1)
	{
		r = 255 - (int)(255 * t);
		g = (int)(64 * t);
		b = (int)(255 * t);
	}
	else
	{
		r = (n * 5 + offset) % 256;
		g = (n * 3 + offset) % 256;
		b = (n * 7 + offset) % 256;
	}
	return ((r << 16) | (g << 8) | b);
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

int	julia(t_mlx *mlx)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;
	int		max_iter;

	zr = mlx->values->real;
	zi = mlx->values->imag;
	max_iter = mlx->values->max_iter;
	n = 0;
	while ((zr * zr + zi * zi <= 4) && (n < max_iter))
	{
		tmp = zr * zr - zi * zi + mlx->values->c_real;
		zi = 2 * zr * zi + mlx->values->c_imag;
		zr = tmp;
		n++;
	}
	return (n);
}


void render_fractal(t_mlx *mlx)
{
	int	x;
	int	y;
	int	n;
	int	color;

	mlx_clear_window(mlx->mlx_ptr,mlx->win_ptr);
	x = 0;
	while (x < HEIGHT)  // Itera por todos os pixels da tela
	{
		y = 0;
		while (y < WIDTH)
		{
            // Mapeia o ponto (x, y) da tela para o plano complexo
			map_screen_to_complex(x, y, mlx->values);
            // Calcula o número de iterações do ponto (a, b)
            if (mlx->values->fractal_type == 0)
                n = mandelbrot(mlx);
            else
                n = julia(mlx);
            // Atribui uma cor de acordo com o número de iterações
			color = color_by_iterations(n,mlx->values->max_iter,
                mlx->values->color_offset,
                mlx->values->palette);
            // Desenha o ponto na tela usando a MiniLibX
			my_mlx_pixel_put(mlx, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}
