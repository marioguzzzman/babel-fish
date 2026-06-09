SHELL = /bin/sh
CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
NAME = libft.a

SOURCES = ft_isalpha.c \ 

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c ft_printf.h
	cc $(SOURCES) -c $<

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	@echo .a archive file created.

clean:
	@rm -f $(OBJECTS)
	@echo All .o object files removed

fclean: clean
	@rm -f $(NAME)
	@echo All .o object files and .a archive files removed

re: fclean all
	@echo All .o files and .a files removed and recreated

.PHONY: all clean fclean re
