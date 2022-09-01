# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:48:18 by yogun             #+#    #+#              #
#    Updated: 2022/09/01 20:23:46 by yogun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = srcs/

SRC_1 = srcs/push_swap/push_swap.c \

SRC_2 =	srcs/push_swap/algorithm.c \
		srcs/push_swap/ft_add_back.c \
		srcs/push_swap/ft_stack_new.c \
		srcs/push_swap/ft_check_utils.c \
		srcs/push_swap/ft_parse.c \
		srcs/push_swap/solver_utils_ab.c \
		srcs/push_swap/solver_utils_ba.c \
		srcs/push_swap/ft_rotate_and_push.c \
		srcs/push_swap/operations.c \
		srcs/push_swap/operations_2.c \
		srcs/push_swap/operations_3.c \
		srcs/push_swap/ft_check_dup.c \
		srcs/push_swap/ft_check_sorted.c \
		srcs/push_swap/ft_error_print.c \
		srcs/push_swap/ft_free.c \
		srcs/push_swap/lst_utils.c \
		srcs/push_swap/lst_utils_2.c \
		srcs/push_swap/ft_parse_args_quoted.c \
		srcs/push_swap/ft_list_args.c \
		srcs/push_swap/ft_check_args.c \
		srcs/push_swap/ft_sort_big.c \
		srcs/push_swap/ft_sort_three.c \
		srcs/push_swap/ft_rotate_type.c \
		
BONUS_SRC = srcs/checker/checker.c \
			srcs/checker/checker_utils.c \
			

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_2} ${BONUS_OBJ} 
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus