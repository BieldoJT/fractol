#include "fractol.h"

void	zoom(t_fractol_values *v, double factor)
{
	double	center_a;
	double	center_b;
	double	width;
	double	height;

	center_a = (v->a_max + v->a_min) / 2.0;
	center_b = (v->b_max + v->b_min) / 2.0;
	width = (v->a_max - v->a_min) * factor / 2.0;
	height = (v->b_max - v->b_min) * factor / 2.0;
	v->a_min = center_a - width;
	v->a_max = center_a + width;
	v->b_min = center_b - height;
	v->b_max = center_b + height;
}
