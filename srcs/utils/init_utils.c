/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:32:35 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/16 20:37:49 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	__get_y_size(int fd)
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

int	__get_x_size(char *str)
{
	int	x;
	int	i;
	int	len;

	i = 0;
	x = 0;
	if (!str)
		return (-1);
	len = ft_strlen(str);
	while (i < len - 1)
	{
		while (str[i] == ' ')
			i++;
		x++;
		while (str[i] != ' ' && str[i])
			i++;
		i++;
	}
	return (x);
}
