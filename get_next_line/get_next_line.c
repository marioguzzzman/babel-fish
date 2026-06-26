/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 10:57:18 by maguzman          #+#    #+#             */
/*   Updated: 2026/06/27 01:46:35 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 1. Start with whatever's in static leftover (could be empty, first call)
2. Loop: read a chunk, append to leftover
3. Check: does leftover now contain a \n?
4. If yes → split at \n, return piece 1, save piece 2 as new leftover, stop looping
5. If no → loop back to step 2 (read more)
*/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	ssize_t		b_read;
	static char	*left_o;
	char		*combined;
	char		*line;
	int			nl_pos;
	int			end;
	char		*temp;

	buf = malloc(BUFFER_SIZE + 2);
	if (buf == NULL)
		return (NULL);
	b_read = read(fd, buf, BUFFER_SIZE);
	if (b_read == -1)
		return (NULL);
	if (b_read == 0)
	{
		if (left_o == NULL)
			return (NULL);
		else
		{
			free(buf);
			line = left_o;
			left_o = NULL;
			return (line);
		}
	}
	buf[b_read] = '\0';
	while (fd >= 0 && b_read > 0)
	{
		if (left_o == NULL)
			temp = "";
		else
			temp = left_o;
		combined = ft_strjoin(temp, buf);
		free(left_o);
		if (!ft_strchr(combined, '\n'))
		{
			b_read = read(fd, buf, BUFFER_SIZE);
			if (b_read == -1)
			{
				left_o = NULL;
				return (NULL);
			}
			buf[b_read] = '\0';
			left_o = combined;
		}
		else
		{
			nl_pos = ft_strchr(combined, '\n') - combined;
			line = ft_substr(combined, 0, nl_pos + 1);
			end = ft_strlen(combined);
			left_o = ft_substr(combined, nl_pos + 1, end);
			free(combined);
			free(buf);
			return (line);
		}
	}
	free(buf);
	line = left_o;
	left_o = NULL;
	return (line);
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
