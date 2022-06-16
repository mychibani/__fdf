/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:05:41 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/16 15:21:50 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void __put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	char *dst;

	dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void print_data(t_fdf *fdf)
{
	printf("mlx = %p\n", fdf->mlx);
	printf("win = %p\n", fdf->win);
	printf("img = %p\n", fdf->img.new_img);
	printf("img addr = %p\n", fdf->img.addr);
	printf("bits per pixel = %d\n", fdf->img.bits_per_pixel);
	printf("line lenght = %d\n", fdf->img.line_length);
	printf("endian = %d\n", fdf->img.endian);
}

t_fdf	*__mlx_init(void)
{	
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
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

int	__mlx_loop(t_program_data *data)
{
	mlx_hook(data->fdf->win, 2, 17, __mlx_event, &data->fdf);
	mlx_loop(data->fdf->mlx);
	mlx_destroy_image(data->fdf->mlx, data->fdf->img.new_img);
	mlx_destroy_window(data->fdf->mlx, data->fdf->win);
	mlx_destroy_display(data->fdf->mlx);
	free(data->fdf->mlx);
	return (1);
}

void	__clean(t_program_data *data)
{
	if (data->fdf)
		free(data->fdf);
	if (data->cam)
		free(data->cam);
	if (data->line)
		free(data->line);
	if (data->key)
		free(data->key);
	if (data)
		free(data);
}

t_program_data	*__init_program_data(void)
{
	t_program_data	*data;
	t_fdf			*fdf;
	t_key			*key;
	t_cam			*cam;
	t_line			*line;

	data = (t_program_data *)ft_calloc(1, sizeof(t_program_data));
	key = (t_key *)malloc(sizeof(t_key));
	cam = (t_cam *)malloc(sizeof(t_cam));
	line = (t_line *)malloc(sizeof(t_line));
	fdf = __mlx_init();
	data->key = key;
	data->cam = cam;
	data->line = line;
	data->fdf = fdf;
	if (!data || !key || !cam || !line || !fdf)
		return (__clean(data), NULL);
	return (data);
}

int main(int ac, char **av)
{
	t_program_data	*data;
	
	if (!(ac == 2) || (!av[1]))
		return (2);
	data = __init_program_data();
	if (!data)
		return (printf("12132312\n"), 35545);
	// if (!__parsing(data))
	// 	return (ERR_PARS, 2);
	// if (!__initialization(data))
	// 	return (ERR_INIT, 2);
	// if (!__mapping(data))
	// 	return (ERR_MAP, 2);
	if (!__mlx_loop(data))
		return (3);
	return (0);
}