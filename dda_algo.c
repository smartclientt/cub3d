/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:14:58 by shbi              #+#    #+#             */
/*   Updated: 2023/01/10 06:26:56 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data_vec(t_data *data)
{
	data->pos.x = 22;
	data->pos.y = 12;
	data->dir.x = -1;
	data->dir.y = 0;
	data->time = 0;
	data->oldtime = 0;
	data->plane.x = 0;
	data->plane.y = 0.66;
	data->hit = 0;
}

// need more understanding
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

void	calcule_step_and_sidedist(t_data *data)
{
	// to calcule the sidedist x and y based on the x and y position
	if (data->raydir.x < 0)
	{
		data->step.x = -1;
		data->side_dist.x = (data->pos.x - data->map.x) * data->delta_dist.x;
	}
	else
	{
		data->step.x = 1;
		data->side_dist.x = (data->map.x + 1 - data->pos.x) * data->delta_dist.x;
	}
	if (data->raydir.y < 0)
	{
		data->step.y = -1;
		data->side_dist.y = (data->pos.y - data->map.y) * data->delta_dist.y;
	}
	else
	{
		data->step.y = 1;
		data->side_dist.y = (data->map.y + 1 - data->pos.y) * data->delta_dist.y;
	}
}

void	hit_wall(t_data *data)
{
	while (!data->hit)
	{
		if (data->side_dist.x < data->side_dist.y)
		{
			data->side_dist.x = data->side_dist.x + data->delta_dist.x;
			data->map.x = data->map.x + data->step.x;
			data->side = 0;
		}
		else
		{
			data->side_dist.y = data->side_dist.y + data->delta_dist.y;
			data->map.y = data->map.y + data->step.y;
			data->side = 1;
		}
		if (map[(int)data->map.x][(int)data->map.y] > 0)
			data->hit = 1;
	}
}

void	calcule_perp_wall_dest(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist.x - data->delta_dist.x;
	else
		data->perp_wall_dist = data->side_dist.y - data->delta_dist.y;
}

// goes through  every x in the map
void	raycasting(t_data *data)
{
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		// this is for calulcul every ray position and direction in the screen
		// start from -1 to 1
		data->camera_x = 2 * x / (double)WIN_WIDTH - 1;
		// now we use the camera x result to calcule all ray directions
		data->raydir.x = data->dir.x + (data->plane.x * data->camera_x);
		data->raydir.y = data->dir.y + (data->plane.y * data->camera_x);
		data->map.x = (int)data->pos.x;
		data->map.y = (int)data->pos.y;
		calcule_delta_dist(data);
		calcule_step_and_sidedist(data);
		hit_wall(data);
		calcule_perp_wall_dest(data);
	}
}

void	dda_algorithm(t_data *data)
{
	init_data_vec(data);
	raycasting(data);
}
