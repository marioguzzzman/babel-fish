/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:16:14 by maguzman          #+#    #+#             */
/*   Updated: 2026/05/26 15:52:24 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void * (*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*newnode;

	result = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (newnode == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, newnode);
		lst = lst->next;
	}
	return (result);
}

/*
DESCRIPTION
Iterates through the list ’lst’, applies the
function ’f’ to each node’s content, and creates
a new list resulting of the successive applications
of the function ’f’. The ’del’ function is used to
delete the content of a node if needed.

RETURN VALUES
The new list.
NULL if the allocation fails.
*/
