#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"

# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

# define ERR_ARG 0x1
# define ERR_NOTFOUND 0x2


int		the_end(int exit);
void    child_process(int fds[2], char *arg1, char *arg2, char **envp);
void	parent_process(int fds[2], char *arg3, char *arg4, char **envp, int child_pid);

#endif