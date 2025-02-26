/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:38:47 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/27 17:52:55 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t l)
{
	size_t	i;
	size_t	ls;
	char	*dest;

	if (!s)
		return (NULL);
	ls = ft_strlen(s);
	if (start >= ls)
		l = 0;
	else if (l > (ls - start))
		l = (ls - start);
	dest = malloc(sizeof(char) * l + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < ls && i < l)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
