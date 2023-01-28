/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 21:28:10 by shbi              #+#    #+#             */
/*   Updated: 2023/01/27 01:23:11 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fre(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	return (*s);
}

char	*get_line(char **f_line)
{
	char	*line;
	char	*n_line;

	if (ft_strchr(*f_line, '\n') || *f_line[0] == '\n')
	{
		line = ft_substr(*f_line, 0, ft_strchr(*f_line, '\n') + 1);
		n_line = ft_strdup(*f_line + ft_strchr(*f_line, '\n') + 1);
		ft_fre(f_line);
		*f_line = n_line;
		return (line);
	}
	else if (ft_strlen(*f_line))
	{
		line = ft_strdup(*f_line);
		ft_fre(f_line);
		return (line);
	}
	ft_fre(f_line);
	return (NULL);
}

char	*get_first_line(int fd, char **f_line)
{
	int		r;
	char	*buffer;
	char	*tmp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_fre(f_line));
	r = 1;
	while (r)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			return (ft_fre(f_line));
		}
		buffer[r] = '\0';
		tmp = ft_strjoin(*f_line, buffer);
		ft_fre(f_line);
		*f_line = tmp;
		if (*f_line[0] == '\n' || ft_strchr(*f_line, '\n'))
			break ;
	}
	free(buffer);
	return (get_line(f_line));
}

char	*get_next_line(int fd)
{
	static char	*f_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!f_line)
		f_line = ft_strdup("");
	return (get_first_line(fd, &f_line));
}
