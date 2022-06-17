/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:29:35 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/17 15:39:04 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int parsing(t_program_data *data, int ac, char **av)
{
    data->fd = open(av[1], O_RDONLY);
    if (data->fd < 0) 
        return (-1);
    return (1);
}