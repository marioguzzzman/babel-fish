/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   babel_tests.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: maguzman <maguzman@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/28 18:27:26 by maguzman         #+#    #+#              */
/*   Updated: 2026/05/28 18:27:26 by maguzman        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "libft.h"

/* ************************************************************************** */
/*  HOW TO COMPILE AND RUN:                                                   */
/*    gcc babel_tests.c ft_*.c -o babel_tests -lbsd && ./babel_tests                  */
/* ************************************************************************** */

/* ************************************************************************** */
/*  PART 1 - CHARACTER CHECKS                                                 */
/* ************************************************************************** */

void	test_isalpha(void)
{
	printf("\n--- ft_isalpha ---\n");
	printf("ft: %d | orig: %d  (input: 'a')\n", ft_isalpha('a'), isalpha('a') != 0);
	printf("ft: %d | orig: %d  (input: 'Z')\n", ft_isalpha('Z'), isalpha('Z') != 0);
	printf("ft: %d | orig: %d  (input: '5')\n", ft_isalpha('5'), isalpha('5') != 0);
	printf("ft: %d | orig: %d  (input: ' ')\n", ft_isalpha(' '), isalpha(' ') != 0);
}

void	test_isdigit(void)
{
	printf("\n--- ft_isdigit ---\n");
	printf("ft: %d | orig: %d  (input: '0')\n", ft_isdigit('0'), isdigit('0') != 0);
	printf("ft: %d | orig: %d  (input: '9')\n", ft_isdigit('9'), isdigit('9') != 0);
	printf("ft: %d | orig: %d  (input: 'a')\n", ft_isdigit('a'), isdigit('a') != 0);
	printf("ft: %d | orig: %d  (input: '/')\n", ft_isdigit('/'), isdigit('/') != 0);
}

void	test_isalnum(void)
{
	printf("\n--- ft_isalnum ---\n");
	printf("ft: %d | orig: %d  (input: 'a')\n", ft_isalnum('a'), isalnum('a') != 0);
	printf("ft: %d | orig: %d  (input: '3')\n", ft_isalnum('3'), isalnum('3') != 0);
	printf("ft: %d | orig: %d  (input: '{')\n", ft_isalnum('{'), isalnum('{') != 0);
	printf("ft: %d | orig: %d  (input: '/')\n", ft_isalnum('/'), isalnum('/') != 0);
}

void	test_isascii(void)
{
	printf("\n--- ft_isascii ---\n");
	printf("ft: %d | orig: %d  (input: 0)\n", ft_isascii(0), isascii(0));
	printf("ft: %d | orig: %d  (input: 127)\n", ft_isascii(127), isascii(127));
	printf("ft: %d | orig: %d  (input: 128)\n", ft_isascii(128), isascii(128));
}

void	test_isprint(void)
{
	printf("\n--- ft_isprint ---\n");
	printf("ft: %d | orig: %d  (input: ' ' = 32)\n", ft_isprint(' '), isprint(' ') != 0);
	printf("ft: %d | orig: %d  (input: '~' = 126)\n", ft_isprint('~'), isprint('~') != 0);
	printf("ft: %d | orig: %d  (input: 31)\n", ft_isprint(31), isprint(31) != 0);
	printf("ft: %d | orig: %d  (input: 127 DEL)\n", ft_isprint(127), isprint(127) != 0);
}

void	test_toupper(void)
{
	printf("\n--- ft_toupper ---\n");
	printf("ft: %c | orig: %c  (input: 'a')\n", ft_toupper('a'), toupper('a'));
	printf("ft: %c | orig: %c  (input: 'z')\n", ft_toupper('z'), toupper('z'));
	printf("ft: %c | orig: %c  (input: 'A' - no change)\n", ft_toupper('A'), toupper('A'));
	printf("ft: %c | orig: %c  (input: '1' - no change)\n", ft_toupper('1'), toupper('1'));
}

void	test_tolower(void)
{
	printf("\n--- ft_tolower ---\n");
	printf("ft: %c | orig: %c  (input: 'A')\n", ft_tolower('A'), tolower('A'));
	printf("ft: %c | orig: %c  (input: 'Z')\n", ft_tolower('Z'), tolower('Z'));
	printf("ft: %c | orig: %c  (input: 'a' - no change)\n", ft_tolower('a'), tolower('a'));
}

/* ************************************************************************** */
/*  PART 1 - STRING FUNCTIONS                                                 */
/* ************************************************************************** */

