/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:06:13 by ychibani          #+#    #+#             */
/*   Updated: 2022/06/17 14:06:23 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__clean(t_program_data *data)
{
	if (data->fdf)
		free(data->fdf);
	if (data->cam)
		free(data->cam);
	if (data->line)
		free(data->line);
	if (data->key)
		free(data->key);
	if (data)
		free(data);
}