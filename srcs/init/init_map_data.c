/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:00:57 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/11 13:56:07 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	zoom(int x, int y, t_map_data *data)
// {
// 	int lenght

// 	lenght = x * y;

// 	while (lenght > SCREEN_HEIGHT * SCREEN_WIDTH)
// 	{
// 		lenght = x * y;
// 		x--;
// 		y--;
// 	}
// 	data->zoom = lenght;
// }


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
	// zoom(map->x_size, map->y_size, map);
	map->fd = open(file_name, O_RDONLY);
	map->file_name = file_name;
	if (map->x_size < 0 || map->y_size < 0)
		return (NULL);
	return (map);
}