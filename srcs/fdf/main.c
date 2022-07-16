/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:05:41 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/16 20:22:16 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	__mlx_loop(t_program_data *data)
{
	mlx_hook(data->fdf->win, 17, 1L << 0, autre_fonction, data);
	mlx_hook(data->fdf->win, 2, ESC, close_win, data);
	mlx_loop(data->fdf->mlx);
	mlx_destroy_image(data->fdf->mlx, data->fdf->img.new_img);
	mlx_destroy_window(data->fdf->mlx, data->fdf->win);
	mlx_destroy_display(data->fdf->mlx);
	free(data->fdf->mlx);
	__clean(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_program_data	*data;

	if (!(ac == 2) || (!av[1]))
		return (-2);
	if (!__parsing(&av[1]))
		return (-3);
	data = (t_program_data *)malloc(sizeof(t_program_data));
	if (!__init_program_data(data, av[1]))
		return (printf("ERROR_MALLOC\n"), -4);
	if (!__line_mapping(data->final_map, data->map_data, data->fdf))
		return (-5);
	if (!__put_image_to_window(data))
		return (-6);
	if (!__mlx_loop(data))
		return (-7);
	return (0);
}