void	test_strlen(void)
{
	printf("\n--- ft_strlen ---\n");
	printf("ft: %zu | orig: %zu  (input: \"hello\")\n", ft_strlen("hello"), strlen("hello"));
	printf("ft: %zu | orig: %zu  (input: \"\")\n", ft_strlen(""), strlen(""));
	printf("ft: %zu | orig: %zu  (input: \"abc\")\n", ft_strlen("abc"), strlen("abc"));
}

void	test_strchr(void)
{
	const char	*s = "hello";

	printf("\n--- ft_strchr ---\n");
	printf("ft: %s | orig: %s  (find 'l' in \"hello\")\n",
		ft_strchr(s, 'l'), strchr(s, 'l'));
	printf("ft: %s | orig: %s  (find 'o' in \"hello\")\n",
		ft_strchr(s, 'o'), strchr(s, 'o'));
	printf("ft: %p | orig: %p  (find 'z' - not found, expect NULL)\n",
		(void *) ft_strchr(s, 'z'), (void *) strchr(s, 'z'));
}

void	test_strrchr(void)
{
	const char	*s = "hello";

	printf("\n--- ft_strrchr ---\n");
	printf("ft: %s | orig: %s  (last 'l' in \"hello\")\n",
		ft_strrchr(s, 'l'), strrchr(s, 'l'));
	printf("ft: %p | orig: %p  (find 'z' - not found, expect NULL)\n",
		(void *) ft_strrchr(s, 'z'), (void *) strrchr(s, 'z'));
}

void	test_strlcpy(void)
{
	char	ft_dst[20];
	char	orig_dst[20];
	size_t	ft_ret;
	size_t	orig_ret;

	printf("\n--- ft_strlcpy ---\n");
	ft_ret = ft_strlcpy(ft_dst, "hello", 20);
	orig_ret = strlcpy(orig_dst, "hello", 20);
	printf("ft: \"%s\" (ret %zu) | orig: \"%s\" (ret %zu)  (full copy)\n",
		ft_dst, ft_ret, orig_dst, orig_ret);
	ft_ret = ft_strlcpy(ft_dst, "hello", 3);
	orig_ret = strlcpy(orig_dst, "hello", 3);
	printf("ft: \"%s\" (ret %zu) | orig: \"%s\" (ret %zu)  (truncated, size=3)\n",
		ft_dst, ft_ret, orig_dst, orig_ret);
	ft_ret = ft_strlcpy(ft_dst, "hello", 0);
	orig_ret = strlcpy(orig_dst, "hello", 0);
	printf("ft: ret %zu | orig: ret %zu  (size=0, no copy)\n", ft_ret, orig_ret);
}

void	test_strlcat(void)
{
	char	ft_dst[20] = "hello";
	char	orig_dst[20] = "hello";
	size_t	ft_ret;
	size_t	orig_ret;

	printf("\n--- ft_strlcat ---\n");
	ft_ret = ft_strlcat(ft_dst, " world", 20);
	orig_ret = strlcat(orig_dst, " world", 20);
	printf("ft: \"%s\" (ret %zu) | orig: \"%s\" (ret %zu)  (normal concat)\n",
		ft_dst, ft_ret, orig_dst, orig_ret);
	ft_ret = ft_strlcat(ft_dst, "!!!", 12);
	orig_ret = strlcat(orig_dst, "!!!", 12);
	printf("ft: \"%s\" (ret %zu) | orig: \"%s\" (ret %zu)  (truncated, size=12)\n",
		ft_dst, ft_ret, orig_dst, orig_ret);
}

