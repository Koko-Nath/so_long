/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:02:57 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/21 15:21:29 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_one_border(char **map, size_t y, size_t x, t_data *data)
{
	if (y == 0 || y == data->y_height - 2)
	{
		if (map[y][x] != '1')
		{
			ft_printf("Error\ninvalid map border 🌳\n");
			return (1);
		}
	}
	if (x == 0 || x == data->x_width - 2)
	{
		if (map[y][x] != '1')
		{
			ft_printf("Error\ninvalid map border 🌳\n");
			return (1);
		}
	}
	return (0);
}

int	check_map_border(t_data *data, size_t y_max, size_t x_max)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < y_max - 1)
	{
		x = 0;
		while (x != x_max - 1)
		{
			if (check_one_border(data->map.matrix, y, x, data) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_shape(char **map, size_t y_max)
{
	size_t	y;

	y = 0;
	while (y != y_max - 2)
	{
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
		{
			ft_printf("Error\ninvalid map shape🔶\n");
			return (1);
		}
		y++;
	}
	if (ft_strlen(map[y]) != ft_strlen(map[0]) - 1)
	{
		ft_printf("Error\ninvalid map shape 🔶\n");
		return (1);
	}
	return (0);
}

int	check_map_size(size_t y_max, size_t x_max)
{
	if (y_max > 33 || x_max > 61)
	{
		ft_printf("Error\nmap too big 🏜️\n");
		return (1);
	}
	return (0);
}
