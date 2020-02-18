# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umoff <umoff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 15:38:52 by umoff             #+#    #+#              #
#    Updated: 2020/02/18 20:12:42 by klaurine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g

SRC_DIR := ./sources
OBJ_DIR := ./objects
INC_DIR := ./includes ./libft/includes
LFT_DIR := ./libft

SRC :=	lem_in.c			\
		flag_parser.c 		\
		reader.c			\
		reader_checks.c		\
		reader_exec.c 		\
		reader_helpers.c 	\
		room_funcs.c		\
		wave_front.c		\
		queue_funcs.c 		\
		detector.c			\
		transfer.c 			\
		ants.c 				\
		matrix.c 			\
		helpers.c			\
		helpers_delete.c 	
		
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INC := $(addprefix -I, $(INC_DIR))

LFT := libft.a

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_DIR) all
	$(CC) $(FLAGS) $(OBJ) $(LFT_DIR)/$(LFT) $(INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@
	
clean:
	make -C $(LFT_DIR) clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LFT_DIR)/$(LFT)
	rm -rf $(NAME)

re: fclean all
