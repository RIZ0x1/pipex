/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:25:55 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/04 23:25:57 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	char			*k;
	unsigned int	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((p = ft_calloc(size + 1, sizeof(s1))) == NULL)
		return (NULL);
	k = p;
	while (*s1)
	{
		(*p) = (*s1);
		(p++);
		(s1++);
	}
	while (*s2)
	{
		(*p) = (*s2);
		(p++);
		(s2++);
	}
	return (k);
}
