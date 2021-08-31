#include "header.h"

#define IN 0
#define OUT 1

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
	if (exit == ERR_ARG)
		write(2, "Wrong number of arguments\n", 26U);
	if (exit == ERR_NOTFOUND)
		write(2, "pipex: command not found\n", 25);
	return ((errno || exit));
}

void	child_process(int fds[2], char *arg1, char *arg2, char **envp)
{
	int		file;
	char	**command;

	file = open(arg1, O_RDONLY);
	if (file == -1)
		the_end(0);
	close(fds[0]);
	dup2(file, IN);
	dup2(fds[1], OUT);
	command = ft_split(arg2, ' ');
	if (execve(get_full_path(command[0], envp), command, envp) == -1)
		the_end(ERR_NOTFOUND);
}

void	parent_process(int fds[2], char *arg3, char *arg4, char **envp, int child_pid)
{
	int		file;
	char	**command;

	waitpid(child_pid, NULL, NULL);
	file = open(arg3, O_WRONLY | O_CREAT | O_TRUNC);
	if (file == -1)
		the_end(0);
	dup2(fds[0], IN);
	close(fds[0]);
	close(fds[1]);
	dup2(file, OUT);
	command = ft_split(arg3, ' ');
	if (execve(get_full_path(command[0], envp), command, envp) == -1)
		the_end(ERR_NOTFOUND);
}
