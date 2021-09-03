/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:07:26 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/01 20:32:43 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	if (!n)
		return (0);
	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	i = 0;
	while ((i < (n - 1)) && ((char)ps1[i] == (char)ps2[i]))
		(i++);
	return (ps1[i] - ps2[i]);
}
