/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: maguzman <maguzman@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/29 23:09:04 by maguzman         #+#    #+#              */
/*   Updated: 2026/05/23 21:24:02 by maguzman        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <limits.h>
#include <stdint.h>

void	OK(char *name)
{
	printf("%s test: OK✓\n", name);
}

void	test_ft_memchr(void)
{
}

// Helper: count words in resulting array

static int	count_array_elements(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (-1);
	while (array[i] != NULL)
		i++;
	return (i);
}

// Helper: free the array

static void	free_split(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

// Test function

void	test_ft_split(void)
{
	char	**result;

	// Test 1: Normal split
	result = ft_split("hello world test", ' ');
	assert(count_array_elements(result) == 3);
	assert(strcmp(result[0], "hello") == 0);
	assert(strcmp(result[1], "world") == 0);
	assert(strcmp(result[2], "test") == 0);
	free_split(result);
	OK("ft_split - normal");
	// Test 2: Multiple consecutive delimiters
	result = ft_split("a::b::c", ':');
	assert(count_array_elements(result) == 3);
	assert(strcmp(result[0], "a") == 0);
	assert(strcmp(result[1], "b") == 0);
	assert(strcmp(result[2], "c") == 0);
	free_split(result);
	OK("ft_split - multiple consecutive delimiters");
	// Test 3: Single word
	result = ft_split("hello", ' ');
	assert(count_array_elements(result) == 1);
	assert(strcmp(result[0], "hello") == 0);
	free_split(result);
	OK("ft_split - single word");
	// Test 4: Empty string
	result = ft_split("", ' ');
	assert(count_array_elements(result) == 0);
	free_split(result);
	OK("ft_split - empty string");
	// Test 5: String starting with delimiter
	result = ft_split(" hello", ' ');
	assert(count_array_elements(result) == 1);
	assert(strcmp(result[0], "hello") == 0);
	free_split(result);
	OK("ft_split - starting with delimiter");
	// Test 6: String ending with delimiter
	result = ft_split("hello ", ' ');
	assert(count_array_elements(result) == 1);
	assert(strcmp(result[0], "hello") == 0);
	free_split(result);
	OK("ft_split - ending with delimiter");
	// Test 7: String with leading and trailing delimiters
	result = ft_split(" hello world ", ' ');
	assert(count_array_elements(result) == 2);
	assert(strcmp(result[0], "hello") == 0);
	assert(strcmp(result[1], "world") == 0);
	free_split(result);
	OK("ft_split - leading and trailing delimiters");
	// Test 8: Only delimiters
	result = ft_split("   ", ' ');
	assert(count_array_elements(result) == 0);
	free_split(result);
	OK("ft_split - only delimiters");
	// Test 9: Delimiter not found
	result = ft_split("hello", 'x');
	assert(count_array_elements(result) == 1);
	assert(strcmp(result[0], "hello") == 0);
	free_split(result);
	OK("ft_split - delimiter not found");
	// Test 10: Single character
	result = ft_split("a", ' ');
	assert(count_array_elements(result) == 1);
	assert(strcmp(result[0], "a") == 0);
	free_split(result);
	OK("ft_split - single character");
}

/* ********** SIMPLE ************* */

void	test_ft_isalpha(void)
{
	assert(ft_isalpha('A') == 1);
	assert(ft_isalpha('z') == 1);
	assert(ft_isalpha('@') == 0);
	assert(ft_isalnum('{') == 0);
	OK("ft_isalpha");
}

void	test_ft_isdigit(void)
{
	assert(ft_isdigit('0') == 1);
	assert(ft_isdigit('9') == 1);
	assert(ft_isdigit('a') == 0);
	assert(ft_isalnum('/') == 0);
	OK("ft_isdigit");
}

void	test_ft_isprint(void)
{
	assert(ft_isprint('\0') == 0);
	assert(ft_isprint('a') == 1);
	OK("ft_isprint");
}

void	test_ft_isalnum(void)
{
	assert(ft_isalnum('0') == 1);
	assert(ft_isalnum('9') == 1);
	assert(ft_isalnum('A') == 1);
	assert(ft_isalnum('z') == 1);
	assert(ft_isalnum('{') == 0);
	assert(ft_isalnum('/') == 0);
	OK("ft_isalnum");
}

