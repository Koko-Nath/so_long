/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 20:26:40 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/21 17:20:31 by ntordjma         ###   ########.fr       */
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
	ft_bzero(&stash_map, sizeof(t_map));
	stash_map.matrix = NULL;
	stash_map.x_max = data->x_width;
	stash_map.y_max = data->y_height;
	stash_map.matrix = init_map(data);
	p_x = data->player_x;
	p_y = data->player_y;
	pathfinding(stash_map.matrix, p_y, p_x, &stash_map);
	if (stash_map.c_left != (data->nbr_collec + 1))
	{
		free_map(stash_map.matrix);
		ft_printf("Error\nno path found 🛤️\n");
		return (1);
	}
	free_map(stash_map.matrix);
	return (0);
}
