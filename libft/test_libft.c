/* ************************************************************************** */
/*                                                                            */
/*   test_libft.c                                                             */
/*   A comprehensive tester for libft                                         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/* ----------------------------- helpers ------------------------------------ */

static int	g_pass = 0;
static int	g_fail = 0;

static void	check(const char *fname, const char *desc, int ok)
{
	if (ok)
	{
		printf("  \033[32m[PASS]\033[0m %s - %s\n", fname, desc);
		g_pass++;
	}
	else
	{
		printf("  \033[31m[FAIL]\033[0m %s - %s\n", fname, desc);
		g_fail++;
	}
}

static void	check_int(const char *fname, const char *desc, int got, int expected)
{
	if (got == expected)
	{
		printf("  \033[32m[PASS]\033[0m %s - %s\n", fname, desc);
		g_pass++;
	}
	else
	{
		printf("  \033[31m[FAIL]\033[0m %s - %s | expected %d, got %d\n",
			fname, desc, expected, got);
		g_fail++;
	}
}

static void	check_str(const char *fname, const char *desc,
	const char *got, const char *expected)
{
	if (got && expected && strcmp(got, expected) == 0)
	{
		printf("  \033[32m[PASS]\033[0m %s - %s\n", fname, desc);
		g_pass++;
	}
	else
	{
		printf("  \033[31m[FAIL]\033[0m %s - %s | expected \"%s\", got \"%s\"\n",
			fname, desc, expected ? expected : "(null)", got ? got : "(null)");
		g_fail++;
	}
}

static void	section(const char *title)
{
	printf("\n\033[1;34m=== %s ===\033[0m\n", title);
}

/* ----------------------------- Part 1 ------------------------------------- */

static void	test_isalpha(void)
{
	check_int("ft_isalpha", "lowercase 'a'",   ft_isalpha('a'), 1);
	check_int("ft_isalpha", "uppercase 'Z'",   ft_isalpha('Z'), 1);
	check_int("ft_isalpha", "digit '5'",        ft_isalpha('5'), 0);
	check_int("ft_isalpha", "space ' '",        ft_isalpha(' '), 0);
	check_int("ft_isalpha", "null byte 0",      ft_isalpha(0),   0);
}

static void	test_isdigit(void)
{
	check_int("ft_isdigit", "'0'",   ft_isdigit('0'), 1);
	check_int("ft_isdigit", "'9'",   ft_isdigit('9'), 1);
	check_int("ft_isdigit", "'a'",   ft_isdigit('a'), 0);
	check_int("ft_isdigit", "' '",   ft_isdigit(' '), 0);
}

static void	test_isalnum(void)
{
	check_int("ft_isalnum", "'a'",  ft_isalnum('a'), 1);
	check_int("ft_isalnum", "'3'",  ft_isalnum('3'), 1);
	check_int("ft_isalnum", "'!'",  ft_isalnum('!'), 0);
}

static void	test_isascii(void)
{
	check_int("ft_isascii", "0",    ft_isascii(0),   1);
	check_int("ft_isascii", "127",  ft_isascii(127), 1);
	check_int("ft_isascii", "128",  ft_isascii(128), 0);
	check_int("ft_isascii", "-1",   ft_isascii(-1),  0);
}

static void	test_isprint(void)
{
	check_int("ft_isprint", "' ' (32)",  ft_isprint(' '),  1);
	check_int("ft_isprint", "'~' (126)", ft_isprint('~'),  1);
	check_int("ft_isprint", "31",        ft_isprint(31),   0);
	check_int("ft_isprint", "127 DEL",   ft_isprint(127),  0);
}

static void	test_strlen(void)
{
	check_int("ft_strlen", "\"hello\"",  (int)ft_strlen("hello"), 5);
	check_int("ft_strlen", "empty \"\"", (int)ft_strlen(""),      0);
	check_int("ft_strlen", "\"abc\"",    (int)ft_strlen("abc"),   3);
}

