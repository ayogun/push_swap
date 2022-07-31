# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:48:18 by yogun             #+#    #+#              #
#    Updated: 2022/07/31 13:20:34 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Colors


NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft
OBJ_DIR = obj/

SRC_DIR = srcs/

SRC =	srcs/push_swap.c \
		srcs/ft_add_back.c \
		srcs/ft_atoi.c \
		srcs/ft_stack_new.c \
		srcs/ft_list_args.c \
		srcs/ft_error_print.c \
		srcs/ft_check_args.c \
		srcs/operations.c \
		srcs/operations_2.c \
		srcs/ft_sort.c \
		srcs/lst_utils.c \
		srcs/lst_utils_2.c \
		srcs/ft_check_sorted.c \
		srcs/ft_check_dup.c \
		srcs/ft_free.c \
		srcs/ft_check_utils.c \
		

OBJ = ${SRC:.c=.o}


.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} ${INCLUDE} -o ${NAME} 


clean:
	${RM} ${OBJ} ${NAME}
	

re: clean all

.PHONY: all clean fclean re bonus