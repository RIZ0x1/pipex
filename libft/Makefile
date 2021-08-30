NAME	=	libft.a
SRCS	=	ft_atoi.c ft_isascii.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_strtrim.c		\
			ft_bzero.c ft_isdigit.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_substr.c	\
			ft_calloc.c ft_isprint.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c	\
			ft_isalnum.c ft_itoa.c ft_memmove.c ft_putstr_fd.c ft_strlcat.c ft_strnstr.c ft_toupper.c	\
			ft_isalpha.c ft_memccpy.c ft_memset.c ft_split.c ft_strlcpy.c ft_strrchr.c

BNS		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c		\
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c	\
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

$(NAME): $(SRCS)
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar -rcs $(NAME) *.o

all: $(NAME)

bonus: $(BNS)
	gcc -Wall -Wextra -Werror -c $(BNS)
	ar -rcs $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
