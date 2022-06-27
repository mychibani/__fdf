/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:06:13 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/24 17:28:45 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__clean_grid(t_3d **grid, t_map_data *data)
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
	if (data->grid)
		__clean_grid(data->grid, data->map_data);
	if (data->map_data)
		free(data->map_data);
	if (data)
		free(data);
}