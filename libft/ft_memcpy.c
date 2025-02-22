/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:48:35 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/21 18:03:08 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t s)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	dest = (unsigned char *) dest;
	while (i != s)
	{
		(*(unsigned char *)dest) = (*(unsigned char *) src);
		dest++;
		src++;
		i++;
	}
	dest -= i;
	return (dest);
}
