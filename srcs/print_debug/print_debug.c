/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:13:44 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/22 23:25:38 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_key(t_key *key)
{
	printf("%d\n", key->key_hook);
}

void	print_cam(t_cam *cam)
{
	printf("%d\n", cam->pov);
}

void	print_line(t_line *line)
{
	printf("%d\n", line->x0);
	printf("%d\n", line->x1);
	printf("%d\n", line->y0);
	printf("%d\n", line->y1);
}

void	print_points(t_3d **points, t_map_data map_data)
{
	int	i;
	int j;
	
	i = 0;
	j = 0;
	while (i < map_data.y_size)
	{
		while (j < map_data.x_size)
		{
			printf("%d\t", points[i][j].x);
			printf("%d\t", points[i][j].y);
			printf("%d\t", points[i][j].z);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

void print_fdf(t_fdf *fdf)
{
	printf("mlx = %p\n", fdf->mlx);
	printf("win = %p\n", fdf->win);
	printf("img = %p\n", fdf->img.new_img);
	printf("img addr = %p\n", fdf->img.addr);
	printf("bits per pixel = %d\n", fdf->img.bits_per_pixel);
	printf("line lenght = %d\n", fdf->img.line_length);
	printf("endian = %d\n", fdf->img.endian);
}

void	print_data(t_program_data *data)
{
	printf("data->fd = %d\n", data->fd);
	print_fdf(data->fdf);
	print_key(data->key);
	print_cam(data->cam);
	print_line(data->line);
}