#include "libft.h"

size_t	ft_lendec_strbin(char *bin)
{
	size_t			highbit;
	size_t			lendec;
	const float		log2_10 = 0.301;

	highbit = (ft_strlen(bin) - (ft_strchr(bin, '1') - bin));
	lendec = (log2_10 * highbit) + 1;
	return (lendec);
}
