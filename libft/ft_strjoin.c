/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:28:12 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/29 11:10:36 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	y;
	size_t	l;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	l = (ft_strlen(s1) + ft_strlen(s2));
	dest = malloc(sizeof(char) * l + 1);
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y] != '\0')
	{
		dest[i + y] = s2[y];
		y++;
	}
	dest[i + y] = '\0';
	return (dest);
}
