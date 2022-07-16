/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:36 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/16 14:50:14 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct s_img
{
	void	*new_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

} t_img;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_img	img;

} t_fdf;

typedef struct s_3d
{
	int	x;
	int	y;
	int	z;
	unsigned int color;

} t_3d;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	unsigned int	color;
	
} t_line;

typedef	struct s_2d
{
	int x;
	int y;
	int	color;
	
} t_2d;

typedef struct s_map_data
{
	int		x_size;	
	int		y_size;	
	int		tot_size;	
	char	*file_name;
	int		fd;
    int		zoom;
	int		scaling;
	int		min;
	int		max;

} t_map_data;

typedef struct s_vars
{
	int	dx;
	int	sx;
	int	sy;
	int	dy;
	int	err;
	int e2;

} t_vars;

typedef	struct s_program_data
{
	int					fd;
	char				*file_name;
	t_fdf				*fdf;
	t_line				*line;
	t_3d				**grid;
	t_2d				**final_map;
	t_map_data			*map_data;

} t_program_data;

#endif