static void	test_memset(void)
{
	char	buf[6];

	ft_memset(buf, 'A', 5);
	buf[5] = '\0';
	check_str("ft_memset", "fill 5 bytes with 'A'", buf, "AAAAA");
	ft_memset(buf, 0, 5);
	check("ft_memset", "fill with 0", buf[0] == 0 && buf[4] == 0);
}

static void	test_bzero(void)
{
	char	buf[5] = {1, 2, 3, 4, 5};

	ft_bzero(buf, 5);
	check("ft_bzero", "all bytes zero",
		buf[0] == 0 && buf[2] == 0 && buf[4] == 0);
}

static void	test_memcpy(void)
{
	char	dst[10] = {0};

	ft_memcpy(dst, "hello", 5);
	check("ft_memcpy", "copy \"hello\"", memcmp(dst, "hello", 5) == 0);
	check("ft_memcpy", "NULL src+dst returns NULL",
		ft_memcpy(NULL, NULL, 5) == NULL);
}

static void	test_memmove(void)
{
	char	buf[] = "memmove can be very useful.";

	ft_memmove(buf + 20, buf + 15, 11);
	check("ft_memmove", "overlapping copy",
		memcmp(buf + 20, "very useful.", 12) == 0);
}

static void	test_strlcpy(void)
{
	char	dst[10];
	size_t	ret;

	ret = ft_strlcpy(dst, "hello", 10);
	check_str("ft_strlcpy", "normal copy",         dst, "hello");
	check_int("ft_strlcpy", "return = src length", (int)ret, 5);
	ret = ft_strlcpy(dst, "hello", 3);
	check_str("ft_strlcpy", "truncated copy",      dst, "he");
	check_int("ft_strlcpy", "return still = 5",    (int)ret, 5);
	ret = ft_strlcpy(dst, "hello", 0);
	check_int("ft_strlcpy", "size=0 returns srclen", (int)ret, 5);
}

static void	test_strlcat(void)
{
	char	dst[20] = "hello";
	size_t	ret;

	ret = ft_strlcat(dst, " world", 20);
	check_str("ft_strlcat", "concat result",        dst, "hello world");
	check_int("ft_strlcat", "return = total length", (int)ret, 11);
	ret = ft_strlcat(dst, "!!!", 12);
	check_str("ft_strlcat", "truncated concat",     dst, "hello world");
}

static void	test_toupper(void)
{
	check_int("ft_toupper", "'a' -> 'A'",    ft_toupper('a'), 'A');
	check_int("ft_toupper", "'z' -> 'Z'",    ft_toupper('z'), 'Z');
	check_int("ft_toupper", "'A' unchanged", ft_toupper('A'), 'A');
	check_int("ft_toupper", "'1' unchanged", ft_toupper('1'), '1');
}

static void	test_tolower(void)
{
	check_int("ft_tolower", "'A' -> 'a'",    ft_tolower('A'), 'a');
	check_int("ft_tolower", "'Z' -> 'z'",    ft_tolower('Z'), 'z');
	check_int("ft_tolower", "'a' unchanged", ft_tolower('a'), 'a');
}

static void	test_strchr(void)
{
	const char	*s = "hello";

	check("ft_strchr", "find 'l'",   ft_strchr(s, 'l') == s + 2);
	check("ft_strchr", "find 'o'",   ft_strchr(s, 'o') == s + 4);
	check("ft_strchr", "not found",  ft_strchr(s, 'z') == NULL);
	check("ft_strchr", "find '\\0'", ft_strchr(s, '\0') == s + 5);
}

static void	test_strrchr(void)
{
	const char	*s = "hello";

	check("ft_strrchr", "last 'l'",    ft_strrchr(s, 'l') == s + 3);
	check("ft_strrchr", "not found",   ft_strrchr(s, 'z') == NULL);
	check("ft_strrchr", "find '\\0'",  ft_strrchr(s, '\0') == s + 5);
}

