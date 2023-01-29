/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:21:28 by shbi              #+#    #+#             */
/*   Updated: 2023/01/29 23:24:41 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dda_algo(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->img2 = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr2 = mlx_get_data_addr(data->img2, &data->bpp2, &data->size_line2, &data->endian2);
	raycasting(data);
	// mlx_destroy_image(data->mlx, data->img2);
	// mlx_destroy_image(data->mlx, data->img_text1);
	return (0);
}

int	exit_hook(t_data *data)
{
	(void) data;
	exit(0);
	return (0);
}

void	inital_img_texture(t_data *data)
{
	data->img_text1 = mlx_xpm_file_to_image(data->mlx, "./texture/text10.xpm", &data->img_width, &data->img_height);
	data->color_data = mlx_get_data_addr(data->img_text1, &data->bpp, &data->size_line, &data->endian);
	// data->img2 = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	// data->addr2 = mlx_get_data_addr(data->img2, &data->bpp2, &data->size_line2, &data->endian2);
}

int	main(void)
{
	t_data	data;

	init_data_vec(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	achmnjnb = 0;
	finghadi = 0;
	harakat = 0;
	inital_img_texture(&data);
	mlx_hook(data.win, 2, 0, key_handler, &data);
	mlx_hook(data.win, 3, 0, key_handler_, &data);
	mlx_hook(data.win, 17, 0, exit_hook, &data);
	mlx_loop_hook(data.mlx, &dda_algo, &data);
	mlx_loop(data.mlx);
	return (0);
}
