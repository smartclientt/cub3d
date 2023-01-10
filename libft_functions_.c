/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:00:37 by shbi              #+#    #+#             */
/*   Updated: 2023/01/07 02:37:12 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(char *s1)
{
	char	*ps;
	int		i;

	i = -1;
	ps = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ps)
		return (NULL);
	while (s1[++i])
		ps[i] = s1[i];
	ps[i] = '\0';
	return (ps);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*d;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	d = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
		return (NULL);
	i = -1;
	while (s1[++i])
		d[i] = s1[i];
	j = -1;
	while (s2[++j])
		d[i++] = s2[j];
	d[i] = '\0';
	return (d);
}
