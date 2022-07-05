/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:15:20 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/05 14:26:45 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void __put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x > 1920 || y < 0 || y > 1080)
		return ;
	dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	__line_mapping(t_2d **grid, t_map_data *data, t_fdf *fdf)
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
				__print_line_to_image(fdf, grid[y][x].x, grid[y][x].y, grid[y][x + 1].x, grid[y][x + 1].y, grid[y][x].color);
			if (y != data->y_size - 1)
				__print_line_to_image(fdf, grid[y][x].x, grid[y][x].y, grid[y + 1][x].x, grid[y + 1][x].y, grid[y][x].color);
			x++;
		}
		y++;
	}
	return (_SUCCESS_);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}