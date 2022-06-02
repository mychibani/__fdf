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

int 	__get_y_size(int fd)
{
 	char	*str;
	int		y;

	y = 0;
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
	close(fd);
 	return (free(str), y);
}

int		__get_x_size(char *str)
{
	int	x;
	int	i;
	int	len;

	i = 0;
	x = 0;
	if (!str)
		return (0);
	len = ft_strlen(str);
	while (i < len)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		if (ft_isdigit(str[i]))
		{
			x++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			return (_ERROR_);
		i++;
	}
	return (free(str), x);
}

int	is_equally_correct(int fd)
{
    int		line_size;
    char	*str;

    str = __gnl(fd);
    line_size = __get_x_size(str);
    while (str)
    {
        str = __gnl(fd);
        if (line_size < __get_x_size(str) && str)
            return (-1);
    }
	return (1);
}

void	init_point(t_3dpoint *file_points, int x, int y, int z)
{
	file_points->x = x;
	file_points->y = y;
	file_points->z = z;
}

t_3dpoint *init_3d_points(int fd, int *size)
{
	t_3dpoint	*file_points;
	char		*str;
	int			i;
	int			max_len;
	int			index;
	int			x;
	int			y;

	x = 0;
	y = 0;
	i = 0;
	index = 0;
	str = __gnl(fd);
	max_len = __get_x_size(str);
	*size = __get_x_size(str) * __get_y_size(fd);
	file_points = (t_3dpoint *)malloc(sizeof(t_3dpoint) * (*size));
	if (!file_points)
		return (free(str), NULL);
	while (str)
	{
		while (i < max_len)
		{
			while (str[i] == ' ')
				i++;
			init_point(&file_points[index++], x, y, ft_atoi(str + i));
			while (ft_isdigit(str[i]))
				i++;
			i++;
			x++;
		}
		free(str);
		str = __gnl(fd);
		x = 0;
		y++;
	}
	return (free(str), file_points);
}

void	ft_print_3d_tab(t_3dpoint *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("x = [%d]\n", tab->x);
		ft_printf("y = [%d]\n", tab->y);
		ft_printf("z = [%d]\n", tab->z);
		i++;
	}
}

int main(int ac, char **av)
{
	t_3dpoint *tab;
	(void)ac;
	int fd;
	int	size;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("can't open file\n", 2), 2);
	tab = init_3d_points(fd, &size);
	ft_printf("%d\n", size);
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
