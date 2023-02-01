/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 03:04:45 by shbi              #+#    #+#             */
/*   Updated: 2023/02/01 16:01:27 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_dir_vector(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
	{
		data->dir.x = 0;
		data->dir.y = 1;
		data->plane.x = 0.66;
		data->plane.y = 0;
		data->rot_dir = -1;
	}
	else if (data->map[i][j] == 'S')
	{
		data->dir.x = 0;
		data->dir.y = -1;
		data->plane.x = 0.66;
		data->plane.y = 0;
		data->rot_dir = 1;
	}
}

void	init_dir_vector_(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'E')
	{
		data->dir.x = 1;
		data->dir.y = 0;
		data->plane.x = 0;
		data->plane.y = 0.66;
		data->rot_dir = 1;
	}
	if (data->map[i][j] == 'W')
	{
		data->dir.x = -1;
		data->dir.y = 0;
		data->plane.x = 0;
		data->plane.y = 0.66;
		data->rot_dir = -1;
	}
}

void	setup_player(t_data *data)
{
	data->rotate = 0;
	data->move = 0;
	data->slide = 0;
	data->map[(size_t)data->pos.x][(size_t)data->pos.y] = '0';
}

void	setup_color(int endian, unsigned char rgb[4], int color[4])
{
	if (!endian)
	{
		rgb[0] = (unsigned char)color[2];
		rgb[1] = (unsigned char)color[1];
		rgb[2] = (unsigned char)color[0];
		rgb[3] = 0;
	}
	else
	{
		rgb[0] = 0;
		rgb[1] = (unsigned char)color[0];
		rgb[2] = (unsigned char)color[1];
		rgb[3] = (unsigned char)color[2];
	}
}
