# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-sous <tde-sous@42.porto.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 07:06:29 by tde-sous          #+#    #+#              #
#    Updated: 2023/03/08 12:49:29 by tde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/pipex.c\
	 srcs/utils.c\
	
OBJS = $(SRCS:.c=.o)

NAME = libpipex.a
LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBC = ar rc
RM = rm -f
OUTPUTFILE = a.out

all: $(OUTPUTFILE)

$(OUTPUTFILE): $(OBJS) $(LIBFT_LIB)
	cp $(LIBFT_LIB) $(NAME)													
	$(LIBC) $(NAME) $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -L. -lpipex -o $(OUTPUTFILE)

debug: $(OBJS) $(LIBFT_LIB)
	cp $(LIBFT_LIB) $(NAME)													
	$(LIBC) $(NAME) $(OBJS)
	$(CC) -g $(SRCS) -L. -lpipex -o $(OUTPUTFILE)

clean:
	@make clean -C libft
	$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	@make fclean -C libft
	$(RM) $(NAME) $(OUTPUTFILE)

re: fclean all

$(LIBFT_LIB): makelibft ;

.PHONY: makelibft
makelibft:
	$(MAKE) -C $(LIBFT_DIR)