/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:21:38 by jcarlena          #+#    #+#             */
/*   Updated: 2020/10/31 15:21:43 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (char*)s;
	i = 0;
	while (p[i])
		(i++);
	while (i >= 0)
	{
		if (p[i] == (char)c)
			return (&p[i]);
		(i--);
	}
	return (NULL);
}
