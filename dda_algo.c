/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:14:58 by shbi              #+#    #+#             */
/*   Updated: 2023/01/25 03:45:55 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[MAP_WIDTH][MAP_HEIGHT] =
{
	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,2 ,2 ,2 ,2 ,2 ,0 ,0 ,0 ,0 ,3 ,0 ,3 ,0 ,3 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,2 ,2 ,0 ,2 ,2 ,0 ,0 ,0 ,0 ,3 ,0 ,3 ,0 ,3 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,0 ,4 ,0 ,0 ,0 ,0 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,0 ,0 ,0 ,0 ,5 ,0 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,0 ,4 ,0 ,0 ,0 ,0 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,0 ,4 ,4 ,4 ,4 ,4 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 }
};

void	move_up(t_data *data)
{
	printf("move up\n");
	if (map[(int)(data->pos.x + data->dir.x * MOVE_SPEED)][(int)data->pos.y] == 0)
		data->pos.x += data->dir.x * MOVE_SPEED;
	if (map[(int)data->pos.x][(int)(data->pos.y + data->dir.y * MOVE_SPEED)] == 0)
		data->pos.y += data->dir.y * MOVE_SPEED;
}

void	move_down(t_data *data)
{
	printf("move down\n");
	if (map[(int)(data->pos.x - data->dir.x * MOVE_SPEED)][(int)data->pos.y] == 0)
		data->pos.x -= data->dir.x * MOVE_SPEED;
	if (map[(int)data->pos.x][(int)(data->pos.y - data->dir.y * MOVE_SPEED)] == 0)
		data->pos.y -= data->dir.y * MOVE_SPEED;
}

void	rotate_left(t_data	*data)
{
	data->old_dir.x = data->dir.x;
	data->dir.x = data->dir.x * cos(ROT_SPEED) - data->dir.y * sin(ROT_SPEED);
	data->dir.y = data->old_dir.x * sin(ROT_SPEED) + data->dir.y * cos(ROT_SPEED);
	data->old_plane.x = data->plane.x;
	data->plane.x = data->plane.x * cos(ROT_SPEED) - data->plane.y * sin(ROT_SPEED);
	data->plane.y = data->old_plane.x * sin(ROT_SPEED) + data->plane.y * cos(ROT_SPEED);
}

void	rotate_right(t_data	*data)
{
	data->old_dir.x = data->dir.x;
	data->dir.x = data->dir.x * cos(-ROT_SPEED) - data->dir.y * sin(-ROT_SPEED);
	data->dir.y = data->old_dir.x * sin(-ROT_SPEED) + data->dir.y * cos(-ROT_SPEED);
	data->old_plane.x = data->plane.x;
	data->plane.x = data->plane.x * cos(-ROT_SPEED) - data->plane.y * sin(-ROT_SPEED);
	data->plane.y = data->old_plane.x * sin(-ROT_SPEED) + data->plane.y * cos(-ROT_SPEED);
}

void	init_data_vec(t_data *data)
{
	data->pos.x = 10;
	data->pos.y = 12;
	data->dir.x = 1;
	data->dir.y = 0;
	data->plane.x = 0;
	data->plane.y = 0.66;
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
	data->hit = 0;
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

void	draw_wall(t_data *data, t_draw *draw)
{
	draw->line_height = (int)(WIN_HEIGHT / data->perp_wall_dist);
	draw->draw_start = (-draw->line_height / 2) + (WIN_HEIGHT / 2);
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end =(draw->line_height / 2) + (WIN_HEIGHT / 2);
	if (draw->draw_end >= WIN_HEIGHT)
		draw->draw_end = WIN_HEIGHT - 1;
	draw->color = 0x0000FF;
	if (data->side == 1)
		draw->color = draw->color / 2; 
}

void	draw_ray_line(t_data *data, t_draw *draw, int x)
{
	int y;
	
	y = 0;
	while (y < draw->draw_start)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0x00FF00);
		y++;
	}
	while (y < draw->draw_end)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, draw->color);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000);
		y++;
	}
}

// goes through  every x in the map
void	raycasting(t_data *data)
{
	t_draw	draw;
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
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
		draw_wall(data, &draw);
		draw_ray_line(data, &draw, x);
		x++;
	}
}
