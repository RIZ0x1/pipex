/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:37:27 by jcarlena          #+#    #+#             */
/*   Updated: 2021/11/22 18:38:05 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_getnbrlen(unsigned int nbr)
{
	int	n;

	n = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		(n++);
	}
	return (n);
}

char	*ft_utoa(unsigned int n)
{
	char		*s;
	size_t		len;

	len = ft_getnbrlen(n);
	s = ft_calloc(len + 2, sizeof(char));
	if (!s)
		return (NULL);
	if (n == 0)
	{
		*s = '0';
		return (s);
	}
	while (n > 0)
	{
		s[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
