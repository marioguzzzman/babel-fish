/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_calloc.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: maguzman <maguzman@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/19 11:55:03 by maguzman         #+#    #+#              */
/*   Updated: 2026/05/19 16:00:26 by maguzman        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (SIZE_MAX / size < nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

/*
** ft_calloc Allocates and zeros memory for an array
** @nmemb: number of elements
** @size: size of each element
** Returns a pointer to zeroed memory, or NULL if overflow or malloc fails
** Note: Check for overflow BEFORE allocating to prevent silent errors.
** Note: Returning NULL as a decision to handle when nmemb or size is 0
*/
