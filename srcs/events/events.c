/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:29:34 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/16 14:23:44by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Les problèmes les plus difficiles à résoudre sont 
// ceux qu'on résous avec les petites choses.
// Rolf Herrold Loundou

void	__clean(t_program_data *data);

int		__mlx_event(int key_hook, t_program_data *data)
{
	if ()
		mlx_destroy_image(data->fdf->mlx, data->fdf->img.new_img);
		mlx_destroy_window(data->fdf->mlx, data->fdf->win);
		mlx_destroy_display(data->fdf->mlx);
		free(data->fdf->mlx);
		__clean(data);
		exit(0);
}