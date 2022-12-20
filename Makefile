# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 10:23:53 by ^@^ Foxan ^@^     #+#    #+#              #
#    Updated: 2022/11/24 11:27:32 by ^@^ Foxan ^@^    ###   ########.fr        #
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

CC			:= gcc
NAME		:= so_long
SRCS		:= src/main.c \
				src/parsing.c \
				src/images.c \
				src/get_next_line.c \
				src/get_next_line_utils.c \
				src/assets.c \
				src/displaying.c \
				src/maptools.c \
				src/maptools2.c \
				src/arguments.c \
				src/lapinou.c \
				src/lapinou2.c \
				src/lapinou3.c \
				src/inputs.c \
				src/display_count.c \
				src/ft_itoa.c \
				src/ft_strjoin.c \
				src/string_utils.c

CFLAGS		:= -Wextra -Wall -Werror
LIBMLX		:= ./lib/MLX42
LIBGLFW 	:= -L "/System/Volumes/Data/opt/homebrew/lib"
LIBFTPRINTF	:= ./lib/ft_printf

HEADERS		:= -I ./include -I $(LIBMLX)/include
LIBS		:= $(LIBMLX)/libmlx42.a -lglfw $(LIBFTPRINTF)/libftprintf.a
OBJS		:= ${SRCS:.c=.o}

all: startall libmlx libftprintf $(NAME)
	@printf "$(MAGENTA)Done !\n$(RESET)"

#//= Compiling libraries =//#
libmlx:
	@printf "$(MAGENTA)Making MLX...\n$(RESET)" && $(MAKE) -C $(LIBMLX)
	@printf "$(BOLD)Done making $(MAGENTA)MLX\n$(RESET)"
	@printf "$(BOLD)--------------------\n$(RESET)"

libftprintf:
	@printf "$(MAGENTA)Making FTPRINTF...\n$(RESET)" && $(MAKE) -C $(LIBFTPRINTF)
	@printf "$(BOLD)Done making $(MAGENTA)FTPRINTF\n$(RESET)"
	@printf "$(BOLD)--------------------\n$(RESET)"

#//= Compiling source files =//#
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(MAGENTA)SO_LONG$(RESET)$(BOLD) Compiling: $(notdir $<) \n$(RESET)"

$(NAME): start $(OBJS) end
	@printf "$(MAGENTA)Compiling everything...\n$(RESET)"
	@$(CC) -o $(NAME) $(OBJS) $(LIBS) $(HEADERS) $(LIBGLFW)
	@printf "$(BOLD)Done compiling $(MAGENTA)e$(CYAN)v$(GREEN)e$(YELLOW)r$(BLUE)y$(RED)t$(MAGENTA)h$(CYAN)i$(GREEN)n$(YELLOW)g !\n$(RESET)"
	@printf "$(BOLD)--------------------\n$(RESET)"

startall:
	@printf "$(BOLD)--------------------\n$(RESET)"
	@printf "$(MAGENTA)Starting making everything\n$(RESET)"
	@printf "$(BOLD)--------------------\n$(RESET)"

start:
	@printf "$(MAGENTA)Making SO_LONG...\n$(RESET)"

end:
	@printf "$(BOLD)Done making $(MAGENTA)SO_LONG\n$(RESET)"
	@printf "$(BOLD)--------------------\n$(RESET)"

#//= Cleaning rules =//#
clean:
	@rm -f $(OBJS) && printf "$(BLUE)Cleaning SO_LONG...\n$(RESET)"
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFTPRINTF) clean
	@printf "$(YELLOW)Finished cleaning !\n$(RESET)"

fclean: clean
	@printf "$(BOLD)--------------------\n$(RESET)"
	@rm -f $(NAME) && printf "$(BLUE)Fully Cleaning SO_LONG...\n$(RESET)"
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFTPRINTF) fclean
	@printf "$(YELLOW)Finished cleaning everything !\n$(RESET)"

re: fclean all

.PHONY: $(NAME), all, libmlx, libftprintf, start, end, clean, fclean, re
