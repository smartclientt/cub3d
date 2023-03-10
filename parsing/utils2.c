/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-idri <ael-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:18:58 by ael-idri          #+#    #+#             */
/*   Updated: 2023/02/01 23:19:00 by ael-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

int	ft_strlen_n(const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	str = (char *)s;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*trim_n_line(char *str)
{
	if (str[ft_strlen(str) - 1] == '\n')
		return (ft_substr(str, 0, ft_strlen(str) - 1));
	return (ft_strdup(str));
}

bool	check_zero_sides(char **player_map, int i, int j)
{
	if (i == 0 || j == 0 || i == check_length(player_map) - 1
		|| j == max_width(player_map) - 1)
		return (false);
	if (player_map[i - 1][j] == ' ')
		return (false);
	if (player_map[i + 1][j] == ' ')
		return (false);
	if (player_map[i][j - 1] == ' ')
		return (false);
	if (player_map[i][j + 1] == ' ')
		return (false);
	return (true);
}
