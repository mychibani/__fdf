/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:08:54 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/26 10:08:56 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int is_equally_correct(int fd)
{
	int line_size;
	int i;
	char *str;

	str = __gnl(fd);
	line_size = __get_x_size(str);
	if (line_size < 0)
		return (free(str), -1);
	free(str);
	i = 0;
	while (str)
	{
		str = __gnl(fd);
		if (!str)
			break;
		if (line_size > __get_x_size(str) && str)
			return (free(str), -1);
		free(str);
		i++;
	}
	return (free(str), 1);
}

t_3dpoint init_point(t_3dpoint file_points, int *x, int *y, int z)
{
	file_points.x = *x;
	file_points.y = *y;
	file_points.z = z;
	return (file_points);
}

t_3dpoint *init_3d_points(int fd, int *size, char *av)
{
	t_3dpoint	*file_points;
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
	file_points = (t_3dpoint *)malloc(sizeof(t_3dpoint) * (*size));
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

void ft_print_3d_tab(t_3dpoint *tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("x = [%d]\t", tab[i].x);
		ft_printf("y = [%d]\t", tab[i].y);
		ft_printf("z = [%d]\n", tab[i].z);
		ft_printf("-------------------\n");
		
		i++;
	}
}

int main(int ac, char **av)
{
	t_3dpoint *tab;
	(void)ac;
	int fd;
	int size;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("can't open file\n", 2), 2);
	tab = init_3d_points(fd, &size, av[1]);
	ft_print_3d_tab(tab, size);
	free(tab);
	close(fd);
}

// void	__mlx_cleaner(t_fdf *fdf)
// {
// 	if (fdf->mlx)
// 		free(fdf->mlx);
// 	if (fdf->win)
// 		free(fdf->win);
// 	if (fdf->img.new_img)
// 		free(fdf->img.new_img);
// }

// void	__put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// t_fdf *init(void)
// {
// 	t_fdf *fdf;

// 	fdf = (t_fdf *)malloc(sizeof(t_fdf));
// 	if (!fdf)
// 		return (NULL);
// 	fdf->mlx = mlx_init();
// 	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FDF");
// 	if (!fdf->win)
// 		return (__mlx_cleaner(fdf), NULL);
// 	fdf->img.new_img = mlx_new_image(fdf->mlx, 1920, 1080);
// 	if (!fdf->img.new_img)
// 		return (__mlx_cleaner(fdf), NULL);
// 	fdf->img.addr = mlx_get_data_addr(fdf->img.new_img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
// 	if (!fdf->img.addr)
// 		return (__mlx_cleaner(fdf), NULL);
// 	return (fdf);
// }

// int	__close_window(void)
// {
// 	exit(ONE);
// }

// int main(int ac, char **av)
// {
// 	t_fdf	*fdf;

// 	fdf = init();
// 	// if (!parsing(ac, av))
// 	// 	return (_ERROR_, 2);
// 	// if (!fdf(fdf))
// 	// 	return (_ERROR_, 2);
// 	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.new_img, 0, 0);
// 	mlx_hook(fdf->win, 33, 1L << 17, __close_window, NULL);
// 	mlx_loop(fdf->mlx);
// 	__mlx_cleaner(fdf);
// 	mlx_destroy_image(fdf->mlx, fdf->img.new_img);
// 	mlx_destroy_window(fdf->mlx, fdf->win);
// 	mlx_destroy_display(fdf->mlx);
// }
