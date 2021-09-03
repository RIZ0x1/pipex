/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:08:28 by jcarlena          #+#    #+#             */
/*   Updated: 2020/10/31 15:08:29 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *p;

	p = (char*)s;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		(p++);
	}
	if (!c)
		return (p);
	else
		return (NULL);
}
