/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:53:05 by ntordjma          #+#    #+#             */
/*   Updated: 2024/12/16 21:32:28 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_param(va_list arg_list, const char *str, int i)
{
	int		is_negative;
	size_t	l;

	l = 0;
	is_negative = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			is_negative = ft_apply_param(str, i, arg_list);
			if (is_negative < 0)
				return (-1);
			else
			{
				i += 2;
				l += is_negative;
			}
		}
		else if (str[i] != '%' && str[i])
			l += ft_print_char(str[i++]);
	}
	return (l);
}

int	ft_apply_param(const char *str, size_t i, va_list arg_list)
{
	if (str[i + 1] == 'c' && str[i] == '%')
		return (ft_print_char(va_arg(arg_list, int)));
	else if (str[i + 1] == 's' && str[i] == '%')
		return (ft_print_str(va_arg(arg_list, char *)));
	else if (str[i + 1] == 'p' && str[i] == '%')
		return (ft_print_ptr(va_arg(arg_list, void *)));
	else if (str[i + 1] == 'd' && str[i] == '%')
		return (ft_print_nbr(va_arg(arg_list, int)));
	else if (str[i + 1] == 'i' && str[i] == '%')
		return (ft_print_nbr(va_arg(arg_list, int)));
	else if (str[i + 1] == 'u' && str[i] == '%')
		return (ft_print_unsigned(va_arg(arg_list, unsigned int)));
	else if (str[i + 1] == 'x' && str[i] == '%')
		return (ft_print_hex(va_arg(arg_list, int), 1));
	else if (str[i + 1] == 'X' && str[i] == '%')
		return (ft_print_hex(va_arg(arg_list, int), 2));
	else if (str[i + 1] == '%' && str[i] == '%')
		return (ft_print_char('%'));
	else
		return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_list;
	size_t	i;
	size_t	l;

	i = 0;
	if (!str)
		return (-1);
	va_start(arg_list, str);
	l = ft_check_param(arg_list, str, i);
	va_end(arg_list);
	return (l);
}
