/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:18:25 by shbi              #+#    #+#             */
/*   Updated: 2023/02/01 23:02:27 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 13)
		data->move = 1;
	if (keycode == 1)
		data->move = -1;
	if (keycode == 124)
		data->rotate = (data->rot_dir) * 1;
	if (keycode == 123)
		data->rotate = (data->rot_dir) * -1;
	if (keycode == 2)
		data->slide = (data->rot_dir) * 1;
	if (keycode == 0)
		data->slide = (data->rot_dir) * -1;
	if (keycode == 53)
	{
		mmlx_destroy_image(data->mlx, data->img_text1);
		exit(0);
	}
	return (0);
}

int	key_handler_(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 13)
		data->move = 0;
	if (keycode == 1)
		data->move = 0;
	if (keycode == 124)
		data->rotate = 0;
	if (keycode == 123)
		data->rotate = 0;
	if (keycode == 2)
		data->slide = 0;
	if (keycode == 0)
		data->slide = 0;
	return (0);
}

int	key_handler__(int x, int y, t_data *data)
{
	if (x >= WIN_WIDTH || x <= 0 || y >= WIN_HEIGHT || y <= 0)
		return (0);
	if (x > data->x_code)
		data->rotate_mousse = data->rot_dir * 1;
	if (x < data->x_code)
		data->rotate_mousse = data->rot_dir * -1;
	data->x_code = x;
	return (0);
}
