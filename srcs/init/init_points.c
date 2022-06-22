/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:25:41 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/17 15:30:03by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int __get_y_size(int fd)
{
	char *str;
	int y;

	y = 0;
	str = __gnl(fd);
	if (!str)
		return (-1);
	while (str)
	{
		if (str)
			y++;
		free(str);
		str = __gnl(fd);
	}
	close(fd);
	return (free(str), y);
}

int __get_x_size(char *str)
{
	int x;
	int i;
	int len;

	i = 0;
	x = 0;
	if (!str)
		return (-1);
	len = ft_strlen(str);
	while (i < len - 1)
	{
		while (str[i] == ' ')
			i++;
		x++;
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (!(str[i] == ' ' || str[i] == '\n' || !str[i]))
			return (_ERROR_);
		i++;
	}
	return (x);
}


t_map_data __init_map_data(int fd)
{
	char		*str;
	t_map_data	data;

	data.y_size = __get_y_size(fd);
	printf("%d\n", fd);
	str = __gnl(fd);
	data.x_size = __get_x_size(str);
	free(str);
	close(fd);
	return (data);
}

// void	init_point_struct(t_3d *grid, int x, int y, int z)
// {	
// 	grid[x][y].x = x;
// 	grid[x][y].y = y;
// 	grid[x][y].z = z;
// 	// grid[x][y].color = __get_gradient(z);
// }

t_3d	*__init_line_struct(t_map_data data, char *str, int y)
{
	t_3d	*grid_line;
	int		i;
	int		x;
	int		index;

	index = 0;
	grid_line = (t_3d *)malloc(sizeof(t_3d) * (__get_x_size(str)));
	if (!grid_line)
		return (NULL);
	while (str[i] && x < data.x_size)
	{
		while (str[i] == ' ')
			i++;
		grid_line[index].x = x;
		grid_line[index].y = y;
		grid_line[index].z = ft_atoi(&str[i]);
		index++;
		// grid_line[index].color = __get_gradient(&str[i]);
		while (ft_isdigit(str[i]))
			i++;
		x++;
	}
	if (x < data.x_size)
		return (NULL);
	free(str);
	return (grid_line);
}

t_3d	**__init_3d_grid(t_map_data *data)
{
	t_map_data	map_data;
	t_3d		**grid;
	char		*str;
	int			y;

	y = 0;
	map_data = __init_map_data(data->fd);
	grid = (t_3d **)malloc(sizeof(t_3d *) * map_data.y_size);
	if (!grid)
		return (NULL);
	while (y < map_data.y_size)
	{
		str = __gnl(data->fd);
		grid[y] = __init_line_struct(map_data, str, y);
		y++;	
	}
	close(data->fd);
	return (grid);
}