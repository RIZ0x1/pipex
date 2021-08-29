#include "header.h"

int	main(int argc, char **argv, char **envp)
{
	int	exit;
	int	fds[2];
	int	pid;

	errno = 0;
	exit = 0;
	if (argc == 5)
	{
		if (pipe(fds) == -1)
			return (the_end(0));
		pid = fork();
		if (pid == -1)
			return (the_end(0));
		if (pid == 0)
			child_process(fds, argv, envp);
		else
			parent_process(fds, argv, envp);
	}
	else
		exit = ERR_ARG;
	return (the_end(exit));
}
