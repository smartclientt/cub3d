/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:21:25 by shbi              #+#    #+#             */
/*   Updated: 2023/02/01 23:02:54 by shbi             ###   ########.fr       */
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
# include <stdbool.h> 
# include <string.h>
# include <errno.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"

# define WIN_WIDTH	800
# define WIN_HEIGHT	600

# define MOVE_SPEED 0.08
# define ROT_SPEED 0.1
# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F 5
# define C 6

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef union u_color
{
	unsigned char	rgb[4];
	int				color;
}			t_color;

typedef struct s_data
{
	char	**o_map;
	char	**map;
	char	**s_map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	int		mhight;
	int		mwidth;
	int		px;
	int		py;
	void	*mlx;
	void	*win;
	t_vec	pos;
	t_vec	raydir;
	t_vec	plane;
	t_vec	dir;
	t_vec	delta_dist;
	t_vec	side_dist;
	t_vec	map_;
	double	perp_wall_dist;
	t_vec	step;
	int		hit;
	int		side;
	double	camera_x;
	t_vec	old_dir;
	t_vec	old_plane;
	t_vec	new_dir;
	int		rot_dir;
	int		move;
	int		slide;
	int		rotate;
	int		rotate_mousse;
	int		x_code;
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
	void	*win_img;
	char	*addr_win_img;
	int		bpp_img_win;
	int		size_line_img;
	int		endian_img_win;
	t_color	ceilling;
	t_color	floor;
}	t_data;

typedef struct s_draw
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;
}	t_draw;

//		parsing/utils.c
int		ft_type(char *str);
char	*trim(char *str, char **dist);
bool	ft_isdigit(char *str);
void	free__tab(char ***tab);
int		tab__length(char **map);

//		parsing/utlis1.c
bool	check_tab(int *tab);
bool	check_range(int n);
int		check_length(char **tab);
int		max_width(char **str);
bool	check_xpm(char *str);

//		parsing/utils2.c
bool	is_player(char c);
int		ft_strlen_n(const char *s);
bool	check_zero_sides(char **player_map, int i, int j);
char	*trim_n_line(char *str);

//		parsing/read_map.c
bool	check_in(char *str);
bool	is_emptyline(char **line, int i);
int		ft_open(char *file);
char	**ft_realoc(char **tab, int size);
bool	read_map(char *file, t_data *data);

//		parsing/check_assets.c
bool	get_texture(t_data *data, int type, int index);
bool	parse_color(t_data *data, int index, char flag);
bool	get_colors(t_data *data, int type, int index);
bool	parse_assets(t_data *data);
bool	check_assets(t_data *data);

//		parsing/check_playermap.c
bool	check_player_map(t_data *data);
bool	pmap_valid(t_data	*data);
bool	check_map_elem(int *player_nb, t_data *data, int i, int j);
bool	init_playermap(t_data *data);
char	*str_refine(char *str, int width);

//		parsing/map_checker.c
void	init_data(t_data *data);
bool	check_map(char *str, t_data *data);
void	setup_player(t_data *data);
void	setup_color(int endian, unsigned char rgb[4], int color[4]);
void	switch_map(t_data *data);
void	setup(t_data *data);
void	protection_malloc(char **map);
void	protection_malloc_(char *map);

// DDA algorithme
int		dda_algo(t_data *data);
void	raycasting(t_data *data);
void	calcule_delta_dist(t_data *data);
void	init_data_vec(t_data *data);
void	init_dir_vector(t_data *data, int i, int j);
void	init_dir_vector_(t_data *data, int i, int j);
void	calcule_step_and_sidedist(t_data *data);
void	hit_wall(t_data *data);
void	calcule_perp_wall_dest(t_data *data);
void	draw_wall(t_data *data, t_draw *draw, int x);
void	draw_ray_line(t_data *data, t_draw *draw, int x);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Key handler
int		key_handler(int keycode, t_data *data);
int		key_handler_(int keycode, t_data *data);
int		key_handler__(int x, int y, t_data *data);
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

// mlx protection
void	*mmlx_init(void);
void	*mmlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	*mmlx_new_image(void *mlx_ptr, int size_x, int size_y);
char	*mmlx_get_data_addr(void *img, int *bpp, int *size_line, int *endian);
void	mmlx_destroy_window(void *mlx_ptr, void *img_ptr);
void	mmlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr);
void	mmlx_destroy_image(void *mlx_ptr, void *img_ptr);


#endif