/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:13:44 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/20 13:05:14 by ychibani         ###   ########.fr       */
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

void	print_points(t_3d *points)
{
	printf("%d\n", points->x);
	printf("%d\n", points->y);
	printf("%d\n", points->z);
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
	print_points(data->grid);
}