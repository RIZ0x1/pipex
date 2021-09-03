/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:44:15 by jcarlena          #+#    #+#             */
/*   Updated: 2020/10/31 13:44:22 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	p = (char*)src;
	if (!dst || !src)
		return (0);
	len = ft_strlen(p);
	if (!dstsize)
		return (len);
	while (i < (dstsize - 1) && p[i])
	{
		dst[i] = p[i];
		(i++);
	}
	dst[i] = '\0';
	return (len);
}
