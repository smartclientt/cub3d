/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:18:25 by shbi              #+#    #+#             */
/*   Updated: 2023/01/25 03:43:25 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	key_handler(int keycode, t_data *data)
{
	if (keycode == 13) // move up
		move_up(data);
	else if (keycode == 1) // move down
		move_down(data);
	else if (keycode == 2) // turn left
		rotate_left(data);
	else if (keycode == 0) // turn right
		rotate_right(data);
	else if (keycode == 53)
		exit(0);
	mlx_clear_window(data->mlx, data->win);
	dda_algo(data);
	return (0);
}
