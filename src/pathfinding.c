/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:28:32 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/22 16:02:17 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	pathfinding(t_data *data, int x, int y, char last_move) //faut envoyer la position du joueur
// {
// 	if (data->map[y][x] == 'E')
// 		return (0);
// 	if (last_move != 'A'
// 		&& (data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'E' || data->map[y][x + 1] == 'C'))
// 	{
// 		if(pathfinding(data, x + 1, y, 'D') == 0)
// 			return (0);
// 	}
// 	if (last_move != 'W'
// 		&& (data->map[y + 1][x] == '0' || data->map[y + 1][x] == 'E' || data->map[y + 1][x] == 'C'))
// 	{
// 		if(pathfinding(data, x, y + 1, 'S') == 0)
// 			return (0);
// 	}
// 	if (last_move != 'D'
// 		&& (data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'E' || data->map[y][x - 1] == 'C'))
// 	{
// 		if(pathfinding(data, x - 1, y, 'A') == 0)
// 			return (0);
// 	}
// 	if (last_move != 'S'
// 		&& (data->map[y - 1][x] == '0' || data->map[y - 1][x] == 'E' || data->map[y - 1][x] == 'C'))
// 	{
// 		if(pathfinding(data, x, y - 1, 'W') == 0)
// 			return (0);
// 	}
// 	return (1);
// }

int	pathfinding(t_data *data, int x, int y, char last_move)
{
	if (data->map[y][x] == 'E')
		return (0);
	if (data->map[y][x] == 'V')
		return (1);
	//char original = data->map[y][x];
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
	//data->map[y][x] = original;
	return (1);
}






