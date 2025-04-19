/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:26:40 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/19 16:05:55 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pathfinding(char **map, size_t y, size_t x, t_map *stash_map)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'X' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E' || map[y][x] == 'C')
		stash_map->c_left++;
	map[y][x] = 'V';
	(pathfinding(map, y, x + 1, stash_map));
	(pathfinding(map, y + 1, x, stash_map));
	(pathfinding(map, y, x - 1, stash_map));
	(pathfinding(map, y - 1, x, stash_map));
}

int	check_pathfinding(t_data *data)
{
	int		p_x;
	int		p_y;
	t_map	stash_map;

	stash_map.c_left = 0;
	stash_map.matrix = NULL;
	stash_map.x_max = data->x_width;
	stash_map.y_max = data->y_height;
	stash_map.matrix = init_map(data);
	p_x = data->sprites.player.img_x;
	p_y = data->sprites.player.img_y;
	pathfinding(stash_map.matrix, p_y, p_x, &stash_map);
	ft_printf("%s%d\n", "check_left = ", stash_map.c_left);
	if (stash_map.c_left != (data->nbr_collec + 1))
	{
		free (stash_map.matrix);
		ft_printf("%s\n", "Error. \n no path found");
		return (1);
	}
	free (stash_map.matrix);
	return (0);
}
