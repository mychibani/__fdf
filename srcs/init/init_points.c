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


t_map_data *__init_map_data(int fd, char *file_name)
{
	char		*str;
	t_map_data	*map;

	map = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map)
		return (NULL);
	map->y_size = __get_y_size(fd);
	map->fd = open(file_name, O_RDONLY);
	str = __gnl(map->fd);
	map->x_size = __get_x_size(str);
	free(str);
	close(map->fd);
	map->fd = open(file_name, O_RDONLY);
	if (map->x_size < 0 || map->y_size < 0)
		return (NULL);
	return (map);
}

void	__init_3d_line_struct(t_3d *grid_line, int x, int y, int z)
{
	grid_line->x = x * 50 + SCREEN_WIDTH / 3;
	grid_line->y = y * 50 - 300;
	grid_line->z = z * (30 / 7);
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
	if (__get_x_size(str) < 0)
		return (NULL);
	grid_line = (t_3d *)malloc(sizeof(t_3d) * (__get_x_size(str)));
	if (!grid_line)
		return (NULL);
	while (i < len - 1 && x < data->x_size)
	{
		while (str[i] == ' ')
			i++;
		__init_3d_line_struct(&grid_line[index], x, y, ft_atoi(&str[i]));
		index++;
		while (ft_isdigit(str[i]) || str[i] == '-')
			i++;
		x++;
	}
	if (x < data->x_size)
		return (NULL);
	return (grid_line);
}

t_3d	**__init_3d_grid(t_map_data *map_data)
{
	t_3d		**grid;
	char		*str;
	int			y;
	int			size;

	y = 0;
	size = map_data->y_size;
	if (size < 0)
		return (NULL);
	grid = (t_3d **)malloc(sizeof(t_3d *) * map_data->y_size);
	if (!grid)
		return (NULL);
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