
SRCS = ft_strchr.c \
                          ft_isdigit.c \
                          ft_strrchr.c \
                          ft_isalpha.c \
                          ft_strlen.c \
                          ft_tolower.c \
                          ft_atoi.c \
                          ft_isalnum.c \
                          ft_isprint.c \
                          ft_strncmp.c \
                          ft_toupper.c \
                          ft_bzero.c \
                          ft_memchr.c \
                          ft_strlcat.c \
                          ft_memset.c \
                          ft_strlcpy.c \
                          ft_memcmp.c \
                          ft_isascii.c \
                          ft_memcpy.c \
                          ft_memmove.c \
                          ft_calloc.c \
                          ft_strdup.c \
                          ft_strnlen.c \
                          ft_strnstr.c \
                          ft_substr.c \
                          ft_strjoin.c \
                          ft_strtrim.c  \
                          ft_split.c \
                          ft_itoa.c \
                          ft_strmapi.c \
                          ft_striteri.c \
                          ft_putchar_fd.c \
                          ft_putstr_fd.c \
                          ft_putendl_fd.c \
                          ft_putnbr_fd.c \
                          ft_int_putchar.c \
                          ft_int_puthex.c \
                          ft_int_putpointer.c \
                          ft_int_putstr.c \
                          ft_int_putnbr.c \
                          ft_printf.c \
                          ft_joinsplit.c \
                          ft_countchar.c \

BNS_SRCS = ft_lstnew.c \
            ft_lstadd_front.c \
            ft_lstsize.c \
            ft_lstlast.c \
            ft_lstadd_back.c \
            ft_lstdelone.c \
            ft_lstclear.c \
            ft_lstiter.c \
            ft_lstmap.c \

OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:%.c=%.o)

NAME = libft.a
NAMEBONUS = libft.a
FLAGS = -Wall -Wextra -Werror
CC = cc
LIBC = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)																	
	$(LIBC) $(NAME) $(OBJS)

bonus: $(BNS_OBJS) $(OBJS)
	$(LIBC) $(NAME) $(BNS_OBJS) $(OBJS)

clean:
	$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
