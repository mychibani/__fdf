// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   color.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/07/04 11:09:09 by ychibani          #+#    #+#             */
// /*   Updated: 2022/07/04 11:20:09 by ychibani         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "fdf.h"

// double __double_ternary(int condition, double success, double failure)
// {
//     if (condition == _SUCCESS_)
//         return (success);
//     return (failure);
// }

// double  ratio(int start, int end, int current)
// {
//     double  position;
//     double  distance;

//     position = current - start;
//     distance = end - start;
//     return (__double_ternary(distance == 0, 1.0, position / distance));
// }

// int __intensity(int start, int end, int percent)
// {
//     return ((int)((1 - percent) * start + percent * end));
// }

// int __init_color(t_program_data *data, int z)
// {
//     double  percent;
    
//     percent = ratio(data->map_data->min, data->map_data->max, z);
//     if (percent < 0.005)
//         return (data->color->min);
//     if (percent < 0.0525)
//         return (data->color->first_quarter);
//     if (percent < 0.125)
//         return (data->color->second_quarter);
//     if (percent < 0.275)
//         return (data->color->third_quarter);
//     return (data->color->max);
// }

// // int __color()
// {
//     red = __intensity((start))    
// }