/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:26:17 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/03 18:42:34 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t cnt)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char*)dst;
	s = (char*)src;
	while (s[i] != (char)c)
	{
		if (i >= cnt)
			return (NULL);
		d[i] = s[i];
		(i++);
	}
	d[i] = s[i];
	(i++);
	return (&d[i]);
}
