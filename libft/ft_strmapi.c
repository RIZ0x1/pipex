/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:40:38 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/07 12:40:41 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	new = ft_substr(s, 0, (ft_strlen(s)));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		(i++);
	}
	return (new);
}
