# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 17:00:49 by kimkwanho         #+#    #+#              #
#    Updated: 2021/07/24 18:46:54 by kimkwanho        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO_NAME	=	philo

SRCS 		=	srcs/check.c \
				srcs/exit.c \
				srcs/init.c \
				srcs/main.c \
				srcs/monitor.c \
				srcs/msg.c \
				srcs/start.c \
				srcs/time.c \
				srcs/util1.c \
				srcs/util2.c

CC			=	clang

CFLAGS		=	-Wextra -Werror -Wall -g

HEADER		=	-I /incs

OBJS		=	${SRCS:.c=.o}

.c.o:
	@printf "\033[34m[PHILO]\033[0m Generating .o files : \033[32mOK\033[0m%-33.33s\r\033[0m"
	@${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all: philo

philo: ${OBJS}
	@printf "\n"
	@${CC} ${CFLAGS} ${HEADER} ${OBJS} -o ${PHILO_NAME} -pthread
	@echo "\033[34m[PHILO]\033[0m Building philo program : \033[32mOK\033[0m"
	@make clean

clean:
	@rm -rf ${OBJS}
	@echo "\033[34m[PHILO]\033[0m Delete .o files : \033[32mOK\033[0m"

fclean:	clean
	@rm -rf ${PHILO_NAME}
	@echo "\033[34m[PHILO]\033[0m Delete executable files : \033[32mOK\033[0m"

re: fclean all

.PHONY:	all clean fclean re philo