void	test_strncmp(void)
{
	printf("\n--- ft_strncmp ---\n");
	printf("ft: %d | orig: %d  (\"hello\" vs \"hello\", n=5)\n",
		ft_strncmp("hello", "hello", 5), strncmp("hello", "hello", 5));
	printf("ft: %d | orig: %d  (\"abc\" vs \"abd\", n=3, expect <0)\n",
		ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
	printf("ft: %d | orig: %d  (\"abd\" vs \"abc\", n=3, expect >0)\n",
		ft_strncmp("abd", "abc", 3), strncmp("abd", "abc", 3));
	printf("ft: %d | orig: %d  (n=0, always equal)\n",
		ft_strncmp("abc", "xyz", 0), strncmp("abc", "xyz", 0));
}

void	test_strnstr(void)
{
	printf("\n--- ft_strnstr ---\n");
	printf("ft: %s | orig: %s  (find \"world\" in \"hello world\", n=11)\n",
		ft_strnstr("hello world", "world", 11),
	strnstr("hello world", "world", 11));
	printf("ft: %p | orig: %p  (find \"world\" n=5, out of range, expect NULL)\n",
		(void *) ft_strnstr("hello world", "world", 5),
	(void *) strnstr("hello world", "world", 5));
	printf("ft: %s | orig: %s  (empty needle, returns haystack)\n",
		ft_strnstr("hello", "", 5),
	strnstr("hello", "", 5));
}

void	test_atoi(void)
{
	printf("\n--- ft_atoi ---\n");
	printf("ft: %d | orig: %d  (input: \"42\")\n", ft_atoi("42"), atoi("42"));
	printf("ft: %d | orig: %d  (input: \"-42\")\n", ft_atoi("-42"), atoi("-42"));
	printf("ft: %d | orig: %d  (input: \"  +7\")\n", ft_atoi("  +7"), atoi("  +7"));
	printf("ft: %d | orig: %d  (input: \"0\")\n", ft_atoi("0"), atoi("0"));
	printf("ft: %d | orig: %d  (input: \"42abc\")\n", ft_atoi("42abc"), atoi("42abc"));
}

/* ************************************************************************** */
/*  PART 1 - MEMORY FUNCTIONS                                                 */
/* ************************************************************************** */

void	test_memset(void)
{
	char	ft_buf[6];
	char	orig_buf[6];

	printf("\n--- ft_memset ---\n");
	ft_memset(ft_buf, 'A', 5);
	ft_buf[5] = '\0';
	memset(orig_buf, 'A', 5);
	orig_buf[5] = '\0';
	printf("ft: \"%s\" | orig: \"%s\"  (fill 5 bytes with 'A')\n", ft_buf, orig_buf);
	ft_memset(ft_buf, '0', 5);
	ft_buf[5] = '\0';
	memset(orig_buf, '0', 5);
	orig_buf[5] = '\0';
	printf("ft: \"%s\" | orig: \"%s\"  (fill 5 bytes with '0')\n", ft_buf, orig_buf);
}

void	test_bzero(void)
{
	char	ft_buf[6] = "hello";
	char	orig_buf[6] = "hello";

	printf("\n--- ft_bzero ---\n");
	printf("before ft_bzero:  \"%s\"\n", ft_buf);
	ft_bzero(ft_buf, 5);
	bzero(orig_buf, 5);
	printf("ft: first byte = %d | orig: first byte = %d  (expect 0)\n",
		ft_buf[0], orig_buf[0]);
}

void	test_memcpy(void)
{
	char	ft_dst[10] =
	{
		0
	};
	char	orig_dst[10] =
	{
		0
	};
	printf("\n--- ft_memcpy ---\n");
	ft_memcpy(ft_dst, "hello", 5);
	memcpy(orig_dst, "hello", 5);
	printf("ft: \"%s\" | orig: \"%s\"  (copy \"hello\")\n", ft_dst, orig_dst);
}

void	test_memmove(void)
{
	char	ft_buf[40] = "memmove can be very useful.";
	char	orig_buf[40] = "memmove can be very useful.";

	printf("\n--- ft_memmove ---\n");
	ft_memmove(ft_buf + 20, ft_buf + 15, 11);
	memmove(orig_buf + 20, orig_buf + 15, 11);
	printf("ft:   \"%s\"\n", ft_buf);
	printf("orig: \"%s\"  (overlapping copy)\n", orig_buf);
}

void	test_memchr(void)
{
	const char	*s = "hello";

	printf("\n--- ft_memchr ---\n");
	printf("ft: %s | orig: %s  (find 'l' in \"hello\", n=5)\n",
		(char *) ft_memchr(s, 'l', 5), (char *) memchr(s, 'l', 5));
	printf("ft: %p | orig: %p  (find 'z', not found, expect NULL)\n",
		ft_memchr(s, 'z', 5), memchr(s, 'z', 5));
	printf("ft: %p | orig: %p  (n=0, expect NULL)\n",
		ft_memchr(s, 'h', 0), memchr(s, 'h', 0));
}

void	test_memcmp(void)
{
	printf("\n--- ft_memcmp ---\n");
	printf("ft: %d | orig: %d  (\"abc\" vs \"abc\", n=3, expect 0)\n",
		ft_memcmp("abc", "abc", 3), memcmp("abc", "abc", 3));
	printf("ft: %d | orig: %d  (\"abc\" vs \"abd\", n=3, expect <0)\n",
		ft_memcmp("abc", "abd", 3), memcmp("abc", "abd", 3));
	printf("ft: %d | orig: %d  (\"abd\" vs \"abc\", n=3, expect >0)\n",
		ft_memcmp("abd", "abc", 3), memcmp("abd", "abc", 3));
	printf("ft: %d | orig: %d  (n=0, always 0)\n",
		ft_memcmp("abc", "xyz", 0), memcmp("abc", "xyz", 0));
}

/* ************************************************************************** */
/*  PART 1 - MALLOC FUNCTIONS                                                 */
/* ************************************************************************** */

void	test_calloc(void)
{
	int		*arr;
	void	*z;

	printf("\n--- ft_calloc ---\n");
	arr = ft_calloc(5, sizeof(int));
	printf("ft_calloc(5, sizeof(int)): pointer not NULL: %s\n",
		arr != NULL ? "yes" : "no");
	printf("  first byte zeroed: %d | last byte zeroed: %d  (expect 0 0)\n",
		arr[0], arr[4]);
	free(arr);
	z = ft_calloc(0, 0);
	printf("ft_calloc(0, 0): pointer not NULL: %s  (must be freeable)\n",
		z != NULL ? "yes" : "no");
	free(z);
}

void	test_strdup(void)
{
	char	*s;

	printf("\n--- ft_strdup ---\n");
	s = ft_strdup("hello");
	printf("ft: \"%s\" | orig: \"%s\"  (dup \"hello\")\n", s, "hello");
	free(s);
	s = ft_strdup("");
	printf("ft: \"%s\" | orig: \"%s\"  (dup empty string)\n", s, "");
	free(s);
}

/* ************************************************************************** */
/*  PART 2 - ADDITIONAL FUNCTIONS (no libc equivalent, just show results)     */
/* ************************************************************************** */

void	test_substr(void)
{
	char	*s;

	printf("\n--- ft_substr ---\n");
	s = ft_substr("hello world", 6, 5);
	printf("ft_substr(\"hello world\", 6, 5) = \"%s\"  (expect: \"world\")\n", s);
	free(s);
	s = ft_substr("hello", 10, 5);
	printf("ft_substr(\"hello\", 10, 5)      = \"%s\"  (expect: \"\")\n", s);
	free(s);
	s = ft_substr("hello", 1, 2);
	printf("ft_substr(\"hello\", 1, 2)       = \"%s\"  (expect: \"el\")\n", s);
	free(s);
}

void	test_strjoin(void)
{
	char	*s;

	printf("\n--- ft_strjoin ---\n");
	s = ft_strjoin("hello", " world");
	printf("ft_strjoin(\"hello\", \" world\") = \"%s\"  (expect: \"hello world\")\n", s);
	free(s);
	s = ft_strjoin("", "world");
	printf("ft_strjoin(\"\", \"world\")        = \"%s\"  (expect: \"world\")\n", s);
	free(s);
	s = ft_strjoin("hello", "");
	printf("ft_strjoin(\"hello\", \"\")        = \"%s\"  (expect: \"hello\")\n", s);
	free(s);
}

void	test_strtrim(void)
{
	char	*s;

	printf("\n--- ft_strtrim ---\n");
	s = ft_strtrim("  hello  ", " ");
	printf("ft_strtrim(\"  hello  \", \" \")  = \"%s\"  (expect: \"hello\")\n", s);
	free(s);
	s = ft_strtrim("xxhelloxx", "x");
	printf("ft_strtrim(\"xxhelloxx\", \"x\")  = \"%s\"  (expect: \"hello\")\n", s);
	free(s);
	s = ft_strtrim("hello", "xyz");
	printf("ft_strtrim(\"hello\", \"xyz\")    = \"%s\"  (expect: \"hello\")\n", s);
	free(s);
	s = ft_strtrim("aaaa", "a");
	printf("ft_strtrim(\"aaaa\", \"a\")       = \"%s\"  (expect: \"\")\n", s);
	free(s);
}

void	test_split(void)
{
	char	**res;
	int		i;

	printf("\n--- ft_split ---\n");
	res = ft_split("hello world foo", ' ');
	printf("ft_split(\"hello world foo\", ' '):\n");
	i = 0;
	while (res[i])
	{
		printf("  [%d] = \"%s\"\n", i, res[i]);
		free(res[i++]);
	}
	printf("  [%d] = NULL  (expect: hello / world / foo)\n", i);
	free(res);
	res = ft_split("", ' ');
	printf("ft_split(\"\", ' '): word[0] = %s  (expect NULL)\n",
		res[0] ? res[0] : "NULL");
	free(res);
	res = ft_split("   ", ' ');
	printf("ft_split(\"   \", ' '): word[0] = %s  (expect NULL)\n",
		res[0] ? res[0] : "NULL");
	free(res);
}

void	test_itoa(void)
{
	char	*s;

	printf("\n--- ft_itoa ---\n");
	s = ft_itoa(42);
	printf("ft_itoa(42)          = \"%s\"  (expect: \"42\")\n", s);
	free(s);
	s = ft_itoa(-42);
	printf("ft_itoa(-42)         = \"%s\"  (expect: \"-42\")\n", s);
	free(s);
	s = ft_itoa(0);
	printf("ft_itoa(0)           = \"%s\"  (expect: \"0\")\n", s);
	free(s);
	s = ft_itoa(2147483647);
	printf("ft_itoa(INT_MAX)     = \"%s\"  (expect: \"2147483647\")\n", s);
	free(s);
	s = ft_itoa(-2147483648);
	printf("ft_itoa(INT_MIN)     = \"%s\"  (expect: \"-2147483648\")\n", s);
	free(s);
}

static char	add_one(unsigned int i, char c)
{
	(void) i;
	return (c + 1);
}

void	test_strmapi(void)
{
	char	*s;

	printf("\n--- ft_strmapi ---\n");
	s = ft_strmapi("abc", add_one);
	printf("ft_strmapi(\"abc\", add_one) = \"%s\"  (expect: \"bcd\")\n", s);
	free(s);
}

static void	upper_first(unsigned int i, char *c)
{
	if (i == 0)
		*c = *c - 32;
}

void	test_striteri(void)
{
	char	s[] = "hello";

	printf("\n--- ft_striteri ---\n");
	printf("before: \"%s\"\n", s);
	ft_striteri(s, upper_first);
	printf("after ft_striteri (uppercase first char): \"%s\"  (expect: \"Hello\")\n", s);
}

void	test_put_fds(void)
{
	printf("\n--- ft_putchar_fd / ft_putstr_fd / ft_putendl_fd / ft_putnbr_fd ---\n");
	printf("ft_putchar_fd('A', 1):       ");
	ft_putchar_fd('A', 1);
	printf("\n");
	printf("ft_putstr_fd(\"hello\", 1):    ");
	ft_putstr_fd("hello", 1);
	printf("\n");
	printf("ft_putendl_fd(\"hello\", 1):   ");
	ft_putendl_fd("hello", 1);
	printf("ft_putnbr_fd(-2147483648, 1): ");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
}

/* ************************************************************************** */
/*  PART 3 - LINKED LIST FUNCTIONS                                            */
/* ************************************************************************** */

void	test_lstnew(void)
{
	t_list	*node;

	printf("\n--- ft_lstnew ---\n");
	node = ft_lstnew("hello");
	printf("node not NULL:        %s\n", node ? "yes" : "no");
	printf("node->content:        \"%s\"  (expect: \"hello\")\n", (char *) node->content);
	printf("node->next is NULL:   %s\n", node->next == NULL ? "yes" : "no");
	free(node);
}

void	test_lstadd_front(void)
{
	t_list	*lst;
	t_list	*n1;
	t_list	*n2;

	printf("\n--- ft_lstadd_front ---\n");
	n1 = ft_lstnew("first");
	n2 = ft_lstnew("second");
	lst = n1;
	ft_lstadd_front(&lst, n2);
	printf("new head content: \"%s\"  (expect: \"second\")\n", (char *) lst->content);
	printf("head->next:       \"%s\"  (expect: \"first\")\n", (char *) lst->next->content);
	free(n1);
	free(n2);
}

void	test_lstsize(void)
{
	t_list	*n1 = ft_lstnew("a");
	t_list	*n2 = ft_lstnew("b");
	t_list	*n3 = ft_lstnew("c");

	n1->next = n2;
	n2->next = n3;
	printf("\n--- ft_lstsize ---\n");
	printf("size of 3-node list: %d  (expect: 3)\n", ft_lstsize(n1));
	printf("size of NULL:        %d  (expect: 0)\n", ft_lstsize(NULL));
	free(n1);
	free(n2);
	free(n3);
}

void	test_lstlast(void)
{
	t_list	*n1 = ft_lstnew("a");
	t_list	*n2 = ft_lstnew("b");

	n1->next = n2;
	printf("\n--- ft_lstlast ---\n");
	printf("last content: \"%s\"  (expect: \"b\")\n", (char *) ft_lstlast(n1)->content);
	printf("last of NULL: %p  (expect: NULL)\n", (void *) ft_lstlast(NULL));
	free(n1);
	free(n2);
}

void	test_lstadd_back(void)
{
	t_list	*lst = ft_lstnew("first");
	t_list	*n2 = ft_lstnew("last");

	printf("\n--- ft_lstadd_back ---\n");
	ft_lstadd_back(&lst, n2);
	printf("last content: \"%s\"  (expect: \"last\")\n",
		(char *) ft_lstlast(lst)->content);
	printf("list size:    %d  (expect: 2)\n", ft_lstsize(lst));
	free(lst);
	free(n2);
}

static void	del_content(void *content)
{
	free(content);
}

void	test_lstdelone(void)
{
	t_list	*node = ft_lstnew(ft_strdup("hello"));

	printf("\n--- ft_lstdelone ---\n");
	ft_lstdelone(node, del_content);
	printf("ft_lstdelone ran without crash: yes\n");
}

void	test_lstclear(void)
{
	t_list	*lst = ft_lstnew(ft_strdup("a"));

	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	printf("\n--- ft_lstclear ---\n");
	ft_lstclear(&lst, del_content);
	printf("lst after clear is NULL: %s  (expect: yes)\n", lst == NULL ? "yes" : "no");
}

static int	g_count = 0;

static void	count_node(void *content)
{
	(void) content;
	g_count++;
}

void	test_lstiter(void)
{
	t_list	*lst = ft_lstnew("a");

	ft_lstadd_back(&lst, ft_lstnew("b"));
	ft_lstadd_back(&lst, ft_lstnew("c"));
	printf("\n--- ft_lstiter ---\n");
	ft_lstiter(lst, count_node);
	printf("function called %d times on 3-node list  (expect: 3)\n", g_count);
	free(lst->next->next);
	free(lst->next);
	free(lst);
}

static void	*dup_content(void *content)
{
	return (ft_strdup((char *) content));
}

void	test_lstmap(void)
{
	t_list	*lst;
	t_list	*mapped;

	printf("\n--- ft_lstmap ---\n");
	lst = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("world")));
	mapped = ft_lstmap(lst, dup_content, del_content);
	printf("mapped not NULL:             %s\n", mapped ? "yes" : "no");
	printf("mapped->content:             \"%s\"  (expect: \"hello\")\n",
		(char *) mapped->content);
	printf("mapped->next->content:       \"%s\"  (expect: \"world\")\n",
		(char *) mapped->next->content);
	printf("original lst->content:       \"%s\"  (expect: \"hello\", unchanged)\n",
		(char *) lst->content);
	ft_lstclear(&lst, del_content);
	ft_lstclear(&mapped, del_content);
}

/* ************************************************************************** */
/*  MAIN                                                                       */
/* ************************************************************************** */

int	main(void)
{
	printf("=== PART 1: CHARACTER CHECKS ===\n");
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	printf("\n=== PART 1: STRING FUNCTIONS ===\n");
	test_strlen();
	test_strchr();
	test_strrchr();
	test_strlcpy();
	test_strlcat();
	test_strncmp();
	test_strnstr();
	test_atoi();
	printf("\n=== PART 1: MEMORY FUNCTIONS ===\n");
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	printf("\n=== PART 1: MALLOC FUNCTIONS ===\n");
	test_calloc();
	test_strdup();
	printf("\n=== PART 2: ADDITIONAL FUNCTIONS ===\n");
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_put_fds();
	printf("\n=== PART 3: LINKED LISTS ===\n");
	test_lstnew();
	test_lstadd_front();
	test_lstsize();
	test_lstlast();
	test_lstadd_back();
	test_lstdelone();
	test_lstclear();
	test_lstiter();
	test_lstmap();
	printf("\n=== DONE ===\n");
	return (0);
}
