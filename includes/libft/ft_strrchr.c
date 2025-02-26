/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:07:04 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/27 16:04:02 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t		i;

	i = ft_strlen(str);
	while (i != 0 && str[i] != (char) c)
		i--;
	if (str[i] == (char) c)
		return ((char *) &str[i]);
	else
		return ((void *) NULL);
}