int	main(void)
{
	char	c;
	char	str[] = "1hEllo";
	char	dest[] = "82345";
	char	str2[] = "0123456789";
	char	str3[] = "0123456789";
	/* ******************************* */

	printf("ft_itoa: %s\n", ft_itoa(42));
	printf("ft_itoa: %s\n", ft_itoa(-42));
	printf("ft_itoa: %s\n", ft_itoa(0));
	/* ********** STRING ************* */
	/* ********** ft_strchr ************* */
	printf("\n");
	printf("Str: %s\n", str);
	printf("ft_strchr: %s\n", (char *) ft_strchr(str, 'l'));
	printf("O strchr: %s\n", (char *) strchr(str, 'l'));
	/* ********** ft_strrchr ************* */
	printf("\n");
	printf("Str: %s\n", str);
	printf("ft_strchr: %s\n", (char *) ft_strrchr(str, 'l'));
	printf("O strchr: %s\n", (char *) strrchr(str, 'l'));
	/* ********** ft_strlcpy ************* */
	printf("\n");
	char	destEmpty[50];
	char	str1[] = "is he";

	printf("str1: %s\n", str);
	printf("ft_strlcpy: %ld\n", ft_strlcpy(destEmpty, str1, 4));
	printf("strlcpy: %ld\n", strlcpy(destEmpty, str1, 4));
	/* ********** ft_strlen ************* */
	printf("\n");
	printf("Str: %s\n", str);
	printf("ft_strlen: %ld", ft_strlen(str));
	printf("  | strlen: %ld\n", strlen(str));
	/* ********** ft_strlcpy ************* */
	printf("\n");
	char	destcpy_cat[] = "we are";
	char	srcpy_cat[] = " here";

	printf("REVIEW\n");
	printf("destcpy_cat: %s\n", destcpy_cat);
	printf("srcpy_cat: %s\n", srcpy_cat);
	printf("ft_strlcpy: %ld\n", ft_strlcpy(destcpy_cat, srcpy_cat, 4));
	printf("O strlcpy: %ld\n", strlcpy(destcpy_cat, srcpy_cat, 4));
	printf("\n");
	/* ********** ft_strlcat ************* */
	printf("\n");
	printf("destcpy_cat: %s\n", destcpy_cat);
	printf("srcpy_cat: %s\n", srcpy_cat);
	printf("ft_strcat: %ld\n", ft_strlcat(destcpy_cat, srcpy_cat, 4));
	printf("O strcat: %ld\n", strlcat(destcpy_cat, srcpy_cat, 4));
	printf("\n");
	/* ********** ft_bzero ************* */
	printf("\n");
	ft_bzero(str, 3);
	printf("ft_bzero: %s", str);
	bzero(str, 3);
	printf("  | bzero: %s\n", str);
	/* ********** MEMORY ************* */
	/* ********** ft_memset ************* */
	printf("\n");
	printf("ft_memset &: %p", ft_memset(str + 3, '#', 3));
	printf("  | memset &: %p\n", memset(str + 3, '#', 3));
	printf("ft_memset s: %s", (char *) ft_memset(str + 3, '#', 3));
	printf("             | memset s: %s\n", (char *) ft_memset(str + 3, '#', 3));
	/* ********** ft_memcpy ************* */
	printf("\n");
	printf("ft_memcpy: %s", (char *) ft_memcpy(dest + 2, str1, 4));
	printf("  | memcpy: %s\n", (char *) memcpy(dest + 2, str1, 4));
	/* ********** ft_memmove ************* */
	printf("\n");
	printf("ft_memmove: %s", (char *) ft_memmove(str2, str2, 3));
	printf("  | memmove: %s\n", (char *) memmove(str2, str2, 3));
	printf("ft_memmove REV: %s", (char *) ft_memmove(str2 + 2, str2, 3));
	printf("  | memmove REV: %s\n", (char *) memmove(str3 + 2, str3, 3));
	/* ********** ft_memchr ************ */
	printf("\n");
	printf("ft_memchr: %s", (char *) ft_memchr("hello", 'e', 3));
	char	s[] = "hello";
	char	*result = memchr(s, 'e', 3);

	printf("  | memchr: %s\n", result);
	/* ********** ft_memcmp ************ */
	printf("\n");
	char	str1mem[] = "12345678901400345678";
	char	str2mem[] = "1234567";

	printf("ft_memcmp: %d", ft_memcmp(str1mem, str2mem, 5));
	printf("  | memcmp: %d\n", memcmp(str1mem, str2mem, 5));
	printf("\n");
	printf("ft_memcmp: %d", ft_memcmp(str1mem, str2mem, 8));
	printf("  | memcmp: %d\n", memcmp(str1mem, str2mem, 8));
	printf("\n");
	/* ********** LETTER ************* */
	/* ********** ft_atoi ************* */
	const char	*nb_str = " ---+--+1234ab567";

	printf("%d\n", ft_atoi(nb_str));
	nb_str = "-2147483647";
	printf("%d\n", ft_atoi(nb_str));
	nb_str = "0";
	printf("%d\n", ft_atoi(nb_str));
	nb_str = "10";
	printf("%d\n", ft_atoi(nb_str));
	nb_str = "2147483647";
	printf("%d\n", ft_atoi(nb_str));
	/* ********** ft_tolower / ft_toupper ************* */
	char	strLU[] = "1hEllo";

	printf("ft_tolower: %c", ft_tolower(strLU[2]));
	printf("  | tolower: %c\n", tolower(strLU[2]));
	printf("ft_toupper: %c", ft_toupper(strLU[1]));
	printf("  | toupper: %c\n", toupper(strLU[1]));
	/* ********** ft_isascii ************* */
	c = ' ';
	printf("\n");
	printf("Test char: %c\n", c);
	printf("\n");
	printf("ft_isascii: %d", ft_isascii(c));
	printf("  | isascii: %d\n", isascii(c));
	printf("\n");
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isprint();
	test_ft_isalnum();
	/* ********** MEMORY  ************* */
	test_ft_memchr();
	/* ********** STRING SPLIT ************* */
	test_ft_split();
	return (0);
}
