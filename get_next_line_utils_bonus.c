/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fobiol-b <fobiol-b@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:53:41 by fobiol-b          #+#    #+#             */
/*   Updated: 2022/02/04 11:53:45 by fobiol-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	unsigned int	j;

	if (ft_strlen(s) < len)
		ret = (char *)malloc(ft_strlen(s) + 1);
	else if (ft_strlen(s) < start)
		ret = (char *)malloc(1);
	else
		ret = (char *)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ret[j] = s[i];
			j ++;
		}
		i ++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
}
