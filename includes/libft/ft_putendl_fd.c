/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:49:24 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/29 12:03:40 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *str, int fd)
{
	int		i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		write (fd, &str[i++], 1);
	write (fd, "\n", 1);
}
