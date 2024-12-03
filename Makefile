
NAME = libftprintf.a
SRCS =	ft_printf.c \
		ft_printf_utils.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) ft_printf.h Makefile
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
