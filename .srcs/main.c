/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:08:54 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/14 11:45:06 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	wu_calc_line(int x0, int y0, int x1, int y1, t_fdf *fdf);

int __get_y_size(int fd)
{
	char *str;
	int y;

	y = 1;
	str = __gnl(fd);
	if (!str)
		return (-1);
	while (str)
	{
		if (str)
			y++;
		free(str);
		str = __gnl(fd);
	}
	return (free(str), y);
}

int __get_x_size(char *str)
{
	int x;
	int i;
	int len;

	i = 0;
	x = 0;
	if (!str)
		return (0);
	len = ft_strlen(str);
	while (i < len - 1)
	{
		while (str[i] == ' ')
			i++;
		x++;
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (!(str[i] == ' ' || str[i] == '\n' || !str[i]))
			return (_ERROR_);
		i++;
	}
	return (x);
}

t_3d init_point(t_3d file_points, int *x, int *y, int z)
{
	file_points.x = *x;
	file_points.y = *y;
	file_points.z = z;
	return (file_points);
}

t_3d *init_3d_points(int fd, int *size, char *av)
{
	t_3d		*file_points;
	char		*str;
	int			i;
	int			x_len;
	int			y_len;
	int			index;
	int			x;
	int			y;

	x = 0;
	y = 0;
	i = 0;
	str = __gnl(fd);
	y_len = __get_y_size(fd);
	x_len = __get_x_size(str);
	close(fd);
	fd = open(av, O_RDONLY);
	index = 0;
	*size = x_len * y_len;
	file_points = (t_3d *)malloc(sizeof(t_3d) * (*size));
	if (!file_points)
		return (free(str), NULL);
	while (y < y_len && str)
	{
		free(str);
		str = __gnl(fd);
		i = 0;
		x = 0;
		while ((x < x_len) && str[i])
		{
			while (str[i] == ' ')
				i++;
			file_points[index] = init_point(file_points[index], &x, &y, ft_atoi(&str[i]));
			index++;
			while (ft_isdigit(str[i]) || str[i] == '-')
				i++;
			x++;
		}
		y++;
	}
	return (free(str), file_points);
}

void	__mlx_cleaner(t_fdf *fdf)
{
	if (fdf->mlx)
		free(fdf->mlx);
	if (fdf->win)
		free(fdf->win);
	if (fdf->img.new_img)
		free(fdf->img.new_img);
}

void	__put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}



t_fdf *init(void)
{
	t_fdf *fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FDF");
	if (!fdf->win)
		return (__mlx_cleaner(fdf), NULL);
	fdf->img.new_img = mlx_new_image(fdf->mlx, 1920, 1080);
	if (!fdf->img.new_img)
		return (__mlx_cleaner(fdf), NULL);
	fdf->img.addr = mlx_get_data_addr(fdf->img.new_img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	if (!fdf->img.addr)
		return (__mlx_cleaner(fdf), NULL);
	return (fdf);
}

int	__close_window(void)
{
	exit(1);
}

__uint32_t	__colorful_pixel(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b << 0);
}

int main(void)
{
	t_fdf	*fdf;
	// __uint32_t		color;

	// color = __colorful_pixel(-255, 0, 255, 255);
	fdf = init();
	// if (!parsing(ac, av))
	// 	return (_ERROR_, 2);
	// if (!fdf(fdf))
	// 	return (_ERROR_, 2);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.new_img, 0, 0);
	
	wu_calc_line(0, 100, 200, 400, fdf);
	wu_calc_line(0, 100, 200, 400, fdf);
	mlx_hook(fdf->win, 33, 1L<<0, __close_window, NULL);
	mlx_loop(fdf->mlx);
	__mlx_cleaner(fdf);
	mlx_destroy_image(fdf->mlx, fdf->img.new_img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
}
