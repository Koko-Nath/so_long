/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:02:57 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/23 20:55:28 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_one_border(char **map, int y, int x, int y_max, int x_max)
{
	if (y == 0 || y == y_max - 1)
	{
		if (map[y][x] != '1')
		{
			ft_printf("Error, invalid map border🌳\n");
			return (1);
		}
	}
	if (x == 0 || x == x_max - 2)
	{
		if (map[y][0] != '1' || map[y][x_max - 2] != '1')
		{
			ft_printf("Error, invalid map border🌳\n");
			return (1);
		}
	}
	return (0);
}

int	check_map_border(char **map, int y_max, int x_max)
{
	int x;
	int y;
	
	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x != x_max - 2)
		{
			if (check_one_border(map, y, x, y_max, x_max) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_shape(char **map, int y_max)
{
	int y;
		
	y = 0;	
	while (y < y_max - 1)
	{
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
		{
			ft_printf("Error, invalid map shape🔶\n");
			return (1);
		}
		y++;
	}
	if (ft_strlen(map[y]) != ft_strlen(map[0]) - 1)
	{
		ft_printf("Error, invalid map shape🔶\n");
		return (1);
	}
	return (0);
}


