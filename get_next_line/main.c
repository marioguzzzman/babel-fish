/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:15:04 by maguzman          #+#    #+#             */
/*   Updated: 2026/06/30 13:29:25 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd = open("test.txt", O_RDONLY | O_CREAT);
	char	*line = "";

	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			printf("end of file");
		}
		else
			printf("line: %s", line);
	}
	free(line);
	return (0);
}
