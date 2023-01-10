/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:28:05 by shbi              #+#    #+#             */
/*   Updated: 2022/11/03 18:25:46 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substr(char *f_line, int start, int len)
{
	char	*ps;
	int		i;

	if (!f_line)
		return (0);
	if (start > ft_strlen(f_line))
		return (ft_strdup(""));
	if (ft_strlen(f_line) < len)
		len = ft_strlen(f_line);
	ps = (char *)malloc(sizeof(char) * (len + 1));
	if (!ps)
		return (NULL);
	i = -1;
	while (++i < len)
		ps[i] = f_line[start + i];
	ps[i] = '\0';
	return (ps);
}
