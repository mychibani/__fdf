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


int	__mlx_loop(t_program_data *data)
{
	printf("%d\n", mlx_hook(data->fdf->win, 2, ESC, __mlx_event, data));
	mlx_loop(data->fdf->mlx);
	mlx_destroy_image(data->fdf->mlx, data->fdf->img.new_img);
	mlx_destroy_window(data->fdf->mlx, data->fdf->win);
	mlx_destroy_display(data->fdf->mlx);
	free(data->fdf->mlx);
	__clean(data);
	return (1);
}


void	__print_line_to_image(t_fdf *fdf, int x1, int y1, int x2, int y2, unsigned int color)
{
	int	dx;
	int	sx;
	int	sy;
	int	dy;
	int	err;
	int e2;


	dx = (int)float_abs(x2 - x1);
	dy = -(int)float_abs(y2 - y1);
	sx = int_trn((x2 > x1), 1, -1);
	sy = int_trn((y2 > y1), 1, -1);
	err = dx + dy;
	while (x1 != x2 && y1 != y2)
	{
		__put_pixel_on_img(fdf, x1, y1, color);
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

t_2d	**isometric_projection(t_3d **grid, t_map_data *data)
{
	t_2d	**final_grid;
	int		i;
	int		j;

	i = 0;
	final_grid = (t_2d **)malloc(sizeof(t_2d *) * data->y_size);
	while (i < data->y_size)
	{
		j = 0;
		final_grid[i] = (t_2d *)malloc(sizeof(t_2d) * data->x_size);
		while (j < data->x_size)
		{
			final_grid[i][j].x = (grid[i][j].x - grid[i][j].y) * cos(0.6);
			final_grid[i][j].y = (grid[i][j].x + grid[i][j].y) * sin(0.6) - grid[i][j].z;
			if (grid[i][j].z > 0)
				final_grid[i][j].color = 0xFFFF0000;
			else
				final_grid[i][j].color = 0xFFFFFFFF;
			j++;
		}
		free(grid[i]);
		i++;
	}
	free(grid);
	return (final_grid);
}

void	__get_min_max_in_tab(t_3d **grid, t_map_data *data, int *min, int *max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*min = _INT_MAX_;
	*max = _INT_MIN_;
	while (j < data->y_size)
	{
		while (i < data->x_size)
		{
			if (grid[j][i].z < *min)
				*min = grid[j][i].z;
			if (grid[j][i].z > *max)
				*max = grid[j][i].z;
			i++;
		}
		i = 0;
		j++;
	}
}

int	__put_image_to_window(t_program_data *data)
{
	mlx_put_image_to_window(data->fdf->mlx, data->fdf->win, data->fdf->img.new_img, 0, 0);
	return (_SUCCESS_);
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
		return (printf("ERROR_MALLOC\n"), -4);
	if (!__line_mapping(data->final_map, data->map_data, data->fdf))
		return (-5);
	if (!__put_image_to_window(data))
		return (-6);
	if (!__mlx_loop(data))
		return (-7);
	return (0);
}