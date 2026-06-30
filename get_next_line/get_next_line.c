/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 10:57:18 by maguzman          #+#    #+#             */
/*   Updated: 2026/06/30 16:20:45 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		left_o = NULL;
		return (NULL);
	}
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
