/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:12:01 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/26 14:33:35 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *block, int c, size_t s)
{
	size_t	i;

	i = 0;
	while (i != s)
	{
		if ((*(unsigned char *)block) == (unsigned char)c)
			return ((void *)block);
		i++;
		block++;
	}
	return (NULL);
}
