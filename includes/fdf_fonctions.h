/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fonctions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:29 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/17 14:07:45 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FONCTIONS_H
# define FDF_FONCTIONS_H

t_program_data	*__init_program_data(void);
t_program_data  *__initialization(void);
t_fdf           *__mlx_init(t_fdf *fdf);

void	        __put_pixel_on_img(t_fdf *fdf, int x, int y, int color);
int		        __mlx_event(int key_hook, t_program_data *data);

void	        __clean(t_program_data *data);

#endif