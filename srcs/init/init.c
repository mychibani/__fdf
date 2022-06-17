/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:45:12 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/17 14:26:36 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_program_data	*__init_program_data(void)
{
	t_program_data	*data;
	t_key			*key;
	t_cam			*cam;
	t_line			*line;
	t_fdf			*fdf;
    t_3d            *grid;

	data = (t_program_data *)ft_calloc(1, sizeof(t_program_data));
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	key = (t_key *)malloc(sizeof(t_key));
	cam = (t_cam *)malloc(sizeof(t_cam));
	line = (t_line *)malloc(sizeof(t_line));
	grid = (t_3d *)malloc(sizeof(t_3d));
	data->key = key;
	data->cam = cam;
	data->line = line;
	data->fdf = __mlx_init(fdf);
    data->grid = __init_points(fd, av[1])
	if (!data || !data->key || !data->cam || !data->line || !data->fdf || !data->grid)
		return (__clean(data), NULL);
	return (data);
}

t_program_data *__initialization(void)
{
	t_program_data	*data;

    data = __init_program_data();
    if (!data)
        return (NULL);
    // if (!init_points(data))
        // return (NULL);
    // if (!init_cam(data))
        // return (NULL);
    // if (!init_points(data))
    //     return (NULL);
    return (data);
}