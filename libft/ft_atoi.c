/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:11:00 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/27 16:03:45 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	size_t		nbr;
	int			i;
	int			p;

	i = 0;
	p = 1;
	nbr = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		p = p * -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		if ((((nbr == (LLONG_MAX / 10) && (str[i] - '0') > (LLONG_MAX % 10))
					|| nbr > (LLONG_MAX / 10)) && p == 1))
			return (-1);
		if ((((nbr == (LLONG_MAX / 10) && (str[i] - '0') > (LLONG_MAX % 10))
					|| nbr > (LLONG_MAX / 10)) && p == -1))
			return (0);
		nbr = nbr * 10 + (str[i++] - '0');
	}
	return (nbr * p);
}
