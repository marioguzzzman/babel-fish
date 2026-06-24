/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: maguzman <maguzman@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/06/23 10:57:18 by maguzman         #+#    #+#              */
/*   Updated: 2026/06/24 12:26:48 by maguzman        ###   ########.fr        */
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
	size_t		BUFFER_SIZE;
	static char	*buf;

	buf = NULL;
	fd = read(fd, buf, BUFFER_SIZE);
	if (fd == -1)
		return (NULL);
	while (buf[0] != 0 & fd > 0)
	{
	}
	if (fd == 0)
		return (NULL);
	else
		return (fd);
}
