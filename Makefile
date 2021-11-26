CC			?=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
NAME		=	pipex
LIB			=	-L ./libft/ -l ft
SRCS		=	main.c utils.c
OBJS		=	main.o utils.o
HDRS		=	header.h
TEST		=	test.sh
TEST_FILES	=	.jcarlena_pipex_err .jcarlena_pipex_out .jcarlena_shell_err .jcarlena_shell_out

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
	rm -f $(TEST_FILES)
	bash $(TEST) 2> /dev/null

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

$(OBJS): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -c

$(LIB):
	make -C ./libft/
