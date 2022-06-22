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

void __put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	char *dst;

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

int main(int ac, char **av)
{
	t_program_data *data;
	
	if (!(ac == 2) || (!av[1]))
		return (-2);
	if (!__parsing(&av[1]))
		return (-3);
	data = malloc(sizeof(t_program_data));
	if (!__init_program_data(data, &av[1]))
		return (printf("ERROR_MALLOC\n"), -2);
	// __print_line_to_image(data->fdf, 1920, 0, 0, 0);
	// mlx_put_image_to_window(data->fdf->mlx, data->fdf->win, data->fdf->img.new_img, 0, 0);

	// t_3d **map;
	t_map_data data_map;

	data_map = __init_map_data(data->fd);
	printf("%d , %d\n", data_map.x_size, data_map.y_size);
	// map = __init_3d_grid(&data_map);
	// print_points(map, data_map);
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