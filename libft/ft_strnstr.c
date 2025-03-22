/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:52:00 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/21 18:04:40 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t l)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < l && big[i] != '\0')
	{
		y = 0;
		while (big[i + y] == little[y] && (i + y) < l && big[i + y] != '\0')
		{
			y++;
			if (little[y] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
