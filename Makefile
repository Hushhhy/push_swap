# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 12:55:34 by acarpent          #+#    #+#              #
#    Updated: 2024/04/29 17:24:30 by acarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Définitions de base
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -pg
CPPFLAGS = -I./src/include
BUILD = ./build
SRC = $(shell find ./src -name '*.c') # A REMPLACER
OBJ = $(SRC:src/%.c=$(BUILD)/%.o)

# Crée le dossier BUILD si nécessaire
$(shell mkdir -p $(BUILD))

# Règle principale
all: $(NAME)

# Règle pour compiler printf
# printf:
# 	$(MAKE) -C $(PRINTF)

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