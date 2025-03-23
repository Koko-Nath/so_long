/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:54:39 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/23 22:54:03 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_path(char *map_path)
{
	int fd;
	
	//checker le format .ber et non .txt
	fd = open((const char*) map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, invalid map path🗺️\n");
		return(1);
	}
	close(fd);
	return (0);
}

int	check_char(int x_max, char **map)
{
	int x;
	int y;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (x < x_max - 1)
		{
			if (map[y][x] != '0' && 
				map[y][x] != '1' &&
				 map[y][x] != 'C' &&
				  map[y][x] != 'E' &&
				   map[y][x] != 'P')
			{
				ft_printf("Error, invalid character in map🌧️\n");
				return(1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	full_checker(t_data *data)
{
	if (check_map_path(data->map.path) == 1)
		return (1);
	if (check_char(data->x_width, data->map.matrix) == 1)
		return (1);
	if (check_map_shape(data->map.matrix, data->y_height) == 1)
		return (1);
	if (check_map_border(data->map.matrix, data->y_height, data->x_width) == 1)
		return (1);
	if (check_items_nbr(data, data->map.matrix) == 1)
		return (1);
	if (check_player_nbr(data->map.matrix) == 1)
		return (1);
	if (check_exit_nbr(data->map.matrix) == 1)
		return (1);
	//if (check_pathfinding(data) == 1)
	//	return (1);
	return (0);
}
