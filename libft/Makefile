SHELL = /bin/sh
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -I.
NAME = libft.a

SOURCES = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c

BONUS_SOURCES = 
# Add your *_bonus.c files here when you do the bonus part, e.g.:
# BONUS_SOURCES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ...

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	@echo .a archive file created.

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
	@echo .a archive file created with bonus.

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) -c $(SOURCES) $(BONUS_SOURCES)
	$(CC) -nostartfiles -shared -o libft.so $(OBJECTS) $(BONUS_OBJECTS)

test: all
	$(CC) $(CFLAGS) test/main.c -L. -lbsd -lft -I. -o demo
	./demo
	@echo .o object files and .a archive files created. Demo is running.

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)
	@echo All .o object files removed

fclean: clean
	@rm -f $(NAME) libft.so
	@echo All .o object files and .a archive files removed

re: fclean all
	@echo All .o files and .a files removed and recreated

.PHONY: all bonus clean fclean re test so