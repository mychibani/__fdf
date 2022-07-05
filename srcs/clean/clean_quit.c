/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:06:13 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/28 20:53:50by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__clean_grid(t_2d **grid, t_map_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->y_size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	__clean(t_program_data *data)
{
	if (data->fdf)
		free(data->fdf);
	if (data->final_map)
		__clean_grid(data->final_map, data->map_data);
	if (data->map_data)
		free(data->map_data);
	if (data)
		free(data);
}