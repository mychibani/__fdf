/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:25:41 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/16 20:35:45 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__init_3d_line_struct(t_3d *grid_line, int x, int y, int z)
{
	grid_line->x = x;
	grid_line->y = y;
	grid_line->z = z;
	if (z)
		grid_line->color = 0xFFFF0000;
	else
		grid_line->color = 0xFFFFFFFF;
}

t_3d	*__init_line_struct(t_map_data *data, char *str, int y)
{
	t_3d	*grid_line;
	int		len;
	int		i;
	int		x;
	int		index;

	index = 0;
	i = 0;
	x = 0;
	len = ft_strlen(str);
	grid_line = (t_3d *)malloc(sizeof(t_3d) * (__get_x_size(str)));
	if (!grid_line)
		return (NULL);
	while (i < len - 1 && x < data->x_size)
	{
		while (str[i] == ' ')
			i++;
		__init_3d_line_struct(&grid_line[index], (x - data->x_size / 2),
			(y - data->y_size / 2), ft_atoi(&str[i]));
		index++;
		while (str[i] != ' ' && str[i])
			i++;
		x++;
	}
	return (grid_line);
}

t_3d	**__init_3d_grid(t_map_data *map_data)
{
	t_3d		**grid;
	char		*str;
	int			y;
	int			temp;

	y = 0;
	temp = open(map_data->file_name, O_RDONLY);
	grid = (t_3d **)malloc(sizeof(t_3d *) * map_data->y_size);
	if (!grid)
		return (NULL);
	str = __gnl(temp);
	while (str)
	{
		free(str);
		str = __gnl(temp);
	}
	while (y < map_data->y_size)
	{
		str = __gnl(map_data->fd);
		grid[y] = __init_line_struct(map_data, str, y);
		free(str);
		y++;
	}	
	close(map_data->fd);
	return (grid);
}
