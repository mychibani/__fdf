/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:45:12 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/17 22:33:15 by ychibani         ###   ########.fr       */
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

	data = (t_program_data *)ft_calloc(1, sizeof(t_program_data));
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	key = (t_key *)malloc(sizeof(t_key));
	cam = (t_cam *)malloc(sizeof(t_cam));
	line = (t_line *)malloc(sizeof(t_line));
	data->key = key;
	data->cam = cam;
	data->line = line;
	data->fdf = __mlx_init(fdf);
	if (!data || !data->key || !data->cam || !data->line || !data->fdf)
		return (__clean(data), NULL);
	return (data);
}

int	__initialization(t_program_data *data, char **av)
{

    data = __init_program_data();
	if (!data)
		return (-1);
	data->fd = open(*av, O_RDONLY);
    // if (!init_points(data))
        // return (NULL);
    // if (!init_cam(data))
        // return (NULL);
    // if (!init_points(data))
    //     return (NULL);
    return (_SUCCESS_);
}