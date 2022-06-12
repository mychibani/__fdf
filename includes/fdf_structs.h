/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:36 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/26 10:09:38 by ychibani         ###   ########.fr       */
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
	
} t_line;

typedef struct s_program_data
{
	
} t_program_data;

#endif