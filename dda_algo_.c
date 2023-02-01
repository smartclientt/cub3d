/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:56:33 by shbi              #+#    #+#             */
/*   Updated: 2023/02/01 16:41:42 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hit_wall(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist.x < data->side_dist.y)
		{
			data->side_dist.x = data->side_dist.x + data->delta_dist.x;
			data->map_.x = data->map_.x + data->step.x;
			data->side = 0;
		}
		else
		{
			data->side_dist.y = data->side_dist.y + data->delta_dist.y;
			data->map_.y = data->map_.y + data->step.y;
			data->side = 1;
		}
		if (data->map[(int)data->map_.x][(int)data->map_.y] == '1')
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
	draw->draw_end = (draw->line_height / 2) + (WIN_HEIGHT / 2);
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
