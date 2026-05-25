/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:51:48 by maguzman          #+#    #+#             */
/*   Updated: 2026/05/25 17:35:05 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;
	t_list	*current;

	if (lst == NULL)
		return ;
	current = *lst;
	buffer = current->next;
	while (current->next != NULL)
	{
		*buffer = current->next;
		ft_lstdelone(current);
		current++;
	}
}

/*
DESCRIPTION
Deletes and frees the given node and all its
successors, using the function ’del’ and free(3).
Finally, set the pointer to the list to NULL.

*/
