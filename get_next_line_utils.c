/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fobiol-b <fobiol-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:50:14 by fobiol-b          #+#    #+#             */
/*   Updated: 2022/01/26 19:58:35 by fobiol-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	to_find;

	to_find = (unsigned char) c;
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

size_t	ft_strlen(const char *str)
{
	int		counter;

	counter = 0;
	while (*str != '\0')
	{
		str++;
		counter++;
	}
	return (counter);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		j;
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	i = 0;
	j = dest_size;
	if (dstsize == 0)
		return (src_size);
	if (dest_size < (dstsize - 1))
	{
		while (src[i] != '\0' && ((dest_size + i) < (dstsize) - 1))
		{
			dst[j++] = src [i++];
		}
		dst[j] = '\0';
	}
	if (dest_size >= dstsize)
		return (dstsize + src_size);
	return (dest_size + src_size);
}

/*char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		size1;
	int		size2;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	result = malloc(size1 + size2 + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, size1 + 1);
	ft_strlcat(result, s2, size1 + size2 + 1);
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*src_start;

	src_start = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((*src != '\0') && ((dstsize - 1) > 0))
	{
		*dst = *src;
		src++;
		dst++;
		dstsize--;
	}
	*dst = '\0';
	return (ft_strlen(src_start));
}*/