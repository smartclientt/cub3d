/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo__.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 02:57:41 by shbi              #+#    #+#             */
/*   Updated: 2023/02/01 16:40:14 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calcule_step_and_sidedist(t_data *data)
{
	data->hit = 0;
	if (data->raydir.x < 0)
	{
		data->step.x = -1;
		data->side_dist.x = (data->pos.x - data->map_.x) * data->delta_dist.x;
	}
	else
	{
		data->step.x = 1;
		data->side_dist.x
			= (data->map_.x + 1.0 - data->pos.x) * data->delta_dist.x;
	}
	if (data->raydir.y < 0)
	{
		data->step.y = -1;
		data->side_dist.y = (data->pos.y - data->map_.y) * data->delta_dist.y;
	}
	else
	{
		data->step.y = 1;
		data->side_dist.y
			= (data->map_.y + 1.0 - data->pos.y) * data->delta_dist.y;
	}
}

void	build_texture(t_data *data, t_draw *draw, int x)
{
	int	y;

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
	data->tex_pos = (draw->draw_start - WIN_HEIGHT / 2
			+ draw->line_height / 2) * data->step_;
	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		data->tex_y = (int)fmod(data->tex_pos, data->img_height);
		data->tex_pos = data->tex_pos + data->step_;
		whish_texture(data, draw);
		my_mlx_pixel_put(data, x, y, draw->color);
		y++;
	}
}

void	whish_texture(t_data *data, t_draw *draw)
{
	if (data->side == 1 && data->raydir.y > 0)
			draw->color = *(int *)(data->color_data + (data->tex_y
					* data->size_line_2 + data->tex_x * (data->bpp_2 / 8)));
	else if (data->side == 1 && data->raydir.y < 0)
			draw->color = *(int *)(data->color_data + (data->tex_y
					* data->size_line_3 + data->tex_x * (data->bpp_3 / 8)));
	else if (data->side == 0 && data->raydir.x > 0)
			draw->color = *(int *)(data->color_data + (data->tex_y
					* data->size_line_1 + data->tex_x * (data->bpp_1 / 8)));
	else if (data->side == 0 && data->raydir.x < 0)
			draw->color = *(int *)(data->color_data + (data->tex_y
					* data->size_line_4 + data->tex_x * (data->bpp_4 / 8)));
	if (data->side == 1)
			draw->color = (draw->color >> 1) & 0x7F7F7F;
}

void	draw_ray_line(t_data *data, t_draw *draw, int x)
{
	int	y;

	y = 0;
	while (y < draw->draw_start)
	{
		my_mlx_pixel_put(data, x, y, data->ceilling.color);
		y++;
	}
	while (y < draw->draw_end)
		y++;
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(data, x, y, data->floor.color);
		y++;
	}
}