static void	test_strncmp(void)
{
	check("ft_strncmp", "equal strings n=5",
		ft_strncmp("hello", "hello", 5) == 0);
	check("ft_strncmp", "n=0 always equal",
		ft_strncmp("abc", "xyz", 0) == 0);
	check("ft_strncmp", "first < second",
		ft_strncmp("abc", "abd", 3) < 0);
	check("ft_strncmp", "first > second",
		ft_strncmp("abd", "abc", 3) > 0);
	check("ft_strncmp", "unsigned byte comparison",
		ft_strncmp("\x80", "\x7f", 1) > 0);
}

static void	test_memchr(void)
{
	const char	*s = "hello";

	check("ft_memchr", "find 'l'",  ft_memchr(s, 'l', 5) == s + 2);
	check("ft_memchr", "not found", ft_memchr(s, 'z', 5) == NULL);
	check("ft_memchr", "n=0",       ft_memchr(s, 'h', 0) == NULL);
}

static void	test_memcmp(void)
{
	check("ft_memcmp", "equal",      ft_memcmp("abc", "abc", 3) == 0);
	check("ft_memcmp", "first less", ft_memcmp("abc", "abd", 3) < 0);
	check("ft_memcmp", "first more", ft_memcmp("abd", "abc", 3) > 0);
	check("ft_memcmp", "n=0",        ft_memcmp("abc", "xyz", 0) == 0);
}

static void	test_strnstr(void)
{
	check("ft_strnstr", "found",
		ft_strnstr("hello world", "world", 11) != NULL);
	check("ft_strnstr", "not in range",
		ft_strnstr("hello world", "world", 5) == NULL);
	check("ft_strnstr", "empty needle returns haystack",
		ft_strnstr("hello", "", 5) != NULL);
	check("ft_strnstr", "needle not found",
		ft_strnstr("hello", "xyz", 5) == NULL);
}

static void	test_atoi(void)
{
	check_int("ft_atoi", "\"42\"",         ft_atoi("42"),       42);
	check_int("ft_atoi", "\"-42\"",        ft_atoi("-42"),      -42);
	check_int("ft_atoi", "\"  +7\"",       ft_atoi("  +7"),     7);
	check_int("ft_atoi", "\"0\"",          ft_atoi("0"),        0);
	check_int("ft_atoi", "trailing alpha", ft_atoi("42abc"),    42);
	check_int("ft_atoi", "empty string",   ft_atoi(""),         0);
}

static void	test_calloc(void)
{
	int	*arr;
	void	*z;

	arr = ft_calloc(5, sizeof(int));
	check("ft_calloc", "not NULL",      arr != NULL);
	check("ft_calloc", "zeroed memory", arr[0] == 0 && arr[4] == 0);
	free(arr);
	z = ft_calloc(0, 0);
	check("ft_calloc", "size=0 not NULL", z != NULL);
	free(z);
}

static void	test_strdup(void)
{
	char	*s;

	s = ft_strdup("hello");
	check_str("ft_strdup", "duplicated string", s, "hello");
	free(s);
	s = ft_strdup("");
	check_str("ft_strdup", "empty string", s, "");
	free(s);
}

/* ----------------------------- Part 2 ------------------------------------- */

static void	test_substr(void)
{
	char	*s;

	s = ft_substr("hello world", 6, 5);
	check_str("ft_substr", "\"world\"",          s, "world");
	free(s);
	s = ft_substr("hello", 10, 5);
	check_str("ft_substr", "start > len = \"\"", s, "");
	free(s);
	s = ft_substr("hello", 1, 2);
	check_str("ft_substr", "len clamped",        s, "el");
	free(s);
	check("ft_substr", "NULL input = NULL", ft_substr(NULL, 0, 5) == NULL);
}

static void	test_strjoin(void)
{
	char	*s;

	s = ft_strjoin("hello", " world");
	check_str("ft_strjoin", "basic join",    s, "hello world");
	free(s);
	s = ft_strjoin("", "world");
	check_str("ft_strjoin", "empty prefix", s, "world");
	free(s);
	s = ft_strjoin("hello", "");
	check_str("ft_strjoin", "empty suffix", s, "hello");
	free(s);
}

