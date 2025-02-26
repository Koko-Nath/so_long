/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:44:50 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/25 16:58:39 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t l)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i != (l - 1) && l != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (l > 0)
	{
		dest[i] = '\0';
		i++;
	}
	return (ft_strlen(src));
}
