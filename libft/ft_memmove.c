/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:08:34 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/21 18:08:51 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t s)
{
	char	*tdest;
	char	*tsrc;

	tdest = (char *) dest;
	tsrc = (char *) src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (s--)
			*tdest++ = *tsrc++;
	}
	else if (dest > src)
	{
		tdest += s - 1;
		tsrc += s - 1;
		while (s--)
			*tdest-- = *tsrc--;
	}
	return (dest);
}
