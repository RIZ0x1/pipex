#ifndef HEADER_H
# define HEADER_H

# include "libft/srcs/libft.h"

# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

# define ERR_ARG 1

int			the_end(int exit);
void		child_process(int fds[2], char **argv, char **envp);
void		parent_process(int fds[2], char **argv, char **envp);



#endif