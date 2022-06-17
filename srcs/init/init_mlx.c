/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:48:00 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/17 12:48:10 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*__mlx_init(t_fdf *fdf)
{	
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (free(fdf), NULL);
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "fenetre.win");
	if (!fdf->win)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		free(fdf);
		return (NULL);
	}
	fdf->img.new_img = mlx_new_image(fdf->mlx, 1920, 1080);
	if (!fdf->img.new_img)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		free(fdf);
		return (NULL);
	}
	fdf->img.addr = mlx_get_data_addr(fdf->img.new_img, &fdf->img.bits_per_pixel, 
	&fdf->img.line_length, &fdf->img.endian);
	return (fdf);
}