#include "fractol.h"




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
	double move_step;

	move_step = (mlx->values->a_max - mlx->values->a_min) * 0.05;
	if (keycode == ESCAPE)
        destroy(mlx);
	   // Teclas de seta para mover a visualização
    else if (keycode == 65361 || keycode == 97) // seta esquerda
    {
        mlx->values->a_min -= move_step;
        mlx->values->a_max -= move_step;
    }
    else if (keycode == 65363 || keycode == 100) // seta direita
    {
        mlx->values->a_min += move_step;
        mlx->values->a_max += move_step;
    }
    else if (keycode == 65362 || keycode == 119) // seta cima
    {
        mlx->values->b_min -= move_step;
        mlx->values->b_max -= move_step;
    }
    else if (keycode == 65364 || keycode == 115) // seta baixo
    {
		mlx->values->b_min += move_step;
        mlx->values->b_max += move_step;
    }
	else if (keycode == 112)  // tecla P (zoom in)
		zoom(mlx->values, 0.9);
	else if (keycode == 111)  // tecla O (zoom out)
		zoom(mlx->values, 1.1);
	else if (keycode == 99) // tecla 'C'
	{
		mlx->values->palette++;
		if (mlx->values->palette > 2)
			mlx->values->palette = 0;
	}
    // Redesenhar a tela com os novos limites
    render_fractal(mlx);
    return (0);
}

int	update_animation(t_mlx *mlx)
{
	mlx->values->color_offset += 1;
	if (mlx->values->color_offset > 255)
		mlx->values->color_offset = 0;
	render_fractal(mlx);
	return (0);
}




