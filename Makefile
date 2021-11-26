CC			?=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
NAME		=	pipex
DEPS		=	-L ./libft/ -l ft

LIB			=	./libft/libft.a
SRCS		=	main.c utils.c
OBJS		=	main.o utils.o
HDRS		=	header.h
TEST		=	test.sh

.PHONY: all clean fclean re test

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

test:
	bash $(TEST) 2> /dev/null

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(DEPS) -o $(NAME)

$(OBJS): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -c

$(LIB):
	make -C ./libft/
