/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:45:12 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/18 19:51:23 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool __init_program_data(t_program_data *data, char **file_name)
{
	t_cam	*cam;
	int		fd;

	fd = open(*file_name, O_RDONLY);
	cam = (t_cam *)malloc(sizeof(t_cam));
	data->cam = cam;
	data->fdf = __mlx_init();
	data->fd = fd;
	if (!data || !data->cam || !data->fdf || !data->fd)
		return (__clean(data), 0);
	return (1);
}