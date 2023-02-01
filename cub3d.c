/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:21:28 by shbi              #+#    #+#             */
/*   Updated: 2023/02/01 17:25:24 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dda_algo(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->win_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr_win_img = mlx_get_data_addr(data->win_img, &data->bpp_img_win,
			&data->size_line_img, &data->endian_img_win);
	raycasting(data);
	mlx_destroy_image(data->mlx, data->win_img);
	return (0);
}

int	exit_hook(t_data *data)
{
	(void) data;
	mlx_destroy_image(data->mlx, data->img_text1);
	mlx_destroy_image(data->mlx, data->img_text2);
	mlx_destroy_image(data->mlx, data->img_text3);
	mlx_destroy_image(data->mlx, data->img_text4);
	exit(0);
	return (0);
}

void	inital_img_texture(t_data *data)
{
	data->img_text1 = mlx_xpm_file_to_image(data->mlx, data->no,
			&data->img_width_1, &data->img_height_1);
	data->img_text2 = mlx_xpm_file_to_image(data->mlx, data->we,
			&data->img_width_2, &data->img_height_2);
	data->img_text3 = mlx_xpm_file_to_image(data->mlx, data->so,
			&data->img_width_3, &data->img_height_3);
	data->img_text4 = mlx_xpm_file_to_image(data->mlx, data->ea,
			&data->img_width_4, &data->img_height_4);
	data->color_data_1 = mlx_get_data_addr(data->img_text1, &data->bpp_1,
			&data->size_line_1, &data->endian_1);
	data->color_data_2 = mlx_get_data_addr(data->img_text2, &data->bpp_2,
			&data->size_line_2, &data->endian_2);
	data->color_data_3 = mlx_get_data_addr(data->img_text3, &data->bpp_3,
			&data->size_line_3, &data->endian_3);
	data->color_data_4 = mlx_get_data_addr(data->img_text4, &data->bpp_4,
			&data->size_line_4, &data->endian_4);
}

void	switch_map(t_data *data)
{
	int	i;
	int	j;

	data->s_map = malloc(sizeof(char *) * (data->mwidth + 1));
	if (!data->s_map)
		exit(1);
	i = -1;
	while (++i < data->mwidth)
	{
		data->s_map[i] = malloc(sizeof(char) * data->mhight);
		if (!data->s_map)
		{
			ft_putstr_fd("Erorr can't malloc\n", 2);
			exit(1);
		}
		j = -1;
		while (++j < data->mhight)
			data->s_map[i][j] = data->map[j][i];
	}
	data->s_map[i] = NULL;
	free__tab(&data->map);
	data->map = data->s_map;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		write (2, "Error invalide arg\n", 20);
		return (1);
	}
	if ((WIN_WIDTH > 1800 || WIN_HEIGHT < 1)
		|| (WIN_WIDTH > 5120 || WIN_HEIGHT < 1))
	{
		ft_putstr_fd("Erorr window size\n", 2);
		exit (1);
	}
	if (!check_map(av[1], &data))
		return (1);
	setup(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	inital_img_texture(&data);
	mlx_hook(data.win, 2, 0, key_handler, &data);
	mlx_hook(data.win, 3, 0, key_handler_, &data);
	mlx_hook(data.win, 17, 0, exit_hook, &data);
	mlx_loop_hook(data.mlx, &dda_algo, &data);
	mlx_loop(data.mlx);
	return (0);
}
