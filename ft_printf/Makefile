NAME := libftprintf.a
CC := cc
FLAGS := -Wall -Wextra -Werror

SRCS := ft_printf.c \
	ft_putchars.c \
	ft_putdigits.c \
	ft_puthex.c

OBJS :=	$(SRCS:.c=.o)

LIB := ar -rc

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
