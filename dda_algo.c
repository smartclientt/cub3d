/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:14:58 by shbi              #+#    #+#             */
/*   Updated: 2023/02/01 03:21:23 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_data *data)
{
	if (data->map[(int)(data->pos.x + (data->move)
			* data->dir.x * MOVE_SPEED)][(int)data->pos.y] == '0')
		data->pos.x += (data->move) * data->dir.x * MOVE_SPEED;
	if (data->map[(int)data->pos.x][(int)(data->pos.y
		+ (data->move) * data->dir.y * MOVE_SPEED)] == '0')
		data->pos.y += (data->move) * data->dir.y * MOVE_SPEED;
}

void	slide(t_data *data)
{
	data->new_dir.x
		= data->dir.x * cos((M_PI_2)) - data->dir.y * sin((M_PI_2));
	data->new_dir.y
		= data->old_dir.x * sin((M_PI_2)) + data->dir.y * cos((M_PI_2));
	if (data->map[(int)(data->pos.x + (data->slide)
			* data->new_dir.x * MOVE_SPEED)][(int)data->pos.y] == '0')
		data->pos.x += (data->slide) * data->new_dir.x * MOVE_SPEED;
	if (data->map[(int)data->pos.x][(int)(data->pos.y
		+ (data->slide) * data->new_dir.y * MOVE_SPEED)] == '0')
		data->pos.y += (data->slide) * data->new_dir.y * MOVE_SPEED;
}

void	rotate(t_data	*data)
{
	data->old_dir.x = data->dir.x;
	data->dir.x = data->dir.x * cos((data->rotate) * ROT_SPEED)
		- data->dir.y * sin((data->rotate) * ROT_SPEED);
	data->dir.y = data->old_dir.x * sin((data->rotate) * ROT_SPEED)
		+ data->dir.y * cos((data->rotate) * ROT_SPEED);
	data->old_plane.x = data->plane.x;
	data->plane.x = data->plane.x * cos((data->rotate) * ROT_SPEED)
		- data->plane.y * sin((data->rotate) * ROT_SPEED);
	data->plane.y = data->old_plane.x * sin((data->rotate) * ROT_SPEED)
		+ data->plane.y * cos((data->rotate) * ROT_SPEED);
}

void	calcule_delta_dist(t_data *data)
{
	if (data->raydir.x == 0)
		data->delta_dist.x = 1e30;
	else
		data->delta_dist.x = fabs(1 / data->raydir.x);
	if (data->raydir.y == 0)
		data->delta_dist.y = 1e30;
	else
		data->delta_dist.y = fabs(1 / data->raydir.y);
}

void	raycasting(t_data *data)
{
	t_draw	draw;
	int		x;

	x = 0;
	move(data);
	rotate(data);
	slide(data);
	while (x < WIN_WIDTH)
	{
		data->camera_x = 2 * x / (double)WIN_WIDTH - 1;
		data->raydir.x = data->dir.x + (data->plane.x * data->camera_x);
		data->raydir.y = data->dir.y + (data->plane.y * data->camera_x);
		data->map_.x = (int)data->pos.x;
		data->map_.y = (int)data->pos.y;
		calcule_delta_dist(data);
		calcule_step_and_sidedist(data);
		hit_wall(data);
		calcule_perp_wall_dest(data);
		draw_wall(data, &draw, x);
		draw_ray_line(data, &draw, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->win_img, 0, 0);
}
