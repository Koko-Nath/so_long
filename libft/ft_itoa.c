/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:41:35 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/21 18:06:26 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countsize(int n)
{
	size_t		size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	if (n == 0)
		size = 1;
	else
	{
		while (n != 0)
		{
			n = n / 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*dest;
	long	nb;
	int		p;
	size_t	size;

	p = 0;
	size = ft_countsize(n);
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	nb = ((long) n);
	if (nb < 0)
	{
		dest[0] = '-';
		nb *= -1;
		p = 1;
	}
	dest[size] = '\0';
	while ((size - p) != 0)
	{
		dest[size - 1] = ((nb % 10) + '0');
		nb = (nb / 10);
		size--;
	}
	return (dest);
}
