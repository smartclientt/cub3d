/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:21:25 by shbi              #+#    #+#             */
/*   Updated: 2023/01/25 03:48:57 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line/get_next_line.h"

# define WIN_WIDTH	720
# define WIN_HEIGHT	576

# define MAP_WIDTH 24
# define MAP_HEIGHT 24

#define MOVE_SPEED	0.7
#define ROT_SPEED	0.4

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_vec	pos;	
	t_vec	raydir;
	t_vec	plane;
	t_vec	dir;
	t_vec	delta_dist;
	t_vec	side_dist;
	t_vec	map;
	double	perp_wall_dist;
	t_vec	step;
	int		hit;
	int		side;
	double	camera_x;
	t_vec	old_dir;
	t_vec	old_plane;
}	t_data;

typedef struct s_draw
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;
}	t_draw;

//libft functions 
int		ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *f_line, char *buffer);

// DDA algorithme
void	dda_algo(t_data *data);
void	raycasting(t_data *data);
void	calcule_delta_dist(t_data *data);
void	init_data_vec(t_data *data);
void	calcule_step_and_sidedist(t_data *data);
void	hit_wall(t_data *data);
void	calcule_perp_wall_dest(t_data *data);
void	draw_wall(t_data *data, t_draw *draw);
void	draw_ray_line(t_data *data, t_draw *draw, int x);

// Key handler
int		key_handler(int keycode, t_data *data);
// move and rotate player
void	move_up(t_data *data);
void	move_down(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data	*data);

#endif