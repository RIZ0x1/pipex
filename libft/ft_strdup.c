/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:42:28 by jcarlena          #+#    #+#             */
/*   Updated: 2020/10/31 18:42:30 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;

	i = 0;
	while (s1[i])
		(i++);
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		(i++);
	}
	new[i] = '\0';
	return (new);
}
