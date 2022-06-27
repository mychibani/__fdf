/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:45:12 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/27 11:17:50 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool __init_program_data(t_program_data *data, char *file_name)
{
	int		fd;


	fd = open(file_name, O_RDONLY);
	data->map_data = __init_map_data(fd, file_name);
	data->fdf = __mlx_init();
	data->fd = fd;
	data->grid = __init_3d_grid(data->map_data);
	data->final_map = parrallel_projection(data->grid, data->map_data);
	data->file_name = file_name;
	if (!data || !data->fdf || !data->map_data)
		return (__clean(data), 0);
	return (1);
}