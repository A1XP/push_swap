# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 17:54:19 by pkhvorov          #+#    #+#              #
#    Updated: 2024/11/29 18:42:12 by pkhvorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAINC	= srcs/main.c 
SRCS	= srcs/nodes_add.c srcs/nodes_init.c srcs/nodes_utils.c srcs/check_errors.c srcs/push_swap.c\
		  srcs/push.c srcs/swap.c srcs/rotate.c srcs/reverse_rotate.c srcs/sort_utils.c srcs/index.c
BSRCS	= srcs/checker/checker.c srcs/checker/get_next_line.c srcs/checker/get_next_line_utils.c

MAINCO	= srcs/main.o
OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE = -I includes
RM		= rm -f
LIBDIR  = ./libft
LIBFT	= ${LIBDIR}/libft.a

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

all: ${NAME}

${NAME}: ${MAINCO} ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${INCLUDE} ${MAINCO} ${OBJS} ${LIBFT} -o ${NAME}

checker: ${BOBJS} ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${INCLUDE} ${BOBJS} ${OBJS} ${LIBFT} -o checker

bonus: $(NAME) checker

${LIBFT}:
	@${MAKE} -C ${LIBDIR}

clean: 
	@${MAKE} -C ${LIBDIR} clean
	@${RM} ${OBJS} ${BOBJS} ${MAINCO}

fclean: clean
	@${MAKE} -C ${LIBDIR} fclean
	@${RM} ${NAME} checker

re: fclean all

.PHONY: all clean fclean re