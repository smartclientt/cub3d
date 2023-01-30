/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:14:58 by shbi              #+#    #+#             */
/*   Updated: 2023/01/30 16:26:35 by shbi             ###   ########.fr       */
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
	if (map[(int)(data->pos.x + (data->move) * data->dir.x * MOVE_SPEED)][(int)data->pos.y] == 0)
		data->pos.x += (data->move) * data->dir.x * MOVE_SPEED;
	if (map[(int)data->pos.x][(int)(data->pos.y + (data->move) * data->dir.y * MOVE_SPEED)] == 0)
		data->pos.y += (data->move) * data->dir.y * MOVE_SPEED;
}

void	slide(t_data *data)
{
	data->new_dir.x = data->dir.x * cos((M_PI_2)) - data->dir.y * sin((M_PI_2));
	data->new_dir.y = data->old_dir.x * sin((M_PI_2)) + data->dir.y * cos((M_PI_2));
	if (map[(int)(data->pos.x + (data->slide) * data->new_dir.x * MOVE_SPEED)][(int)data->pos.y] == 0)
		data->pos.x += (data->slide) * data->new_dir.x * MOVE_SPEED;
	if (map[(int)data->pos.x][(int)(data->pos.y + (data->slide) * data->new_dir.y * MOVE_SPEED)] == 0)
		data->pos.y += (data->slide) * data->new_dir.y * MOVE_SPEED;
}

void	rotate(t_data	*data)
{
	data->old_dir.x = data->dir.x;
	data->dir.x = data->dir.x * cos((data->rotate) * ROT_SPEED) - data->dir.y * sin((data->rotate)  * ROT_SPEED);
	data->dir.y = data->old_dir.x * sin((data->rotate) * ROT_SPEED) + data->dir.y * cos((data->rotate) * ROT_SPEED);
	data->old_plane.x = data->plane.x;
	data->plane.x = data->plane.x * cos((data->rotate) * ROT_SPEED) - data->plane.y * sin((data->rotate) * ROT_SPEED);
	data->plane.y = data->old_plane.x * sin((data->rotate) * ROT_SPEED) + data->plane.y * cos((data->rotate) * ROT_SPEED);
}


void	init_data_vec(t_data *data)
{
	data->pos.x = 12;
	data->pos.y = 10;
	data->dir.x = 0;
	data->dir.y = -1;
	data->plane.x = 0.66;
	data->plane.y = 0;
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

int test;

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

	index = y * data->size_line_img + x * (data->bpp_img_win / 8);
	data->addr_win_img[index++] = color;
	data->addr_win_img[index++] = color >> 8;
	data->addr_win_img[index++] = color >> 16;
	data->addr_win_img[index] = color >> 24;
}

void	texture_info(t_data *data)
{
	if (data->side == 1 && data->raydir.y > 0)
	{
		data->color_data = data->color_data_2;
		data->img_height = data->img_height_2;	
		data->img_width = data->img_width_2;
	}
	if (data->side == 1 && data->raydir.y < 0)
	{
		data->color_data = data->color_data_3;
		data->img_height = data->img_height_3;	
		data->img_width = data->img_width_3;
	}
	if (data->side == 0 && data->raydir.x > 0)
	{
		data->color_data = data->color_data_1;
		data->img_width = data->img_width_1;
		data->img_height = data->img_height_1;
	}
	if (data->side == 0 && data->raydir.x < 0)
	{
		data->color_data = data->color_data_4;
		data->img_height = data->img_height_4;
		data->img_width = data->img_width_4;
	}
}

void	build_texture(t_data *data, t_draw *draw, int x)
{
	int y;

	texture_info(data);
	if (data->side == 0)
		data->wall_x = data->pos.y + data->perp_wall_dist * data->raydir.y;
	else
		data->wall_x = data->pos.x + data->perp_wall_dist * data->raydir.x;
	data->wall_x = data->wall_x - floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * (double)(data->img_width));
	if (data->side == 0 && data->raydir.x > 0)
		data->tex_x = data->img_width - data->tex_x - 1;
	if (data->side == 1 && data->raydir.y < 0)
		data->tex_x = data->img_width - data->tex_x - 1;
	data->step_ = (double)data->img_height / draw->line_height;
	data->tex_pos = (draw->draw_start - WIN_HEIGHT / 2 + draw->line_height / 2) * data->step_;
	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		data->tex_y = (int)fmod(data->tex_pos ,data->img_height);
		data->tex_pos = data->tex_pos + data->step_;
		whish_texture(data, draw);
		my_mlx_pixel_put(data, x, y, draw->color);
		y++;
	}
}

void	whish_texture(t_data *data, t_draw *draw)
{
	if (data->side == 1 && data->raydir.y > 0)
			draw->color = *(int *)(data->color_data + (data->tex_y * data->size_line_2 + data->tex_x * (data->bpp_2 / 8)));
		else if (data->side == 1 && data->raydir.y < 0)
			draw->color = *(int *)(data->color_data + (data->tex_y * data->size_line_3 + data->tex_x * (data->bpp_3 / 8)));
		else if (data->side == 0 && data->raydir.x > 0)
			draw->color = *(int *)(data->color_data + (data->tex_y * data->size_line_1 + data->tex_x * (data->bpp_1 / 8)));
		else if (data->side == 0 && data->raydir.x < 0)
			draw->color = *(int *)(data->color_data + (data->tex_y * data->size_line_4 + data->tex_x * (data->bpp_4 / 8)));
		if (data->side == 1)
			draw->color = (draw->color >> 1) & 0x7F7F7F;
}

void	draw_ray_line(t_data *data, t_draw *draw, int x)
{
	int y;
	(void)data;
	(void)x;
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
	mlx_put_image_to_window(data->mlx, data->win, data->win_img, 0, 0);
}
