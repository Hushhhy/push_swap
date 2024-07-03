# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 12:55:34 by acarpent          #+#    #+#              #
#    Updated: 2024/05/03 13:01:16 by acarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Définitions de base
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -pg
CPPFLAGS = -I./src/include
BUILD = ./build
SRC = 	./src/command/commands_push.c \
		./src/command/commands_double.c \
		./src/command/commands_reverse.c \
		./src/command/commands_rotate.c \
		./src/command/commands_swap.c \
		./src/lib/algo.c \
		./src/lib/cost.c \
		./src/lib/cost_utils.c \
		./src/lib/ft_lst.c \
		./src/lib/ft_split.c \
		./src/lib/libft_utils0.c \
		./src/lib/libft_utils1.c \
		./src/lib/libft_utils.c \
		./src/lib/median.c \
		./src/lib/parsing.c \
		./src/lib/push_swap_utils.c \
		./src/main.c \
		./src/security/ft_security.c \
		./src/security/ft_security_utils.c \

OBJ = $(SRC:src/%.c=$(BUILD)/%.o)

# Crée le dossier BUILD si nécessaire
$(shell mkdir -p $(BUILD))

# Règle principale
all: $(NAME)

# Règle pour créer l'exécutable push_swap
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME)

# Règle pour compiler les fichiers .c en .o et les déplacer dans BUILD
$(BUILD)/%.o: src/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Règles pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(BUILD)/*.o

fclean: clean
	rm -f $(NAME)

# Règle pour recompiler
re: fclean all

# Pour éviter les conflits avec des fichiers du même nom
.PHONY: all clean fclean re
