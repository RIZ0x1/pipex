#include "header.h"

#define CHILD 0

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
			the_end(0);
		pid = fork();
		if (pid == -1)
			the_end(0);
		if (pid == CHILD)
			child_process(fds, argv[1], argv[2], envp);
		else
			parent_process(fds, argv[3], argv[4], envp, pid);
	}
	else
		the_end(ERR_ARG);
	return (0);
}
