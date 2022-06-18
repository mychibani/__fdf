/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:29:35 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/18 19:53:07 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int __is_valid_file_name(char *file_name, char *file_type)
{
    int     size;

    size = ft_strlen(file_name) - ft_strlen(file_type);
    if (size < _SUCCESS_)
        return (_ERROR_);
    if (ft_strncmp(file_type, (file_name + size), size))
        return (_ERROR_);
    return (_SUCCESS_);
}

int __parsing(char **file_name)
{
    int fd;

    printf("%s\n", *file_name);
    if (__is_valid_file_name(*file_name, ".fdf") == _ERROR_)
        return (_ERROR_);
    fd = open(*file_name, O_RDONLY);
    if (fd < 0)
        return (_ERROR_);
    close(fd);
    return (_SUCCESS_);
}
