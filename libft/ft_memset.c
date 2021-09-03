/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:38:05 by jcarlena          #+#    #+#             */
/*   Updated: 2020/10/28 19:29:39 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t len)
{
	char *tmp_mem;

	tmp_mem = (char*)destination;
	while (len--)
	{
		*tmp_mem = (char)c;
		(tmp_mem++);
	}
	return (destination);
}
