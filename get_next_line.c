/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fobiol-b <fobiol-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:32:38 by fobiol-b          #+#    #+#             */
/*   Updated: 2022/01/26 20:02:39 by fobiol-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_buffer[BUFFER_SIZE];

char	*get_next_line(int fd)
{
	char	*buffer;
	size_t	read_characters;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read_characters = read(fd, buffer, BUFFER_SIZE);
	if (read_characters <= 0)
		return (NULL);

	return (buffer);
}

