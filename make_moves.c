/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:18:25 by shbi              #+#    #+#             */
/*   Updated: 2023/01/29 23:55:32 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 13) // move up
		data->move = 1;
	if (keycode == 1) // move down
		data->move = -1;
	if (keycode == 124) // turn left
		data->rotate = 1;
	if (keycode == 123) // turn right
		data->rotate = -1;
	if (keycode == 2) // turn left
		data->slide = 1;
	if (keycode == 0) // turn right
		data->slide = -1;
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img_text1);
		exit(0);
	}
		// printf("keycode = %d\n", keycode );
	// mlx_clear_window(data->mlx, data->win);
	return (0);
}

int	key_handler_(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 13) // move up
		data->move = 0;
	if (keycode == 1) // move down
		data->move = 0;
	if (keycode == 124) // turn left
		data->rotate = 0;
	if (keycode == 123) // turn right
		data->rotate = 0;
	if (keycode == 2) // turn left
		data->slide = 0;
	if (keycode == 0) // turn right
		data->slide = 0;
	// mlx_clear_window(data->mlx, data->win);
	return (0);
}