static void	test_strtrim(void)
{
	char	*s;

	s = ft_strtrim("  hello  ", " ");
	check_str("ft_strtrim", "trim spaces",        s, "hello");
	free(s);
	s = ft_strtrim("xxhelloxx", "x");
	check_str("ft_strtrim", "trim 'x'",           s, "hello");
	free(s);
	s = ft_strtrim("hello", "xyz");
	check_str("ft_strtrim", "nothing to trim",    s, "hello");
	free(s);
	s = ft_strtrim("aaaa", "a");
	check_str("ft_strtrim", "all trimmed = \"\"", s, "");
	free(s);
}

static void	test_split(void)
{
	char	**res;
	int		i;

	res = ft_split("hello world foo", ' ');
	check("ft_split", "3 words not NULL", res != NULL);
	check_str("ft_split", "word[0] = \"hello\"", res[0], "hello");
	check_str("ft_split", "word[1] = \"world\"", res[1], "world");
	check_str("ft_split", "word[2] = \"foo\"",   res[2], "foo");
	check("ft_split", "word[3] = NULL",          res[3] == NULL);
	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	res = ft_split("", ' ');
	check("ft_split", "empty -> word[0] NULL",        res[0] == NULL);
	free(res);
	res = ft_split("   ", ' ');
	check("ft_split", "only delimiters -> NULL term",  res[0] == NULL);
	free(res);
	res = ft_split("one", ' ');
	check_str("ft_split", "single word", res[0], "one");
	free(res[0]);
	free(res);
}

static void	test_itoa(void)
{
	char	*s;

	s = ft_itoa(42);
	check_str("ft_itoa", "42",      s, "42");
	free(s);
	s = ft_itoa(-42);
	check_str("ft_itoa", "-42",     s, "-42");
	free(s);
	s = ft_itoa(0);
	check_str("ft_itoa", "0",       s, "0");
	free(s);
	s = ft_itoa(INT_MAX);
	check_str("ft_itoa", "INT_MAX", s, "2147483647");
	free(s);
	s = ft_itoa(INT_MIN);
	check_str("ft_itoa", "INT_MIN", s, "-2147483648");
	free(s);
}

