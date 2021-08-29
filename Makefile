CC		?=	gcc
CFLAGS	:=	-g #-Wall -Wextra -Werror
LIB		=	-L ./libft/srcs/ -l ft
NAME	=	pipex
SRCS	=	main.c utils.c
OBJS	=	main.o utils.o
HDRS	=	header.h
TEST	=	test.sh

.PHONY: all clean fclean re test

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

$(OBJS): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -c

test:
	sh $(TEST)