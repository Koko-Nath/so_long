/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:01:16 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/22 18:37:06 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player_nbr(t_data *data, char **map)
{
	int	x;
	int	y;
	int	player_count;
	
	y = 0;
	player_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
	{
		ft_printf("Error, invalid number of player🧍\n");
		end_program(data);
	}
}

void	check_exit_nbr(t_data *data, char **map)
{
	int	x;
	int	y;
	int exit_count;

	y = 0;
	exit_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				exit_count++;
			x++;
		}
		y++;
	}
	if (exit_count != 1)
	{
		ft_printf("Error, invalid number of exit⛩️\n");
		end_program(data);
	}
}

void	check_items_nbr(t_data *data, char **map)
{
	int	x;
	int	y;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				data->nbr_collec++;
				//pathfinding
			}
			x++;
		}
		y++;
	}
	if (data->nbr_collec < 1)
	{
		(ft_printf("Error\nNo collectibles in map\n"));
		end_program(data);
	}
}

