/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:00:58 by maguzman          #+#    #+#             */
/*   Updated: 2026/06/30 12:55:07 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
ft_strlen	Calculates string length
ft_strdup	Duplicates strings
ft_strchr	Searches for a character inside a string
ft_strjoin	Concatenates two strings
*/

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	if (size == 0)
		return (slen);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (slen);
}

/*
DESCRIPTION
It copies a string with a safety guard of taking the full size of the buffer
and making sure thee is space to NUL-temrinate the result. As long as size > 0.
Important to make sure NUL is included in size and therefore to have size - 1.
It operates in true "c" strings, meaning that they only take
NUL-terminated strings.

RETURN VALUES
It returns the total length of the string they tried to create.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
		i++;
	}
	if ((char) c == '\0')
		return ((char *) & s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc((s1_len + s2_len) + 1);
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, s1_len + 1);
	ft_strlcpy(s3 + s1_len, s2, s2_len + 1);
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	copy_len;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (s_len - start < len)
		copy_len = s_len - start;
	else
		copy_len = len;
	ptr = malloc(copy_len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s + start, copy_len + 1);
	return (ptr);
}
