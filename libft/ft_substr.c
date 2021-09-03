/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:25:02 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/04 02:25:04 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*k;

	if ((p = ft_calloc(len + 1, sizeof(char))) == NULL || !s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (p);
	k = p;
	while (len-- && s[start])
	{
		*p = s[start];
		(start++);
		(p++);
	}
	return (k);
}
