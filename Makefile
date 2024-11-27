# Nom du programme
NAME = ft_printf

# Fichiers source
SRCS = ft_printf.c 

# Objets générés
OBJS = $(SRCS:.c=.o)

# Dossier de la libft
LIBFT_DIR = ../libft  # Chemin vers le dossier de la libft
LIBFT = $(LIBFT_DIR)/libft.a

# Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../Rank_00/libft

# Règles
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
