/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:27:02 by jcarlena          #+#    #+#             */
/*   Updated: 2020/10/29 17:27:04 by jcarlena         ###   ########.fr       */
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
		return ((char*)haystack);
	if (needle)
		while (haystack[i] && (i < len))
		{
			j = i;
			k = 0;
			while (j < len && haystack[j] && (haystack[j] == needle[k]))
			{
				(j++);
				(k++);
			}
			if (!needle[k])
				return ((char*)&(haystack[i]));
			(i++);
		}
	return (NULL);
}
