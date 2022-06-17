/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:08:54 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/17 14:25:49 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	__put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}



t_fdf *init(void)
{
	t_fdf *fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FDF");
	if (!fdf->win)
		return (__mlx_cleaner(fdf), NULL);
	fdf->img.new_img = mlx_new_image(fdf->mlx, 1920, 1080);
	if (!fdf->img.new_img)
		return (__mlx_cleaner(fdf), NULL);
	fdf->img.addr = mlx_get_data_addr(fdf->img.new_img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
	if (!fdf->img.addr)
		return (__mlx_cleaner(fdf), NULL);
	return (fdf);
}

int	__close_window(void)
{
	exit(1);
}

__uint32_t	__colorful_pixel(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b << 0);
}

int main(void)
{
	t_fdf	*fdf;
	// __uint32_t		color;

	// color = __colorful_pixel(-255, 0, 255, 255);
	fdf = init();
	// if (!parsing(ac, av))
	// 	return (_ERROR_, 2);
	// if (!fdf(fdf))
	// 	return (_ERROR_, 2);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.new_img, 0, 0);
	
	wu_calc_line(0, 100, 200, 400, fdf);
	wu_calc_line(0, 100, 200, 400, fdf);
	mlx_hook(fdf->win, 33, 1L<<0, __close_window, NULL);
	mlx_loop(fdf->mlx);
	__mlx_cleaner(fdf);
	mlx_destroy_image(fdf->mlx, fdf->img.new_img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
}
