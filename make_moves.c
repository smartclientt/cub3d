/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:18:25 by shbi              #+#    #+#             */
/*   Updated: 2023/01/29 23:21:16 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 13) // move up
		finghadi = 1;
	if (keycode == 1) // move down
		finghadi = -1;
	if (keycode == 124) // turn left
		achmnjnb = 1;
	if (keycode == 123) // turn right
		achmnjnb = -1;
	if (keycode == 2) // turn left
		harakat = 1;
	if (keycode == 0) // turn right
		harakat = -1;
	if (keycode == 53)
		exit(0);
		// printf("keycode = %d\n", keycode );
	// mlx_clear_window(data->mlx, data->win);
	return (0);
}

int	key_handler_(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 13) // move up
		finghadi = 0;
	if (keycode == 1) // move down
		finghadi = 0;
	if (keycode == 124) // turn left
		achmnjnb = 0;
	if (keycode == 123) // turn right
		achmnjnb = 0;
	if (keycode == 2) // turn left
		harakat = 0;
	if (keycode == 0) // turn right
		harakat = 0;
	// mlx_clear_window(data->mlx, data->win);
	return (0);
}

