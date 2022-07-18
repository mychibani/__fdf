/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:15:20 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/18 12:49:19 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)
		return ;
	dst = fdf->img.addr + (y * fdf->img.line_length
			+ x * (fdf->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	right_line(t_line *line, t_2d **grid, int x, int y)
{
	line->x0 = grid[y][x].x;
	line->x1 = grid[y][x + 1].x;
	line->y0 = grid[y][x].y;
	line->y1 = grid[y][x + 1].y;
	line->color = grid[y][x].color;
}

void	bottom_line(t_line *line, t_2d **grid, int x, int y)
{
	line->x0 = grid[y][x].x;
	line->x1 = grid[y + 1][x].x;
	line->y0 = grid[y][x].y;
	line->y1 = grid[y + 1][x].y;
	line->color = grid[y][x].color;
}

int	__line_mapping(t_2d **grid, t_map_data *data, t_fdf *fdf)
{
	int		x;
	int		y;
	t_line	line;

	x = -1;
	y = -1;
	while (++y < data->y_size)
	{
		x = -1;
		while (++x < data->x_size)
		{
			if (x != data->x_size - 1)
			{
				right_line(&line, grid, x, y);
				__print_line_to_image(fdf, &line);
			}
			if (y != data->y_size - 1)
			{
				bottom_line(&line, grid, x, y);
				__print_line_to_image(fdf, &line);
			}
		}
	}
	return (_SUCCESS_);
}
