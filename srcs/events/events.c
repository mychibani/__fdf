/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:29:34 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/16 19:26:03 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(int key_hook, t_program_data *data)
{
	if (key_hook == ESC)
	{
		mlx_destroy_image(data->fdf->mlx, data->fdf->img.new_img);
		mlx_destroy_window(data->fdf->mlx, data->fdf->win);
		mlx_destroy_display(data->fdf->mlx);
		free(data->fdf->mlx);
		__clean(data);
		exit(0);
	}
	return (12);
}

int	autre_fonction(t_program_data *data)
{	
	mlx_destroy_image(data->fdf->mlx, data->fdf->img.new_img);
	mlx_destroy_window(data->fdf->mlx, data->fdf->win);
	mlx_destroy_display(data->fdf->mlx);
	free(data->fdf->mlx);
	__clean(data);
	exit(0);
}
