/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:31:45 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/01 20:31:57 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*new;
	char		*p;
	size_t		fullsize;

	fullsize = (count * size);
	new = malloc(fullsize);
	if (new)
	{
		p = new;
		while (fullsize)
		{
			*p = '\0';
			(p++);
			(fullsize--);
		}
	}
	return (new);
}
