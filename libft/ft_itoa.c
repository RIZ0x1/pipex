/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:55:02 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/07 17:55:03 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getnbrlen(long int nbr)
{
	int n;

	if (nbr <= 0)
	{
		nbr = -nbr;
		n = 1;
	}
	else
		n = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		(n++);
	}
	return (n);
}

char			*ft_itoa(int n)
{
	char		*s;
	size_t		len;
	long int	nl;

	nl = n;
	len = ft_getnbrlen(nl) - 1;
	if (!(s = ft_calloc(len + 2, sizeof(char))))
		return (NULL);
	if (nl == 0)
	{
		*s = '0';
		return (s);
	}
	if (nl < 0)
	{
		*s = '-';
		nl = -nl;
	}
	while (nl > 0)
	{
		s[len--] = (nl % 10) + '0';
		nl /= 10;
	}
	return (s);
}
