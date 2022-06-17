/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:36 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/17 14:33:47 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	void	*new_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_img;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_img	img;

} t_fdf;

typedef struct s_3d
{
	int x;
	int y;
	int z;
	int	color;

} t_3d;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	
} t_line;

typedef	struct s_key
{
	int	key_hook;

} t_key;

typedef	struct s_cam
{
	int	pov;	

} t_cam;

typedef	struct s_program_data
{
	unsigned long long	grid_size;
	int					fd;
	t_fdf				*fdf;
	t_key				*key;
	t_cam				*cam;
	t_line				*line;
	t_3d				*grid;

}	t_program_data;

#endif