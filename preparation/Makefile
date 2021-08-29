CC		:=	gcc
NAME	=	out
CFLAGS	=	-g #-Wall -Wextra -Werror
LIB		=	libft.a
SRCS	=	main.c utils.c
OBJS	=	main.o utils.o
HDRS	=	header.h
HDIR	=	.

.PHONY: all clean fclean re

all: $(NAME) clean

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

$(OBJS): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -c