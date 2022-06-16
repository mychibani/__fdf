#include "fdf.h"

void	__put_pixel_on_img(t_fdf *fdf, int x, int y, int color, float brightness);


// typedef struct s_line
// {
// 	int		x;
// 	int		steep;
// 	float	dx;
// 	float	dy;
// 	double	gradient;
// };

/*typedef struct
	x0;
	x1;
	y0;
	y1;
*/

void	wu_calc_line(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	int		x;
	int		steep;
	int		x_temp1;
	int		x_temp2;
	float	dx;
	float	dy;
	float	intersecty;
	double	gradient;
	// t_line	data_line;

	steep = float_abs(y1 - y0) > float_abs(x1 - x0);
	ft_printf("%d\n", steep);
	if (steep)
	{
		__swap(&x0 , &y0);
		__swap(&x1 , &y1);
	}
	if (x0 > x1)
	{
		__swap(&x0 ,&x1);
		__swap(&y0 ,&y1);
	}
	// init_line_coordonate(x0, x1, dx, dy, gradient, intersecty);
	// init_line_coordonate(&data_line);
	dx = x1 - x0;
	dy = y1 - y0;
	gradient = dy / dx;
	x_temp1 = x0;
	x_temp2 = x1;
	intersecty = y0;
	if (steep)
	{
		x = x_temp1;
		while (x <= x_temp2)
		{
			__put_pixel_on_img(fdf, integer_part(intersecty), x, 0xFFFFFF , minus_fractional_part(intersecty));
			__put_pixel_on_img(fdf, integer_part(intersecty) - 1, x, 255, fractional_part(intersecty));
			intersecty += gradient;
			x++;
		}
	}
	else
	{
		x = x_temp1;
		while (x <= x_temp2)
		{
			__put_pixel_on_img(fdf, x, integer_part(intersecty) , 255, minus_fractional_part(intersecty));
			__put_pixel_on_img(fdf, x, integer_part(intersecty) - 1 , 0xFFFFFF, minus_fractional_part(intersecty));
			intersecty += gradient;
			x++;
		}
	}
}

// #include "fdf.h"
// #include <stdint.h>
// #include <stdio.h>

// // Prints the binary representation of any unsigned integer
// // When running, pass 1 to first_call
// void printf_binary(unsigned int number, int first_call)
// {
//         if (first_call)
//         {
//                 printf("The binary representation of %d is [", number);
//         }
//         if (number >> 1)
//         {
//                 printf_binary(number >> 1, 0);
//                 putc((number & 1) ? '1' : '0', stdout);
//         }
//         else 
//         {
//                 putc((number & 1) ? '1' : '0', stdout);
//         }
//         if (first_call)
//         {
//                 printf("]\n");
//         }
// }

// int	color(int t, int r, int g, int b)
// {
// 	__int32_t color;

// 	color = 0;
// 	color = color | t << 24;
// 	color = color | r << 16;
// 	color = color | g << 8;
// 	color = color | b << 0;
// 	return (color);
// }

// int main(int ac, char **av)
// {
// 	printf_binary(color(1, 255, 255, 12), 1);

// }