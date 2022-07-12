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


int	__mlx_loop(t_program_data *data)
{
	mlx_hook(data->fdf->win, 17, 1L << 0, autre_fonction, data);
	mlx_loop(data->fdf->mlx);
	mlx_destroy_image(data->fdf->mlx, data->fdf->img.new_img);
	mlx_destroy_window(data->fdf->mlx, data->fdf->win);
	mlx_destroy_display(data->fdf->mlx);
	free(data->fdf->mlx);
	__clean(data);
	return (1);
}


void	__print_line_to_image(t_fdf *fdf, t_line *line)
{
	t_vars vars;

	vars.dx = (int)float_abs(line->x1 - line->x0);
	vars.dy = -(int)float_abs(line->y1 - line->y0);
	vars.sx = int_trn((line->x1 > line->x0), 1, -1);
	vars.sy = int_trn((line->y1 > line->y0), 1, -1);
	vars.err = vars.dx + vars.dy;
	print_line(line);
	while (line->x0 != line->x1 && line->y0 != line->y1)
	{
		__put_pixel_on_img(fdf, line->x0, line->y0, line->color);
		vars.e2 = 2 * vars.err;
		if (vars.e2 >= vars.dy)
		{
			vars.err += vars.dy;
			line->x0 += vars.sx;
		}
		if (vars.e2 <= vars.dy)
		{
			vars.err += vars.dx;
			line->y0 += vars.sy;
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
			data->scaling = 11.6;
			data->zoom = 50;
			final_grid[i][j].x = (data->zoom * grid[i][j].x - data->zoom * grid[i][j].y) * cos(0.6) + SCREEN_WIDTH / 2;
			final_grid[i][j].y = (data->zoom * grid[i][j].x + data->zoom * grid[i][j].y) * sin(0.6) - (data->zoom / data->scaling) * grid[i][j].z + SCREEN_HEIGHT / 2;
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