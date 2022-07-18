/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:20:40 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/18 10:27:41 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	__put_image_to_window(t_program_data *data)
{
	mlx_put_image_to_window(data->fdf->mlx, data->fdf->win,
		data->fdf->img.new_img, 0, 0);
	return (_SUCCESS_);
}

int	init_x(t_map_data *data, int x, int y)
{
	return ((data->zoom * x - data->zoom * y)
		* cos(0.6) + SCREEN_WIDTH / 2);
}

int	init_y(t_map_data *data, int x, int y, int z)
{
	return ((data->zoom * x + data->zoom * y)
		* sin(0.6) - (data->zoom / data->scaling) * z + SCREEN_HEIGHT / 2);
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
			final_grid[i][j].x = init_x(data, grid[i][j].x, grid[i][j].y);
			final_grid[i][j].y = init_y(data, grid[i][j].x, grid[i][j].y,
					grid[i][j].z);
			final_grid[i][j].color = grid[i][j].color;
			j++;
		}
		free(grid[i]);
		i++;
	}
	free(grid);
	return (final_grid);
}
