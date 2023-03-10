/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playermap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:07:11 by ael-idri          #+#    #+#             */
/*   Updated: 2023/02/01 23:19:22 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*str_refine(char *str, int width)
{
	char	*spacestr;
	char	*trim_nline;
	char	*tmp;
	int		i;

	i = 0;
	if (width - (int)ft_strlen_n(str) == 0)
		return (ft_substr(str, 0, ft_strlen_n(str)));
	spacestr = (char *)malloc(sizeof(char) * (width - ft_strlen_n(str) + 1));
	if (!spacestr)
		return (NULL);
	while (i < (width - ft_strlen_n(str)))
		spacestr[i++] = ' ';
	spacestr[i] = '\0';
	trim_nline = trim_n_line(str);
	tmp = ft_strjoin(trim_nline, spacestr);
	free(trim_nline);
	free(spacestr);
	return (tmp);
}

bool	init_playermap(t_data *data)
{
	int	i;

	i = 0;
	data->mhight = tab__length(data->o_map + 6);
	data->mwidth = max_width(data->o_map + 6);
	data->map = (char **)malloc(sizeof(char *) * (data->mhight + 1));
	if (!data->map)
		return (false);
	while (i < data->mhight)
	{
		data->map[i] = str_refine(data->o_map[i + 6], data->mwidth);
		if (!data->map[i])
			return (false);
		i++;
	}
	data->map[i] = NULL;
	return (true);
}

bool	check_map_elem(int *player_nb, t_data *data, int i, int j)
{
	if (data->map[i][j] == '0')
	{
		if (!check_zero_sides(data->map, i, j))
			return (printf("map border is open !!\n"), false);
	}
	else if (is_player(data->map[i][j]))
	{	
		if ((++(*player_nb)) != 1)
			return (printf("player (number) !valid\n"), false);
		if (!check_zero_sides(data->map, i, j))
			return (printf("player position !valid\n"), false);
		data->pos.x = (double)j + 0.6;
		data->pos.y = (double)i + 0.6;
		init_dir_vector(data, i, j);
		init_dir_vector_(data, i, j);
	}
	else if (data->map[i][j] != ' ' && data->map[i][j] != '1')
		return (printf("caracter not valid\n"), false);
	return (true);
}

bool	pmap_valid(t_data	*data)
{
	int	i;
	int	j;
	int	player_nb;

	i = -1;
	player_nb = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (!check_map_elem(&player_nb, data, i, j))
				return (false);
		}
	}
	if (player_nb != 1)
		return (printf("player position(number) !valid\n"), false);
	return (true);
}

bool	check_player_map(t_data *data)
{
	if (!init_playermap(data))
	{
		printf("fail init map!!\n");
		return (false);
	}
	if (!pmap_valid(data))
	{
		printf("player map not valide\n");
		return (false);
	}
	return (1);
}
