/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:01:16 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/20 20:50:06 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player_nbr(char **map, size_t y_max, size_t x_max)
{
	size_t	x;
	size_t	y;
	size_t	player_count;

	y = 0;
	player_count = 0;
	while (y != y_max - 1)
	{
		x = 0;
		while (x != x_max - 1)
		{
			if (map[y][x] == 'P')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
	{
		ft_printf("Error.\ninvalid number of player 🧍\n");
		return (1);
	}
	return (0);
}

int	check_exit_nbr(char **map, size_t y_max, size_t x_max)
{
	size_t	x;
	size_t	y;
	int		exit_count;

	y = 0;
	exit_count = 0;
	while (y != y_max - 1)
	{
		x = 0;
		while (x != x_max - 1)
		{
			if (map[y][x] == 'E')
				exit_count++;
			x++;
		}
		y++;
	}
	if (exit_count != 1)
	{
		ft_printf("Error.\ninvalid number of exit ⛩️\n");
		return (1);
	}
	return (0);
}

int	check_items_nbr(t_data *data, char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y != (data->y_height - 1))
	{
		x = 0;
		while (x != (data->x_width - 1))
		{
			if (map[y][x] == 'C')
				data->nbr_collec++;
			x++;
		}
		y++;
	}
	if (data->nbr_collec < 1)
		return (ft_printf("Error.\n no collectibles in map 🥛\n"), 1);
	return (0);
}
