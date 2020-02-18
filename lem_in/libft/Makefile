# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umoff <umoff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 15:01:26 by umoff             #+#    #+#              #
#    Updated: 2020/02/08 15:01:29 by umoff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		:= gcc -Wall -Wextra -Werror -c

NAME 	:= libft.a

INC_DIR := ./includes

SRC_DIRS := mem_funcs	str_funcs	str_arr_funcs	\
			char_funcs 	list_funcs 	int_funcs		\
			rw_funcs 	ft_printf 	btree_funcs

OBJ_DIR	 := ./objs

MEM_FUNCS 	:= 	ft_memset.c 		\
				ft_bzero.c  		\
				ft_memcpy.c 		\
				ft_memccpy.c 		\
				ft_memmove.c 		\
				ft_memchr.c 		\
				ft_memcmp.c 		\
				ft_memalloc.c 		\
				ft_memdel.c 		\

STR_FUNCS 	:=	ft_strlen.c 		\
				ft_strdup.c 		\
				ft_strcpy.c 		\
				ft_strncpy.c 		\
				ft_strcat.c 		\
				ft_strncat.c 		\
				ft_strlcat.c 		\
				ft_strchr.c 		\
				ft_strrchr.c 		\
				ft_strstr.c 		\
				ft_strnstr.c 		\
				ft_strcmp.c 		\
				ft_strncmp.c 		\
				ft_strnew.c 		\
				ft_strdel.c 		\
				ft_strclr.c 		\
				ft_striter.c 		\
				ft_striteri.c 		\
				ft_strmap.c 		\
				ft_strmapi.c 		\
				ft_strequ.c 		\
				ft_strnequ.c 		\
				ft_strsub.c 		\
				ft_strjoin.c 		\
				ft_strtrim.c 		\
				ft_strsplit.c 		\
				ft_word_count.c 	\
				ft_strrev.c

STR_ARR_FUNCS := ft_clear_strarr.c  \
				 ft_len_strarr.c	\
				 ft_put_strarr.c

CHAR_FUNCS := 	ft_isalpha.c 		\
				ft_isdigit.c 		\
				ft_isalnum.c 		\
				ft_isascii.c 		\
				ft_isprint.c 		\
				ft_toupper.c 		\
				ft_tolower.c 		\
				ft_iswhite.c

LIST_FUNCS :=	ft_lstnew.c 		\
				ft_lstdelone.c 		\
				ft_lstdel.c 		\
				ft_lstadd.c 		\
				ft_lstiter.c 		\
				ft_lstmap.c 		\
				ft_lstadd_back.c 	\
				ft_lstdel_back.c 	\
				ft_lstdel_front.c 	\
				ft_lstlen.c 		\
				ft_lst_erase.c

INT_FUNCS 	:=	ft_atoi.c 				\
				ft_atoi16.c				\
				ft_itoa.c 				\
				ft_itoa_base.c 			\
				ft_itoa_base_unsigned.c \
				ft_itoa_sign.c			\
				ft_itoa_abs.c			\
				ft_ftoa.c 				\
				ft_ftoa_abs.c 			\
				ft_numlen.c				\
				ft_is_number.c

RW_FUNCS 	:= 	get_next_line.c 	\
				ft_putchar.c 		\
				ft_putstr.c 		\
				ft_putendl.c 		\
				ft_putnbr.c 		\
				ft_putchar_fd.c 	\
				ft_putstr_fd.c 		\
				ft_putendl_fd.c 	\
				ft_putnbr_fd.c

FT_PRINTF :=	ft_printf.c		        	\
				parser.c 					\
				checker.c 					\
				former.c 					\
				form_s.c 					\
				form_s_wide.c				\
				form_ct_el.c 				\
				form_c_wide.c				\
				form_i_d.c					\
				form_xoubp.c				\
				form_f.c					\
				form_e.c 					\
				form_date.c 				\
				form_r.c					\
				compute_width.c				\
				compute_width_unsigned.c

BTREE_FUNCS :=	ft_btreenew.c 				\
				ft_btree_insert.c 			\
				ft_btree_find.c 			\
				ft_btreedelone.c 			\
				ft_btree_erase.c			\
				ft_btree_inorder_print.c				
		



SRCS = 	$(MEM_FUNCS)	$(STR_FUNCS)	$(STR_ARR_FUNCS)  	\
		$(CHAR_FUNCS)	$(LIST_FUNCS) 	$(INT_FUNCS)    	\
		$(RW_FUNCS) 	$(FT_PRINTF) 	$(BTREE_FUNCS)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

VPATH := $(SRC_DIRS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $< -I$(INC_DIR) -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re: fclean all