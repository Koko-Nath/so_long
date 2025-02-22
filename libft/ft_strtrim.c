/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:18:58 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/27 17:53:50 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_checkend(char const *str, char const *set)
{
	size_t	i;
	size_t	y;

	i = ft_strlen(str);
	if (i == 0)
		return (0);
	i--;
	y = 0;
	while (set[y] != '\0' && i > 0)
	{
		if (str[i] == set[y])
		{
			i--;
			y = 0;
		}
		else
			y++;
	}
	return (i);
}

static size_t	ft_checkstart(char const *str, char const *set)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (set[y] != '\0')
	{
		if (str[i] == set[y])
		{
			i++;
			y = 0;
		}
		else
			y++;
	}
	return (i);
}

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*dest;

	if (!str || !set)
		return (NULL);
	i = 0;
	start = ft_checkstart(str, set);
	end = ft_checkend(str, set);
	if (start > end || (start == end && end == 0))
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * (end - start) + 2);
	if (!dest)
		return (NULL);
	i = 0;
	while (i <= (end - start))
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
