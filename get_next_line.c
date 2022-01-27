/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fobiol-b <fobiol-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:32:38 by fobiol-b          #+#    #+#             */
/*   Updated: 2022/01/27 16:11:36 by fobiol-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		*saved_read;
	char 			*line;
	char			*read_buffer;
	size_t			read_characters;

	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read_buffer == NULL)
		return (NULL);	
	printf("hola1\n");
	saved_read = "";
	char *end_position = ft_strchr(saved_read, '\n');
	printf("hola2\n");
	read_characters = 43;
	while(end_position == NULL || read_characters < BUFFER_SIZE) 
	{
		read_characters = read(fd, read_buffer, BUFFER_SIZE);
		saved_read = ft_strjoin(saved_read, read_buffer);
		end_position = ft_strchr(saved_read, '\n');
	}
	line = ft_substr(saved_read, 0, end_position - saved_read);
	return (line);
}

