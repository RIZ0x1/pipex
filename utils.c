#include "header.h"

int	the_end(int exit)
{
	char	*error;

	if (errno || exit)
		write(2, "Error: ", 7U);
	if (errno != 0)
	{
		error = strerror(errno);
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
		return (errno);
	}
	if (exit != 0)
	{
		if (exit == ERR_ARG)
			write(2, "Wrong number of arguments\n", 26U);
	}
	return (1);
}

void	child_process(int fds[2], char *arg1, char *arg2, char **envp)
{
	close(fds[0]);
	dup2(fds[1], 1);
	
}

void	parent_process(int fds[2], char *arg3, char *arg4, char **envp)
{
	int	file;

	file = open(arg3, O_RDONLY);
	
}