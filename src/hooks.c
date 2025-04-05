#include "fractol.h"

int	mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
	double	mouse_real;
	double	mouse_imag;
	double	zoom_factor;
    double	range;

    static int	zooming = 0;

    if (zooming)
        return (0);
    zooming = 1;

	range = mlx->values->a_max - mlx->values->a_min;
	if ((range < 1e-15 && button == 4) || (range > 10.0 && button == 5))
		return (0);  // Impede zoom in extremo ou zoom out exagerado
	if (button != 4 && button != 5)
		return (0);
	mouse_real = (x / (double)HEIGHT) * (mlx->values->a_max - mlx->values->a_min) + mlx->values->a_min;
	mouse_imag = (y / (double)WIDTH) * (mlx->values->b_max - mlx->values->b_min) + mlx->values->b_min;
	if (button == 4)
		zoom_factor = 0.95;
	else
	    zoom_factor = 1.05;
	mlx->values->a_min = mouse_real + (mlx->values->a_min - mouse_real) * zoom_factor;
	mlx->values->a_max = mouse_real + (mlx->values->a_max - mouse_real) * zoom_factor;
	mlx->values->b_min = mouse_imag + (mlx->values->b_min - mouse_imag) * zoom_factor;
	mlx->values->b_max = mouse_imag + (mlx->values->b_max - mouse_imag) * zoom_factor;
	render_fractal(mlx);

    zooming = 0;
	if (button == 4 && mlx->values->max_iter < 1000)
		mlx->values->max_iter += 10;
	else if (button == 5 && mlx->values->max_iter > 30)
		mlx->values->max_iter -= 10;

	return (0);
}


int	destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(0);
	return (0);
}

int my_key_func(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
        destroy(mlx);
	   // Teclas de seta para mover a visualização
    else if (keycode == 65361 || keycode == 97) // seta esquerda
    {
        mlx->values->a_min -= mlx->values->move_step;
        mlx->values->a_max -= mlx->values->move_step;
    }
    else if (keycode == 65363 || keycode == 100) // seta direita
    {
        mlx->values->a_min += mlx->values->move_step;
        mlx->values->a_max += mlx->values->move_step;
    }
    else if (keycode == 65362 || keycode == 119) // seta cima
    {
        mlx->values->b_min += mlx->values->move_step;
        mlx->values->b_max += mlx->values->move_step;
    }
    else if (keycode == 65364 || keycode == 115) // seta baixo
    {
        mlx->values->b_min -= mlx->values->move_step;
        mlx->values->b_max -= mlx->values->move_step;
    }
	//else if (keycode == 112)  // tecla P (zoom in)
	//	zoom(mlx->values, 0.9);
	//else if (keycode == 111)  // tecla O (zoom out)
	//	zoom(mlx->values, 1.1);
    // Redesenhar a tela com os novos limites
    render_fractal(mlx);
    return (0);
}




