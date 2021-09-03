/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:36:58 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/03 18:42:53 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	if (!n)
		return (0);
	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	i = 0;
	while (ps1[i] == ps2[i])
	{
		(i++);
		if ((i == n) || !(s1[i] || s2[i]))
			return (0);
	}
	return (ps1[i] - ps2[i]);
}
