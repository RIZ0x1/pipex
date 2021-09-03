/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:21:03 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/03 18:43:54 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*ps;
	char	*pd;
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	ps = (char*)src;
	pd = (char*)dst;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (*pd)
		(pd++);
	while (ps[i] && i < (dstsize - dstlen - 1))
	{
		pd[i] = ps[i];
		(i++);
	}
	pd[i] = '\0';
	return (dstlen + srclen);
}
