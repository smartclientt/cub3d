/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:19:03 by ael-idri          #+#    #+#             */
/*   Updated: 2023/02/01 23:19:07 by ael-idri         ###   ########.fr       */
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
