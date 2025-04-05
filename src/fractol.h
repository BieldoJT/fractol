#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libraries/Libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 600
# define HEIGHT 800


# define ESCAPE 65307


typedef struct s_fractol_values
{
	double a_min;
	double a_max;
	double b_min;
	double b_max;
	double move_step;
	double real;
	double imag;
	int max_iter;
}	t_fractol_values;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_fractol_values *values;
}	t_mlx;





void	init_mlx(t_mlx *mlx);
void	init_values(t_fractol_values *values);

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

int	color_by_iterations(int n, int max_iter);
void render_fractal(t_mlx *mlx);

int	destroy(t_mlx *mlx);
int my_key_func(int keycode, t_mlx *mlx);


void	zoom(t_fractol_values *v, double factor);
int	mouse_zoom(int button, int x, int y, t_mlx *mlx);


#endif
