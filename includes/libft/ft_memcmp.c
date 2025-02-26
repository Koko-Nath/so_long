/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:36:04 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/21 18:09:02 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t s)
{
	size_t	i;

	i = 0;
	while (i != s)
	{
		if ((*(unsigned char *) ptr1) > (*(unsigned char *) ptr2))
			return (1);
		else if ((*(unsigned char *) ptr1) < (*(unsigned char *) ptr2))
			return (-1);
		i++;
		ptr1++;
		ptr2++;
	}
	return (0);
}
