/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:02:57 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/22 18:36:57 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_one_border(t_data *data, char **map, int y, int x)
{
	if (y == 0 || y == data->y_height - 1)
	{
		if (map[y][x] != '1')
		{
			ft_printf("Error, invalid map border🌳\n");
			end_program(data);
		}
	}
	if (x == 0 || x == data->x_width - 1)
	{
		if (map[y][0] != '1' || map[y][data->x_width - 1] != '1')
		{
			ft_printf("Error, invalid map border🌳\n");
			end_program(data);
		}
	}
}

void	check_map_border(t_data *data, char **map, int y_max, int x_max)
{
	int x;
	int y;
	
	y = 0;
	while (y < data->y_height)
	{
		x = 0;
		while (x != x_max)
		{
			check_one_border(data, map, y, x);
			x++;
		}
		y++;
	}
}

void	check_map_shape(t_data *data, char **map, int y_max)
{
	int y;
		
	y = 0;	
	while (y < y_max - 1)
	{
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
		{
			ft_printf("Error, invalid map shape🔶\n");
			end_program(data);
		}
		y++;
	}
	if (ft_strlen(map[y]) != ft_strlen(map[0]) - 1)
	{
		ft_printf("Error, invalid map shape🔶\n");
		end_program(data);
	}
}

int	check_pathfinding(t_data *data, int x, int y, char last_move)
{
	if (data->map[y][x] == 'E')
		return (0);
	if (data->map[y][x] == 'V')
		return (1);
		data->map[y][x] = 'V'; 
	if (last_move != 'A' && x + 1 < data->map_width &&
		(data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'E' || data->map[y][x + 1] == 'C'))
		if (pathfinding(data, x + 1, y, 'D') == 0)
			return (0);

	if (last_move != 'W' && y + 1 < data->map_height &&
		(data->map[y + 1][x] == '0' || data->map[y + 1][x] == 'E' || data->map[y + 1][x] == 'C'))
		if (pathfinding(data, x, y + 1, 'S') == 0)
			return (0);

	if (last_move != 'D' && x - 1 >= 0 &&
		(data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'E' || data->map[y][x - 1] == 'C'))
		if (pathfinding(data, x - 1, y, 'A') == 0)
			return (0);

	if (last_move != 'S' && y - 1 >= 0 &&
		(data->map[y - 1][x] == '0' || data->map[y - 1][x] == 'E' || data->map[y - 1][x] == 'C'))
		if (pathfinding(data, x, y - 1, 'W') == 0)
			return (0);
	return (1);
}
