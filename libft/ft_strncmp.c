/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:29:57 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/21 18:04:27 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *sec, size_t length)
{
	size_t	i;

	i = 0;
	while (i != length)
	{
		if ((*(unsigned char *)first) > (*(unsigned char *)sec))
			return (1);
		else if ((*(unsigned char *)first) < (*(unsigned char *)sec))
			return (-1);
		else if ((*(unsigned char *)first) == '\0'
			&& (*(unsigned char *)sec) == '\0')
			return (0);
		else if ((*(unsigned char *)first) == (*(unsigned char *)sec))
		{
			i++;
			first++;
			sec++;
		}
	}
	return (0);
}
