/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:08:54 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/26 10:08:56 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

}	t_fdf;

void	__mlx_cleaner(t_fdf *fdf)
{
 	if (fdf->mlx)
 		free(fdf->mlx);
 	if (fdf->win)
 		free(fdf->win);
	if (fdf->img.new_img)
		free(fdf->img.new_img);
}

void	ft_put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	char *dst;

	fdf->img.addr = mlx_get_data_addr(fdf->img.new_img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 2));
	*(unsigned int*)dst = color;
}

// void	__put_pixel_click(t_fdf *fdf)
// {
//  	int	mouse_clk;

// }


int main()
{
	t_fdf	fdf;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1920, 1080, "FDF");
	if (!fdf.win)
		return(__mlx_cleaner(&fdf), 2);
	fdf.img.new_img = mlx_new_image(fdf.mlx, 1920, 1080);
	if (!fdf.img.new_img)
		return (__mlx_cleaner(&fdf), 2);
	ft_put_pixel_on_img(&fdf, 960, 540, 0xFFFFFFFF);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.new_img, 0, 0);
	mlx_loop(fdf.mlx);
	mlx_destroy_image(fdf.mlx, fdf.img.new_img);
	mlx_destroy_window(fdf.mlx, fdf.win);
	mlx_destroy_display(fdf.mlx);
}
