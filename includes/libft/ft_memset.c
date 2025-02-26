/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:12:24 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/21 18:09:16 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *) src;
	i = 0;
	while (i != n)
	{
		dest[i] = (unsigned char) c;
		i++;
	}
	return (src);
}
