# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:48:18 by yogun             #+#    #+#              #
#    Updated: 2022/07/27 19:38:10 by yogun            ###   ########.fr        #
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
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft

SRC =	push_swap.c \
		ft_add_back.c \
		ft_atoi.c \
		ft_stack_new.c \
		list_args.c \
		error_print.c \
		check_args.c \
		operations.c

OBJ = ${SRC:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} ${INCLUDE} -o ${NAME} 


clean:
	${RM} ${OBJ} ${NAME}
	

re: clean all

.PHONY: all clean fclean re bonus