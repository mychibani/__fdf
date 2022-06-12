/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:09:29 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/26 10:09:30 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTIONS_H
# define FONCTIONS_H

void	__put_pixel_on_img(t_fdf *fdf, int x, int y, int color, float brightness);
void	wu_calc_line(int x0, int y0, int x1, int y1, t_fdf *fdf);


#endif