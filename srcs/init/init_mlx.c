/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:48:00 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/16 20:31:32 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	__mlx_destroy_win(t_fdf *fdf)
{
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
}

static void	__mlx_destroy_img(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
}

t_fdf	*__mlx_init(void)
{	
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (free(fdf), NULL);
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "fdf");
	if (!fdf->win)
		return (__mlx_destroy_win(fdf), NULL);
	fdf->img.new_img = mlx_new_image(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!fdf->img.new_img)
		return (__mlx_destroy_img(fdf), NULL);
	fdf->img.addr = mlx_get_data_addr(fdf->img.new_img,
			&fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	return (fdf);
}
