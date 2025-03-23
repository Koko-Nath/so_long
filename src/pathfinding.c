/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:26:40 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/23 22:30:13 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	pathfinding_c_to_e(t_data *data, char **map, int x, int y, char last_move)
// {
// 	if (map[y][x] == 'E')
// 		return (0);
// 	if (map[y][x] == 'V')
// 		return (1);
// 		map[y][x] = 'V'; 
// 	if (last_move != 'A' && x + 1 < data->y_height &&
// 		(map[y][x + 1] == '0' || map[y][x + 1] == 'E' || map[y][x + 1] == 'C'))
// 		if (pathfinding(data, map, x + 1, y, 'D') == 0)
// 			return (0);
// 	if (last_move != 'W' && y + 1 < data->y_height &&
// 		(map[y + 1][x] == '0' || map[y + 1][x] == 'E' || map[y + 1][x] == 'C'))
// 		if (pathfinding(data, map, x, y + 1, 'S') == 0)
// 			return (0);
// 	if (last_move != 'D' && x - 1 >= 0 &&
// 		(map[y][x - 1] == '0' || map[y][x - 1] == 'E' || map[y][x - 1] == 'C'))
// 		if (pathfinding(data, map, x - 1, y, 'A') == 0)
// 			return (0);
// 	if (last_move != 'S' && y - 1 >= 0 &&
// 		(map[y - 1][x] == '0' || map[y - 1][x] == 'E' || map[y - 1][x] == 'C'))
// 		if (pathfinding(data, map, x, y - 1, 'W') == 0)
// 			return (0);
// 	return (1);
// }

// int	pathfinding_c_to_c(t_data *data, char **map, int x, int y, char last_move)
// {
// 	if (map[y][x] == 'E')
// 		return (0);
// 	if (map[y][x] == 'V')
// 		return (1);
// 		map[y][x] = 'V'; 
// 	if (last_move != 'A' && x + 1 < data->y_height &&
// 		(map[y][x + 1] == '0' || map[y][x + 1] == 'E' || map[y][x + 1] == 'C'))
// 		if (pathfinding(data, map, x + 1, y, 'D') == 0)
// 			return (0);
// 	if (last_move != 'W' && y + 1 < data->y_height &&
// 		(map[y + 1][x] == '0' || map[y + 1][x] == 'E' || map[y + 1][x] == 'C'))
// 		if (pathfinding(data, map, x, y + 1, 'S') == 0)
// 			return (0);
// 	if (last_move != 'D' && x - 1 >= 0 &&
// 		(map[y][x - 1] == '0' || map[y][x - 1] == 'E' || map[y][x - 1] == 'C'))
// 		if (pathfinding(data, map, x - 1, y, 'A') == 0)
// 			return (0);
// 	if (last_move != 'S' && y - 1 >= 0 &&
// 		(map[y - 1][x] == '0' || map[y - 1][x] == 'E' || map[y - 1][x] == 'C'))
// 		if (pathfinding(data, map, x, y - 1, 'W') == 0)
// 			return (0);
// 	return (1);
// }

int	pathfinding(t_map *data, char **map, int x, int y, char last_move)
{
	if (map[y][x] == 'E' || map[y][x] == 'C')
	{
		map[y][x] = 'V';
		return (0);
	}
	map[y][x] = 'V';
	if (last_move != 'A' && (map[y][x + 1] != '1'))
		if(pathfinding(data, map, x + 1, y, 'D') == 0)
			return(0);
	if (last_move != 'W' && (map[y + 1][x] != '1'))
		if(pathfinding(data, map, x, y + 1, 'S') == 0)
			return (0);
	if (last_move != 'D' && (map[y][x - 1]!= '1'))
		if(pathfinding(data, map, x - 1, y, 'A') == 0)
			return (0);
	if (last_move != 'S' && (map[y - 1][x] != '1'))
		if(pathfinding(data, map, x, y - 1, 'W') == 0)
			return (0);
	return (1);
}

int	check_pathfinding(t_data *data)
{
	int		p_x;
	int		p_y;
	int		i;
	int		check_left;
	t_map	stash_map;

	check_left = data->nbr_collec;
	stash_map.matrix = NULL;
	stash_map.x_max = data->x_width;
	stash_map.y_max = data->y_height;
	stash_map.matrix = init_map(data);
	p_x = data->sprites.player.img_x;
	p_y = data->sprites.player.img_y;
	i = 0;
	while (i <= check_left)
	{
		if (pathfinding(&stash_map, stash_map.matrix, p_x, p_y, 'T') == 1)
		{
			ft_printf("%s\n", "Error, no path found");
			return (1);
		}
		i++;
	}
	free (stash_map.matrix);
	return (0);
}