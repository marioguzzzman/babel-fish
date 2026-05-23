/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguzman <maguzman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:34:33 by maguzman          #+#    #+#             */
/*   Updated: 2026/05/23 02:50:34 by maguzman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static void	get_words(char const *s, char c, char **array);

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (array == NULL)
		return (NULL);
	get_words(s, c, array);
	return (array);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	if (s[i] != c && s[i] != '\0')
		word_count++;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			word_count++;
		i++;
	}
	return (word_count);
}

static void	get_words(char const *s, char c, char **array)
{
	int	i;
	int	j;
	int	start;
	int	len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			len = 0;
			while (s[i] != c && s[i] != '\0')
			{
				len++;
				i++;
			}
			array[j++] = ft_substr(s, start, len);
		}
		else
			i++;
	}
	array[j] = NULL;
}

/*
DESCRIPTION
Allocates memory (using malloc(3)) and returns an
array of strings obtained by splitting ’s’ using
the character ’c’ as a delimiter.
Each string in the returned array is allocated
independently.
The array of pointers itself is also allocated
dynamically.
The returned array must be NULL terminated.

PARAMETERS
s: The string to be split.
c: The delimiter character.

RETURN VALUES
The array of new strings resulting from the split.
NULL if any allocation fails.
The returned structure will be released using: 1)
free() on each string in the array; 2) free() the
array itself.

NOTES
// 2D pointer to a pointer to an int
**array = malloc(sizeof(int *) * n_array);
//Syntax for introducing the 5 into the first element of the first array
array[0][0] = 5;

//is it more costly to allocate this on the heap, than a 1D on the stack

*/
