/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:21:28 by shbi              #+#    #+#             */
/*   Updated: 2023/01/25 01:41:49 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_algo(t_data *data)
{
	raycasting(data);
}

int	main(void)
{
	t_data	data;

	init_data_vec(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	dda_algo(&data);
	mlx_hook(data.win, 2, 0, key_handler, &data);
	mlx_loop(data.mlx);
	return (0);
}
