/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:27:02 by jcarlena          #+#    #+#             */
/*   Updated: 2021/09/10 15:33:07 by tasian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] && (i < len) && needle)
	{
		j = i;
		k = 0;
		while (j < len && haystack[j] && (haystack[j] == needle[k]))
		{
			(j++);
			(k++);
		}
		if (!needle[k])
			return ((char *)&(haystack[i]));
		(i++);
	}
	return (NULL);
}
