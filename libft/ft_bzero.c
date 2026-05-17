/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_bzero.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: maguzman <maguzman@student.42.fr>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/30 18:45:08 by maguzman         #+#    #+#              */
/*   Updated: 2026/04/30 18:56:56 by maguzman        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	int				i;
	unsigned char	*s;

	s = (unsigned char *) str;
	i = 0;
	while (n > 0)
	{
		s[i] = '\0';
		i++;
		n--;
	}
}
