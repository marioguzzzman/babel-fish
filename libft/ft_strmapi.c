/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strmapi.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: maguzman <maguzman@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/24 23:31:10 by maguzman         #+#    #+#              */
/*   Updated: 2026/05/24 23:42:57 by maguzman        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft(char const *s, char (*f)(unsigned int, char))
{
}

/*
DESCRIPTION
Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to store the
results from the successive applications of f.

PARAMETERS
s: The string to iterate over.
f: The function to apply to each character.

RETURN VALUES
The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.

*/
