/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:45:47 by jcarlena          #+#    #+#             */
/*   Updated: 2020/10/30 20:45:50 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;

	p = (unsigned char*)s;
	while (n > 0)
	{
		if (*p == (unsigned char)c)
			return (p);
		(p++);
		(n--);
	}
	return (NULL);
}
