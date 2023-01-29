/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:14:58 by shbi              #+#    #+#             */
/*   Updated: 2023/01/29 22:59:17 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[MAP_WIDTH][MAP_HEIGHT] =
{
	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 }
};

void	move(t_data *data)
{
	if (map[(int)(data->pos.x + (finghadi) * data->dir.x * MOVE_SPEED)][(int)data->pos.y] == 0)
		data->pos.x += (finghadi) * data->dir.x * MOVE_SPEED;
	if (map[(int)data->pos.x][(int)(data->pos.y + (finghadi) * data->dir.y * MOVE_SPEED)] == 0)
		data->pos.y += (finghadi) * data->dir.y * MOVE_SPEED;
}

void	slide(t_data *data)
{
	data->new_dir.x = data->dir.x * cos((M_PI_2)) - data->dir.y * sin((M_PI_2));
	data->new_dir.y = data->old_dir.x * sin((M_PI_2)) + data->dir.y * cos((M_PI_2));
	if (map[(int)(data->pos.x + (harakat) * data->new_dir.x * MOVE_SPEED)][(int)data->pos.y] == 0)
		data->pos.x += (harakat) * data->new_dir.x * MOVE_SPEED;
	if (map[(int)data->pos.x][(int)(data->pos.y + (harakat) * data->new_dir.y * MOVE_SPEED)] == 0)
		data->pos.y += (harakat) * data->new_dir.y * MOVE_SPEED;
}

void	rotate(t_data	*data)
{
	data->old_dir.x = data->dir.x;
	data->dir.x = data->dir.x * cos((achmnjnb) * ROT_SPEED) - data->dir.y * sin((achmnjnb)  * ROT_SPEED);
	data->dir.y = data->old_dir.x * sin((achmnjnb) * ROT_SPEED) + data->dir.y * cos((achmnjnb) * ROT_SPEED);
	data->old_plane.x = data->plane.x;
	data->plane.x = data->plane.x * cos((achmnjnb) * ROT_SPEED) - data->plane.y * sin((achmnjnb) * ROT_SPEED);
	data->plane.y = data->old_plane.x * sin((achmnjnb) * ROT_SPEED) + data->plane.y * cos((achmnjnb) * ROT_SPEED);
}


void	init_data_vec(t_data *data)
{
	data->pos.x = 12.5;
	data->pos.y = 12.2;
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
		data->side_dist.x = (data->map.x + 1.0 - data->pos.x) * data->delta_dist.x;
	}
	if (data->raydir.y < 0)
	{
		data->step.y = -1;
		data->side_dist.y = (data->pos.y - data->map.y) * data->delta_dist.y;
	}
	else
	{
		data->step.y = 1;
		data->side_dist.y = (data->map.y + 1.0 - data->pos.y) * data->delta_dist.y;
	}
}

void	hit_wall(t_data *data)
{
	while (data->hit == 0)
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

void	draw_wall(t_data *data, t_draw *draw, int x)
{
	draw->line_height = (int)(WIN_HEIGHT / data->perp_wall_dist);
	draw->draw_start = (-draw->line_height / 2) + (WIN_HEIGHT / 2);
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end =(draw->line_height / 2) + (WIN_HEIGHT / 2);
	if (draw->draw_end >= WIN_HEIGHT)
		draw->draw_end = WIN_HEIGHT - 1;
	build_texture(data, draw, x);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	index;

	index = y * data->size_line2 + x * (data->bpp2 / 8);
	data->addr2[index++] = color;
	data->addr2[index++] = color >> 8;
	data->addr2[index++] = color >> 16;
	data->addr2[index] = color >> 24;
}

void	build_texture(t_data *data, t_draw *draw, int x)
{
	int y;

	if (data->side == 0)
		data->wall_x = data->pos.y + data->perp_wall_dist * data->raydir.y;
	else
		data->wall_x = data->pos.x + data->perp_wall_dist * data->raydir.x;
	data->wall_x = data->wall_x - floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * (double)(TEX_WIDTH));
	if (data->side == 0 && data->raydir.x > 0)
		data->tex_x = TEX_WIDTH - data->tex_x - 1;
	if (data->side == 1 && data->raydir.y < 0)
		data->tex_x = TEX_WIDTH - data->tex_x - 1;
	data->step_ = (double)TEX_HEIGHT / draw->line_height;
	data->tex_pos = (draw->draw_start - WIN_HEIGHT / 2 + draw->line_height / 2) * data->step_;
	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		data->tex_y = (int)fmod(data->tex_pos ,TEX_HEIGHT);
		data->tex_pos = data->tex_pos + data->step_;
		draw->color = *(int *)(data->color_data + (data->tex_y * data->size_line + data->tex_x * (data->bpp / 8)));
		if (data->side == 1)
			draw->color = (draw->color >> 1) & 0x7F7F7F;
		my_mlx_pixel_put(data, x, y, draw->color);
		y++;
	}
}

void	draw_ray_line(t_data *data, t_draw *draw, int x)
{
	int y;
	
	y = 0;
	while (y < draw->draw_start)
	{
		my_mlx_pixel_put(data, x, y, 0xdbfdf7);
		y++;
	}
	while (y < draw->draw_end)
		y++;
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(data, x, y, 0xdbfdf7);
		y++;
	}
}

// goes through  every x in the map
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
		// this is for calulcul every ray position and direction in the screen
		// start from -1 to 1
		data->camera_x = 2 * x / (double)WIN_WIDTH - 1;
		data->raydir.x = data->dir.x + (data->plane.x * data->camera_x);
		data->raydir.y = data->dir.y + (data->plane.y * data->camera_x);
		data->map.x = (int)data->pos.x;
		data->map.y = (int)data->pos.y;
		calcule_delta_dist(data);
		calcule_step_and_sidedist(data);
		hit_wall(data);
		calcule_perp_wall_dest(data);
		draw_wall(data, &draw, x);
		draw_ray_line(data, &draw, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img2, 0, 0);
}
