/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:07:34 by shbi              #+#    #+#             */
/*   Updated: 2023/02/01 17:21:18 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup(t_data *data)
{
	switch_map(data);
	setup_player(data);
	setup_color(data->endian_img_win, data->ceilling.rgb, data->c);
	setup_color(data->endian_img_win, data->floor.rgb, data->f);
}
