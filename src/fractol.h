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
# include <math.h>

# define WIDTH 600
# define HEIGHT 800


# define ESCAPE 65307


typedef struct s_fractol_values
{
	int		fractal_type; // 0 = mandelbrot, 1 = julia
	double	c_real;       // usado para Julia
	double	c_imag;
	double	a_min;
	double	a_max;
	double	b_min;
	double	b_max;
	double	real;
	double	imag;
	int		max_iter;
	int		color_offset;
	int		palette;

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

int	color_by_iterations(int n, int max_iter, int offset, int palette);
void render_fractal(t_mlx *mlx);

int	destroy(t_mlx *mlx);
int my_key_func(int keycode, t_mlx *mlx);
int	update_animation(t_mlx *mlx);


void	zoom(t_fractol_values *v, double factor);

int	julia(t_mlx *mlx);


#endif
