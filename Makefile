# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flox <flox@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 11:21:42 by flox              #+#    #+#              #
#    Updated: 2026/01/22 11:21:45 by flox             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux
MAP_DIR		= maps
TEXTURE_DIR	= textures

# Source files
SRCS		= $(SRC_DIR)/parsing.c \
				$(SRC_DIR)/handle_error.c \
			 	$(SRC_DIR)/so_long.c \
				$(SRC_DIR)/map_is_valid.c \
				$(SRC_DIR)/flood_fill.c \
				$(SRC_DIR)/graphic.c \
				$(SRC_DIR)/hook.c \
				$(SRC_DIR)/manage_game_err.c \
				$(SRC_DIR)/manage_game.c
# Object files
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(MLX_DIR) -O3 -I$(LIBFT_DIR)
LDFLAGS		= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "compiled successfully"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "Building libft"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@echo "Building MLX"
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "Object files removed"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "Full cleaned"

re: fclean all

.PHONY: all clean fclean re