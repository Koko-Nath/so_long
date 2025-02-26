/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:12:50 by ntordjma          #+#    #+#             */
/*   Updated: 2024/12/16 21:30:18 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(unsigned long address)
{
	char	*hex;
	char	buffer[16];
	size_t	i;
	size_t	l;

	i = 0;
	hex = "0123456789abcdef";
	while (address > 0)
	{
		buffer[i++] = hex[address % 16];
		address /= 16;
	}
	l = 2;
	write(1, "0x", 2);
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		l++;
	}
	return (l);
}

int	ft_print_ptr(void *ptr)
{
	size_t	l;
	size_t	address;

	l = 0;
	address = (unsigned long)ptr;
	if (ptr == NULL || ptr == 0)
		return (write(1, "(nil)", 5));
	else
		l += ft_put_ptr(address);
	return (l);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	size_t	l;

	l = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[l])
		l++;
	return (write(1, str, l));
}
