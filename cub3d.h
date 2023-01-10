/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:21:25 by shbi              #+#    #+#             */
/*   Updated: 2023/01/10 06:22:44 by shbi             ###   ########.fr       */
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

int map[MAP_WIDTH][MAP_HEIGHT] =
{
	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,2 ,2 ,2 ,2 ,2 ,0 ,0 ,0 ,0 ,3 ,0 ,3 ,0 ,3 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,2 ,2 ,0 ,2 ,2 ,0 ,0 ,0 ,0 ,3 ,0 ,3 ,0 ,3 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,0 ,4 ,0 ,0 ,0 ,0 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,0 ,0 ,0 ,0 ,5 ,0 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,0 ,4 ,0 ,0 ,0 ,0 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },*
	{1 ,4 ,0 ,4 ,4 ,4 ,4 ,4 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 },
	{1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 }
};

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_vec	pos;
	double	time;
	double	oldtime;	
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
}	t_data;

typedef struct s_draw
{
	int	line_height;
	int	draw_start;
	int	draw_end;
}	t_draw;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

//libft functions 
int		ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *f_line, char *buffer);

// DDA algorithme
void	dda_algorithm(t_data *data);
void	raycasting(t_data *data);
void	calcule_delta_dist(t_data *data);

#endif