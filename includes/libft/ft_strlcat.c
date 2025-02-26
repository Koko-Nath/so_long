/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:25:09 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/21 22:22:15 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		dl;
	size_t		y;
	size_t		i;

	dl = ft_strlen(dest);
	y = dl;
	i = 0;
	while (src[i] != '\0' && (i + y + 1) < size)
	{
		dest[i + y] = src[i];
		i++;
	}
	if (i < size)
		dest[i + y] = '\0';
	if (size <= dl)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + dl);
}
