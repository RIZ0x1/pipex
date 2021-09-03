/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:28:32 by jcarlena          #+#    #+#             */
/*   Updated: 2020/10/30 20:28:35 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*pd;
	char	*ps;

	i = 0;
	pd = (char*)dst;
	ps = (char*)src;
	if (pd > ps)
		while (len--)
			pd[len] = ps[len];
	else if (ps > pd)
		while (i < len)
		{
			pd[i] = ps[i];
			(i++);
		}
	return (dst);
}
