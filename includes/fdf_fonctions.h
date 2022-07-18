/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fonctions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:29 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/18 10:29:30 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FONCTIONS_H
# define FDF_FONCTIONS_H

/*
**  Init
*/

t_map_data		*__init_map_data(int fd, char *file_name);
t_3d			**__init_3d_grid(t_map_data *data);
t_fdf			*__mlx_init(void);
bool			__init_program_data(t_program_data *data, char *file_name);
int				__get_y_size(int fd);
int				__get_x_size(char *str);

/*
**  Utils
*/

void			__put_pixel_on_img(t_fdf *fdf, int x, int y, int color);
int				__parsing(char **file_name);
int				__line_mapping(t_2d **grid, t_map_data *data, t_fdf *fdf);
int				__put_image_to_window(t_program_data *data);
int				__get_y_size(int fd);
int				__get_x_size(char *str);

/*
**  Events
*/

int				close_win(int key_hook, t_program_data *data);
int				autre_fonction(t_program_data *data);

/*
**  Clean
*/

void			__clean(t_program_data *data);

/*
**  Mapping
*/

void			__print_line_to_image(t_fdf *fdf, t_line *line);
void			__get_min_max_in_tab(t_3d **grid, t_map_data *data, int *min,
					int *max);
t_2d			**isometric_projection(t_3d **grid, t_map_data *data);

#endif