/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:31:11 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/22 23:34:44 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t ecount, size_t esize)
{
	void	*dest;

	if (ecount * esize == 0)
		return (malloc(0));
	if (ecount > (__SIZE_MAX__ / esize))
		return (NULL);
	dest = malloc(esize * ecount);
	if (!dest)
		return (NULL);
	ft_memset(dest, '\0', (ecount * esize));
	return (dest);
}
