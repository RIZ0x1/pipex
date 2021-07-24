#include "header.h"

unsigned    ft_strlen(char *str)
{
	unsigned    n;

	n = 0;
	while (*(str + n))
		(n++);
	return (n);
}
