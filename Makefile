# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 10:08:40 by oezzaou           #+#    #+#              #
#    Updated: 2023/09/13 10:52:01 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	:= cub3d
CC		:= gcc
CFLAGS	:= -lmlx -framework OpenGL -framework AppKit
SRC		:= $(wildcard *.c)
OBJ_DIR	:= obj
OBJ		:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC))))
RM		:= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) -c $< -o $@

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
