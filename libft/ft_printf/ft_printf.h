/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:56:10 by ntordjma          #+#    #+#             */
/*   Updated: 2024/12/16 21:32:40 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *ptr);
int		ft_put_ptr(unsigned long address);
int		ft_print_hex(unsigned int nb, int uppercase);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_nbr(int nb);
int		ft_check_param(va_list arg_list, const char *str, int i);
int		ft_apply_param(const char *str, size_t i, va_list arg_list);

#endif