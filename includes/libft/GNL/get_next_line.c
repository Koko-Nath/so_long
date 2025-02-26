/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 02:36:30 by ntordjma          #+#    #+#             */
/*   Updated: 2025/02/26 00:15:35 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_line(char *buffer, char **line)
{
	int	bufsize;

	bufsize = ft_strlen_to_charset(buffer, '\n');
	*line = ft_str_join_lines(*line, buffer, bufsize);
	if (ft_gnl_strchr(buffer, '\n'))
	{
		ft_gnl_strlcpy(buffer, ft_gnl_strchr(buffer, '\n') + 1, BUFFER_SIZE + 1);
		return (1);
	}
	buffer[0] = '\0';
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			nbr_read;

	if (fd < 0 && fd > FD_MAX)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (!buffer[fd][0])
		{
			nbr_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (nbr_read < 0)
			{
				free(line);
				buffer[fd][0] = '\0';
				return (NULL);
			}
			buffer[fd][nbr_read] = '\0';
			if (nbr_read == 0)
				return (line);
		}
		if (ft_get_line(buffer[fd], &line))
			return (line);
	}
}
