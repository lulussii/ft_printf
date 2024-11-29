# Nom du programme
NAME = libftprintf.a

# Fichiers source
SRCS =	ft_printf.c \
		ft_functions.c

# Objets générés
OBJS = $(SRCS:%.c=%.o)

# Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror 

# Règles
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 


# NAME                 =     libftprintf.a
# HEAD                =    ft_printf.h
# INC_DIR                =    .
# OBJ_DIR                =    obj/
# CC                     =     gcc
# CFLAGS                 =     -Wall -Wextra -Werror
# AR                    =    ar rcs
# RM                    =    rm -f
# SRC                 =    ft_printf.c
# OBJ                 =     $(SRC:%.c=$(OBJ_DIR)%.o)

# COLOUR_GREEN        =    \033[0;32m
# COLOUR_RED            =    \033[0;31m
# END_COLOUR            =    \033[0m

# $(OBJ_DIR)%.o:	%.c $(HEAD) | $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# all:                     $(NAME)

# $(NAME):	$(OBJ) Makefile
# 	$(AR) $@ $^

# $(OBJ_DIR):
# 	@mkdir -p $(OBJ_DIR)
# 	@echo "Creating repository 'obj'"
# clean:
# 	@rm -rf $(OBJ_DIR)
# 	@echo "$(COLOUR_RED)Deleting repository 'obj'$(END_COLOUR)"

# fclean:	clean
# 	@$(RM) $(NAME)
# 	@echo "$(COLOUR_RED)Deleting libftprintf.a$(END_COLOUR)"

# re:	fclean all


# .PHONY:	all bonus clean fclean re