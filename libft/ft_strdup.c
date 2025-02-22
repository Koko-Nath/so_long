/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:44:34 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/29 11:46:36 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	l;
	char	*dest;

	if (!src)
		return (NULL);
	i = 0;
	l = ft_strlen(src);
	dest = malloc(sizeof(char) * l + 1);
	if (!dest)
		return (NULL);
	while (i != l)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
