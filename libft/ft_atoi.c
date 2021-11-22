/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:11:20 by jcarlena          #+#    #+#             */
/*   Updated: 2021/11/22 18:31:53 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			neg;
	long int	sum;

	neg = 1;
	sum = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		(str++);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		(str++);
	}
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - '0');
		if (sum >= 2147483648 && neg == 1)
			return (-1);
		if (sum <= -2147483648 && neg == -1)
			return (0);
		(str++);
	}
	return (sum * neg);
}
