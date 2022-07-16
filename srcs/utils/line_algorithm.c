/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:21:22 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/16 20:38:11 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__print_line_to_image(t_fdf *fdf, t_line *line)
{
	t_vars	vars;

	vars.dx = (int)float_abs(line->x1 - line->x0);
	vars.dy = -(int)float_abs(line->y1 - line->y0);
	vars.sx = int_trn((line->x1 > line->x0), 1, -1);
	vars.sy = int_trn((line->y1 > line->y0), 1, -1);
	vars.err = vars.dx + vars.dy;
	while (line->x0 != line->x1 && line->y0 != line->y1)
	{
		__put_pixel_on_img(fdf, line->x0, line->y0, line->color);
		vars.e2 = 2 * vars.err;
		if (vars.e2 >= vars.dy)
		{
			vars.err += vars.dy;
			line->x0 += vars.sx;
		}
		if (vars.e2 <= vars.dy)
		{
			vars.err += vars.dx;
			line->y0 += vars.sy;
		}
	}
}
