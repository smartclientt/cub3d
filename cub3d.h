/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:21:25 by shbi              #+#    #+#             */
/*   Updated: 2023/01/30 16:24:03 by shbi             ###   ########.fr       */
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

# define WIN_WIDTH	800
# define WIN_HEIGHT	600

# define MAP_WIDTH 24
# define MAP_HEIGHT 24

#define MOVE_SPEED	0.1
#define ROT_SPEED	0.1

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
	t_vec	new_dir;
	int		move;
	int		slide;
	int		rotate;
	// texture variables
	void	*img_text1;
	void	*img_text2;
	void	*img_text3;
	void	*img_text4;
	int		img_width;
	int		img_height;
	int		img_width_1;
	int		img_height_1;
	int		img_width_2;
	int		img_height_2;
	int		img_width_3;
	int		img_height_3;
	int		img_width_4;
	int		img_height_4;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step_;
	char	*color_data;
	char	*color_data_1;
	char	*color_data_2;
	char	*color_data_3;
	char	*color_data_4;
	int		bpp_1;
	int		size_line_1;
	int		endian_1;
	int		bpp_2;
	int		size_line_2;
	int		endian_2;
	int		bpp_3;
	int		size_line_3;
	int		endian_3;
	int		bpp_4;
	int		size_line_4;
	int		endian_4;
	// img to draw
	void	*win_img;
	char	*addr_win_img;
	int		bpp_img_win;
	int		size_line_img;
	int		endian_img_win;
	
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
int		dda_algo(t_data *data);
void	raycasting(t_data *data);
void	calcule_delta_dist(t_data *data);
void	init_data_vec(t_data *data);
void	calcule_step_and_sidedist(t_data *data);
void	hit_wall(t_data *data);
void	calcule_perp_wall_dest(t_data *data);
void	draw_wall(t_data *data, t_draw *draw, int x);
void	draw_ray_line(t_data *data, t_draw *draw, int x);

// Key handler
int		key_handler(int keycode, t_data *data);
int		exit_hook(t_data *data);
// move and rotate player
void	move(t_data *data);
void	move_down(t_data *data);
void	rotate(t_data *data);
void	slide(t_data *data);

// texture
void	inital_img_texture(t_data *data);
void	build_texture(t_data *data, t_draw *draw, int x);
void	whish_texture(t_data *data, t_draw *draw);
void	texture_info(t_data *data);


//zbel hachack
int	key_handler_(int keycode, t_data *data);

#endif