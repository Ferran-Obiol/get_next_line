/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fobiol-b <fobiol-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:14:43 by fobiol-b          #+#    #+#             */
/*   Updated: 2022/02/04 12:58:33 by fobiol-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	to_find;

	to_find = (unsigned char) c;
	if (!s)
		return (NULL);
	while (*s != 0)
	{
		if (*s == to_find)
			return ((char *)s);
		s++;
	}
	if (to_find == 0)
		return ((char *)s);
	return (NULL);
}

static char	*get_buff_until_n(char *saved_read)
{
	char	*end_position;

	if (*saved_read == '\0')
		return (NULL);
	end_position = ft_strchr(saved_read, '\n');
	if (end_position)
		return (ft_substr(saved_read, 0, end_position - saved_read + 1));
	else
		if (*saved_read == 0)
			return (NULL);
	return (ft_substr(saved_read, 0, ft_strlen(saved_read) + 1));
}

static char	*clean_buffer(char *saved_read)
{	
	char	*end_position;
	char	*result;

	end_position = ft_strchr(saved_read, '\n');
	if (end_position)
		result = ft_substr(saved_read, end_position - saved_read + 1,
				(saved_read + ft_strlen(saved_read)) - end_position + 1);
	else
	{
		result = NULL;
	}
	free(saved_read);
	return (result);
}

static char	*read_until_next_line(char *saved_read, int fd)
{
	char	*read_buffer;
	int		read_characters;
	char	*tmp;

	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read_buffer == NULL)
		return (NULL);
	read_characters = 1;
	while (!ft_strchr(saved_read, '\n') && read_characters > 0)
	{	
		read_characters = read(fd, read_buffer, BUFFER_SIZE);
		if (read_characters == -1)
		{
			free(saved_read);
			free(read_buffer);
			return (NULL);
		}
		read_buffer [read_characters] = '\0';
		tmp = ft_strjoin(saved_read, read_buffer);
		free(saved_read);
		saved_read = tmp;
	}
	free(read_buffer);
	return (saved_read);
}

char	*get_next_line(int fd)
{
	static char		*saved_read[MAX_FD];
	char			*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (saved_read[fd] == NULL)
	{
		saved_read[fd] = (char *)malloc(1);
		saved_read[fd][0] = 0;
	}
	saved_read[fd] = read_until_next_line(saved_read[fd], fd);
	if (saved_read[fd] == NULL)
		return (NULL);
	line = get_buff_until_n(saved_read[fd]);
	saved_read[fd] = clean_buffer(saved_read[fd]);
	return (line);
}
