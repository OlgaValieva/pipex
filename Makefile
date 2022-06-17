# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carys <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 12:11:13 by carys             #+#    #+#              #
#    Updated: 2022/03/25 12:11:17 by carys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

HEADER	=	pipex.h

SRCS	=	pipex.c	utils.c	path.c	ft_split.c

OBJS	=	${SRCS:%.c=%.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -I${HEADER}

.PHONY	=	all clean fclean re

all:	${NAME}

%.o:		%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:		${OBJS} ${HEADER}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all