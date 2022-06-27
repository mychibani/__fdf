/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fonctions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:29 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/26 21:05:14 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FONCTIONS_H
#define FDF_FONCTIONS_H

bool        __init_program_data(t_program_data *data, char *file_name);
t_3d        **__init_3d_grid(t_map_data *data);
t_fdf       *__mlx_init(void);
t_map_data  *__init_map_data(int fd, char *file_name);

int		__parsing(char **file_name);

void	__put_pixel_on_img(t_fdf *fdf, int x, int y, int color);
int		__mlx_event(int key_hook, t_program_data *data);

void	__clean(t_program_data *data);


t_2d    **parrallel_projection(t_3d **grid, t_map_data *data);

void	print_points(t_3d **points, t_map_data *data);
void	print_data(t_program_data *data);
void	print_fdf(t_fdf *fdf);

#endif