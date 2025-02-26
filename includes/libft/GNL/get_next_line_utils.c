/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 02:48:40 by ntordjma          #+#    #+#             */
/*   Updated: 2025/02/26 00:14:33 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_to_charset(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c && c == '\n')
		i++;
	return (i);
}

char	*ft_gnl_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (0);
}

size_t	ft_gnl_strlcpy(char *dest, char *src, size_t l)
{
	size_t	i;

	i = 0;
	if (l == 0)
		return (ft_strlen_to_charset(src, '\0'));
	while (src[i] && i < l - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen_to_charset(dest, '\0'));
}

char	*ft_str_join_lines(char *s1, char *s2, int bufsize)
{
	int		i;
	int		j;
	int		l1;
	char	*dest;

	i = -1;
	j = -1;
	if (!s2)
		return (NULL);
	l1 = 0;
	if (s1)
		l1 = ft_strlen_to_charset(s1, '\0');
	dest = malloc(sizeof(char) * (l1 + bufsize + 1));
	if (!dest)
	{
		free (s1);
		return (NULL);
	}
	while (++i < l1)
		dest[i] = s1[i];
	while (++j < bufsize)
		dest[i + j] = s2[j];
	dest[l1 + bufsize] = '\0';
	free (s1);
	return (dest);
}
