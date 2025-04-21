/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:04 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/21 17:29:00 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_file(int fd)
{
	int	result;

	result = close(fd);
	if (result == -1)
	{
		perror("Error.\nIn close_file ");
		exit(1);
		return (result);
	}
	else
		return (result);
}

static int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error.\nIn open_file ");
		exit(1);
		return (1);
	}
	else
		return (fd);
}

char	**init_map(t_data *data)
{
	int		fd;
	int		i;
	char	**map;

	i = -1;
	map = ft_calloc(sizeof(char *), data->y_height + 1);
	if (!map)
	{
		ft_printf("Error\nError initializing map\n");
		end_program(data);
	}
	fd = open_file(data->map.path);
	while (++i != (int)data->y_height - 1)
	{
		map[i] = (get_next_line(fd));
		if (ft_strlen(map[i]) == 1 && map[i][0] == '\n')
		{
			ft_printf("Error\n empty line found in map\n");
			free_map(map);
			close_file(fd);
			end_program(data);
		}
	}
	close_file(fd);
	return (map);
}

