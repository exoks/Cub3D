# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 10:08:40 by oezzaou           #+#    #+#              #
#    Updated: 2023/09/19 20:23:29 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#           Variables|                                                         #
#******************************************************************************#
NAME		:= cub3d
CC			:= cc
MLX_FLAGS	:= -lmlx -framework OpenGL -framework AppKit
#MLX_FLAGS	:= -lmlx -lXext -lX11 -lm -lz
SRC_DIR		:= src
OBJ_DIR		:= obj
INCLUDES	:= includes
SRC			:= $(wildcard *.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJ			:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(SRC)))))
RM			:= rm -rf

#******************************************************************************#
#           Rules|                                                             #
#******************************************************************************#
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $^ -o $@ -I $(INCLUDES) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ -I $(INCLUDES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ -I $(INCLUDES)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

re: fclean all

run:
	./$(NAME)

.PHONY: all clean fclean re run
#******************************************************************************#
