/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:05:41 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/16 15:21:50by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void __put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x > 1929 || y < 0 || y > 1080)
		return ;
	dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	__mlx_loop(t_program_data *data)
{
	mlx_hook(data->fdf->win, 2, 17, __mlx_event, data);
	mlx_loop(data->fdf->mlx);
	mlx_destroy_image(data->fdf->mlx, data->fdf->img.new_img);
	mlx_destroy_window(data->fdf->mlx, data->fdf->win);
	mlx_destroy_display(data->fdf->mlx);
	free(data->fdf->mlx);
	__clean(data);
	return (1);
}

int	__int_trn(int condition, int success, int failure)
{
	if (condition)
		return (success);
	return (failure);
}

int	__abs(int x)
{
	return (__int_trn((x < 0), -x, x));
}

void	__print_line_to_image(t_fdf *fdf, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	sx;
	int	sy;
	int	dy;
	int	err;
	int e2;

	dx = __abs(x2 - x1);
	dy = -__abs(y2 - y1);
	sx = __int_trn((x2 > x1), 1, -1);
	sy = __int_trn((y2 > y1), 1, -1);
	err = dx + dy;
	while (1)
	{
		__put_pixel_on_img(fdf, x1, y1, 0x00FF0000);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dy)
		{
			err += dx;
			y1 += sy;
		}
	}
}

#define	D_ANGLE M_PI / 8
t_2d	**parrallel_projection(t_3d **grid, t_map_data *data)
{
	t_2d	**final_grid;
	int		i;
	int		j;

	i = 0;
	printf("%d %d\n", data->x_size, data->y_size);
	final_grid = (t_2d **)malloc(sizeof(t_2d *) * data->y_size);
	while (i < data->y_size)
	{
		j = 0;
		final_grid[i] = (t_2d *)malloc(sizeof(t_2d) * data->x_size);
		while (j < data->x_size)
		{
			// final_grid[i][j].x = grid[i][j].x + cos(1.15) * grid[i][j].z - cos(1) * grid[i][j].y;
			// final_grid[i][j].y = -grid[i][j].y * sin(2.7) - grid[i][j].z * sin(2);
			// final_grid[i][j].x = (grid[i][j].x + cos(D_ANGLE) * grid[i][j].z - cos(D_ANGLE) * grid[i][j].y) * -1;
			// final_grid[i][j].y = (-grid[i][j].y * sin(D_ANGLE) - grid[i][j].z * sin(D_ANGLE));
			final_grid[i][j].x = (grid[i][j].x - grid[i][j].y) * cos(0.46346716);
			final_grid[i][j].y = (grid[i][j].x + grid[i][j].y) * sin(0.46346716) - grid[i][j].z;
			j++;
		}
		i++;
	}
	printf("%d\n", final_grid[0][0].x);
	printf("%d\n", final_grid[0][0].y);
	// free(grid);
	return (final_grid);
}

void	__line_mapping(t_2d **grid, t_map_data *data, t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->y_size)
	{
		x = 0;
		while (x < data->x_size)
		{
			if (x != data->x_size - 1)
				__print_line_to_image(fdf, grid[y][x].x, grid[y][x].y, grid[y][x + 1].x, grid[y][x + 1].y);
			if (y != data->y_size - 1)
				__print_line_to_image(fdf, grid[y][x].x, grid[y][x].y, grid[y + 1][x].x, grid[y + 1][x].y);
			x++;
		}
		y++;
	}
}

int main(int ac, char **av)
{
	t_program_data *data;
	
	if (!(ac == 2) || (!av[1]))
		return (-2);
	if (!__parsing(&av[1]))
		return (-3);
	data = (t_program_data *)malloc(sizeof(t_program_data));
	if (!__init_program_data(data, av[1]))
		return (printf("ERROR_MALLOC\n"), -2);
	
	__line_mapping(data->final_map, data->map_data, data->fdf);
	mlx_put_image_to_window(data->fdf->mlx, data->fdf->win, data->fdf->img.new_img, 0, 0);
	// if (!__mapping(data))
		// return (ERR_MAP, 2);
	// if (!hooks(data))
	// return (ERR_HOOKS, 2);

	/**********
	 * LOOP *
	***********/

	if (!__mlx_loop(data))
		return (3);
	return (0);
}