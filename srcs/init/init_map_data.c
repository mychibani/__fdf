/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:00:57 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/18 10:47:24 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_data	*__init_map_data(int fd, char *file_name)
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
	map->file_name = file_name;
	map->tot_size = map->x_size * map->y_size;
	map->zoom = fmin(SCREEN_WIDTH / map->x_size / 1.5,
			SCREEN_HEIGHT / map->y_size / 1.5);
	map->scaling = SCALING;
	if (map->x_size < 0 || map->y_size < 0)
		return (NULL);
	return (map);
}
