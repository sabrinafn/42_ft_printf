NAME := libftprintf.a

CC := cc

FLAGS := -Wall -Wextra -Werror

HEADER := ft_printf.h

CFILES := ft_printf.c \
		ft_putchars.c \
		ft_putdigits.c \
		ft_puthexa.c

OFILES := $(CFILES:.c=.o)

LIB := ar -rcs

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ 

$(NAME): $(OFILES)
	$(LIB) $(NAME) $(OFILES)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: 
	rm -f $(OFILES) $(NAME)

re: fclean all

.PHONY: all clean fclean re
