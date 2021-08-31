CC		?=	gcc
CFLAGS	:=	-g #-Wall -Wextra -Werror
NAME	=	pipex
LIB		=	-L ./libft/ -l ft
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

test:
	sh $(TEST)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

$(OBJS): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -c

$(LIB): ./libft/libft.a
	make -C ./libft/
