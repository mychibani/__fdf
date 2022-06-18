/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:05:41 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/16 15:21:50by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void __put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	char *dst;

	dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	__mlx_loop(t_program_data *data)
{
	mlx_hook(data->fdf->win, 2, 17, __mlx_event, data);
	mlx_loop(data->fdf->mlx);
	mlx_destroy_image(data->fdf->mlx, data->fdf->img.new_img);
	mlx_destroy_window(data->fdf->mlx, data->fdf->win);
	mlx_destroy_display(data->fdf->mlx);
	free(data->fdf->mlx);
	__clean(data);
	return (1);
}

int main(int ac, char **av)
{
	t_program_data *data;
	
	if (!(ac == 2) || (!av[1]))
		return (-2);
	if (!__parsing(&av[1]))
		return (-3);
	data = malloc(sizeof(t_program_data));
	if (!__init_program_data(data, &av[1]))
		return (printf("ERROR_MALLOC\n"), -2);
	// if (!__mapping(data))
	// 	return (ERR_MAP, 2);
	// if (!hooks(data))
	// return (ERR_HOOKS, 2);

	/**********
	 * LOOP *
	***********/

	if (!__mlx_loop(data))
		return (3);
	return (0);
}