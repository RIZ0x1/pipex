#include "header.h"

unsigned	ft_strlen(char *str)
{
	unsigned	n;

	n = 0;
	while (*(str + n))
		(n++);
	return (n);
}

int			the_end(int exit)
{
	char	*error;

	if (exit != 0)
	{
		error = strerror(errno);
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
	}
	return (-1);
}