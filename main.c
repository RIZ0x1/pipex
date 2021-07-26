#include "header.h"

int		main(int argc, char **argv)
{
	int		fd_1;
	int		fd_2;
	int		exit;

	errno = 0;
	exit = EXIT_SUCCESS;
	if (argc == 5)
	{
		fd_1 = open(argv[1], O_RDONLY);
		fd_2 = open(argv[4], O_WRONLY);

		

		close(fd_1);
		close(fd_2);
	}
	else
		exit = EXIT_FAILURE;

	return (the_end(exit));
}
