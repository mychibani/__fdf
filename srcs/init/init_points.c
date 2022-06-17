/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:25:41 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/17 15:30:03by ychibani         ###   ########.fr       */
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

t_3d init_point(t_3d file_points, int x, int y, int z)
{
	file_points.x = x;
	file_points.y = y;
	file_points.z = z;
	return (file_points);
}

void    fill_with_line(t_3d *file_points, int index, int x, int y, char *str)
{
        int i;
        int x;
        
        i = 0;
		x = 0;
		while ((x < x_len) && str[i])
		{
			while (str[i] == ' ')
				i++;
			file_points[index] = init_point(file_points[index], x, y, ft_atoi(&str[i]));
			index++;
			while (ft_isdigit(str[i]) || str[i] == '-')
				i++;
			x++;
		}
}

t_3d *init_3d_points(int fd, char *av)
{
	t_3d		*file_points;
	char		*str;
	int			i;
	int			x_len;
	int			y_len;
	int			index;
	int			x;
	int			y;
    int         size;

	x = 0;
	y = 0;
	i = 0;
	str = __gnl(fd);
	y_len = __get_y_size(fd);
	x_len = __get_x_size(str);
	close(fd);
	fd = open(av, O_RDONLY);
	index = 0;
	size = x_len * y_len;
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
			file_points[index] = init_point(file_points[index], x, y, ft_atoi(&str[i]));
			index++;
			while (ft_isdigit(str[i]) || str[i] == '-')
				i++;
			x++;
		}
		y++;
	}
	return (free(str), file_points);
}