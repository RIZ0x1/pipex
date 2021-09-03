/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 08:19:22 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/06 08:19:24 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	long int nb;

	nb = (long int)nbr;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd((nb / 10), fd);
	ft_putchar_fd((char)(nb % 10 + 48), fd);
}
