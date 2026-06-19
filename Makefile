# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 16:25:49 by maalwis           #+#    #+#              #
#    Updated: 2025/04/16 14:58:21 by maalwis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = Object_files

SRC = \
	find_path.c \
	infinite_pipes.c \
	pipex.c \
	heredoc.c \

LIBFT_PATH = Superlibft
LIBFT = $(LIBFT_PATH)/libft.a

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
