# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 10:08:40 by oezzaou           #+#    #+#              #
#    Updated: 2023/09/18 12:48:37 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#           Variables|                                                         #
#******************************************************************************#
NAME		:= cub3d
CC			:= cc
CFLAGS		:= -lmlx -framework OpenGL -framework AppKit
SRC_DIR		:= src
OBJ_DIR		:= obj
INCLUDES	:= includes
SRC			:= $(wildcard *.c) $(notdir $(wildcard $(SRC_DIR)/*.c)) $(notdir $(wildcard $(SRC_DIR)/*/*.c))
OBJ			:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC))))
RM			:= rm -rf

#******************************************************************************#
#           Rules|                                                             #
#******************************************************************************#
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@ -I $(INCLUDES)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ -I $(INCLUDES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
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
