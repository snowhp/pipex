# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 07:06:29 by tde-sous          #+#    #+#              #
#    Updated: 2023/04/08 19:35:05 by tde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/pipex.c \
	   src/utils.c \

OBJS = $(SRCS:.c=.o)

NAME = pipex
LIBFT		= libft.a
LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/$(LIBFT)
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBC = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

debug: $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) -g $(SRCS) $(LIBFT_LIB) -o $(NAME)
	
$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKE) --silent

clean:
	cd $(LIBFT_DIR) && $(MAKE) clean
	$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	cd $(LIBFT_DIR) && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: $(LIBFT)