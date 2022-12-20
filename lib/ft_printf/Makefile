# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:     #
#                                                     +:+ +:+         +:+      #
#    By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 10:29:40 by ^@^ Foxan ^@^     #+#    #+#              #
#    Updated: 2022/11/07 10:29:42 by ^@^ Foxan ^@^    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

CC = gcc
NAME = libftprintf.a
SRCS = ft_printf.c printf_putcharstr.c printf_putnrbs.c printf_puthex.c
INCLUDES = includes
FLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES} && printf "$(GREEN)FTPRINTF$(RESET)$(BOLD) Compiling: $(notdir $<) \n$(RESET)"

clean:
	@rm -f ${OBJS} && printf "$(BLACK)Cleaning PRINTF$(RESET)\n"

fclean: clean
	@rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
