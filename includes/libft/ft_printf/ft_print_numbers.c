/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:37:59 by ntordjma          #+#    #+#             */
/*   Updated: 2024/12/16 21:30:25 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nb, int uppercase)
{
	size_t			l;
	char			*hex;
	unsigned int	unb;

	l = 0;
	unb = (unsigned int) nb;
	if (uppercase == 1)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (unb >= 16)
		l += ft_print_hex(unb / 16, uppercase);
	l += ft_print_char(hex[unb % 16]);
	return (l);
}

int	ft_print_unsigned(unsigned int nb)
{
	size_t	l;

	l = 0;
	if (nb >= 10)
	{
		l += ft_print_unsigned(nb / 10);
	}
	l += ft_print_char((nb % 10) + '0');
	return (l);
}

int	ft_print_nbr(int nb)
{
	size_t	l;

	l = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		l += ft_print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
		l += ft_print_nbr(nb / 10);
	l += ft_print_char((nb % 10) + '0');
	return (l);
}