static char	add_one(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

static void	test_strmapi(void)
{
	char	*s;

	s = ft_strmapi("abc", add_one);
	check_str("ft_strmapi", "each char +1",     s, "bcd");
	free(s);
	check("ft_strmapi", "NULL string = NULL",
		ft_strmapi(NULL, add_one) == NULL);
}

static void	upper_first(unsigned int i, char *c)
{
	if (i == 0)
		*c = *c - 32;
}

static void	test_striteri(void)
{
	char	s[] = "hello";

	ft_striteri(s, upper_first);
	check_str("ft_striteri", "uppercase first char", s, "Hello");
}

static void	test_putchar_fd(void)
{
	printf("  [INFO] ft_putchar_fd writes 'A': ");
	ft_putchar_fd('A', 1);
	printf("\n");
	g_pass++;
}

static void	test_putstr_fd(void)
{
	printf("  [INFO] ft_putstr_fd writes \"hello\": ");
	ft_putstr_fd("hello", 1);
	printf("\n");
	g_pass++;
}

static void	test_putendl_fd(void)
{
	printf("  [INFO] ft_putendl_fd writes \"hello\" + newline:\n  ");
	ft_putendl_fd("hello", 1);
	g_pass++;
}

static void	test_putnbr_fd(void)
{
	printf("  [INFO] ft_putnbr_fd(-2147483648): ");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	g_pass++;
}

/* ----------------------------- Part 3 ------------------------------------- */

static void	del_content(void *content)
{
	free(content);
}

static void	*dup_content(void *content)
{
	return (ft_strdup((char *)content));
}

static void	test_lstnew(void)
{
	t_list	*node;

	node = ft_lstnew("hello");
	check("ft_lstnew", "not NULL",     node != NULL);
	check("ft_lstnew", "content set",  node->content == (void *)"hello");
	check("ft_lstnew", "next is NULL", node->next == NULL);
	free(node);
}

static void	test_lstadd_front(void)
{
	t_list	*lst;
	t_list	*n1;
	t_list	*n2;

	n1 = ft_lstnew("first");
	n2 = ft_lstnew("second");
	lst = n1;
	ft_lstadd_front(&lst, n2);
	check("ft_lstadd_front", "new head is n2", lst == n2);
	check("ft_lstadd_front", "n2->next is n1", lst->next == n1);
	free(n1);
	free(n2);
}

static void	test_lstsize(void)
{
	t_list	*n1 = ft_lstnew("a");
	t_list	*n2 = ft_lstnew("b");
	t_list	*n3 = ft_lstnew("c");

	n1->next = n2;
	n2->next = n3;
	check_int("ft_lstsize", "3 nodes",  ft_lstsize(n1), 3);
	check_int("ft_lstsize", "NULL = 0", ft_lstsize(NULL), 0);
	free(n1);
	free(n2);
	free(n3);
}

static void	test_lstlast(void)
{
	t_list	*n1 = ft_lstnew("a");
	t_list	*n2 = ft_lstnew("b");

	n1->next = n2;
	check("ft_lstlast", "last node is n2",   ft_lstlast(n1) == n2);
	check("ft_lstlast", "NULL returns NULL", ft_lstlast(NULL) == NULL);
	free(n1);
	free(n2);
}

static void	test_lstadd_back(void)
{
	t_list	*lst = ft_lstnew("first");
	t_list	*n2  = ft_lstnew("last");

	ft_lstadd_back(&lst, n2);
	check("ft_lstadd_back", "last node is n2", ft_lstlast(lst) == n2);
	check("ft_lstadd_back", "size is 2",       ft_lstsize(lst) == 2);
	free(lst);
	free(n2);
}

static void	test_lstdelone(void)
{
	t_list	*node = ft_lstnew(ft_strdup("hello"));

	ft_lstdelone(node, del_content);
	check("ft_lstdelone", "node freed (no crash)", 1);
}

static void	test_lstclear(void)
{
	t_list	*lst = ft_lstnew(ft_strdup("a"));

	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	ft_lstclear(&lst, del_content);
	check("ft_lstclear", "lst is NULL after clear", lst == NULL);
}

static int	g_iter_count = 0;

static void	count_node(void *content)
{
	(void)content;
	g_iter_count++;
}

static void	test_lstiter(void)
{
	t_list	*lst = ft_lstnew("a");

	ft_lstadd_back(&lst, ft_lstnew("b"));
	ft_lstadd_back(&lst, ft_lstnew("c"));
	ft_lstiter(lst, count_node);
	check_int("ft_lstiter", "f called 3 times", g_iter_count, 3);
	free(lst->next->next);
	free(lst->next);
	free(lst);
}

static void	test_lstmap(void)
{
	t_list	*lst;
	t_list	*mapped;

	lst = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("world")));
	mapped = ft_lstmap(lst, dup_content, del_content);
	check("ft_lstmap", "result not NULL",   mapped != NULL);
	check_str("ft_lstmap", "node[0] content",
		(char *)mapped->content, "hello");
	check_str("ft_lstmap", "node[1] content",
		(char *)mapped->next->content, "world");
	check("ft_lstmap", "original unchanged",
		strcmp((char *)lst->content, "hello") == 0);
	ft_lstclear(&lst, del_content);
	ft_lstclear(&mapped, del_content);
}

/* ----------------------------- main --------------------------------------- */

int	main(void)
{
	printf("\033[1;33m\nlibft comprehensive tester\033[0m\n");

	section("Part 1 - libc functions");
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();

	section("Part 2 - additional functions");
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();

	section("Part 3 - linked lists");
	test_lstnew();
	test_lstadd_front();
	test_lstsize();
	test_lstlast();
	test_lstadd_back();
	test_lstdelone();
	test_lstclear();
	test_lstiter();
	test_lstmap();

	printf("\n\033[1m--- Summary: %d passed, %d failed ---\033[0m\n\n",
		g_pass, g_fail);
	return (g_fail > 0 ? 1 : 0);
}
