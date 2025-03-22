/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:02:57 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/22 16:13:10 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_one_border(t_data data, int y, int x, int count_lines, int line_size)
{
	if (y == 0 || y == count_lines - 1)
	{
		if (data.map[y][x] != '1')
		{
			ft_printf("Error, invalid map border🌳\n");
			end_program(data);
		}
	}
	if (x == 0 || x == line_size)
	{
		if (data.map[y][0] != '1' || data.map[y][line_size] != '1')
		{
			ft_printf("Error, invalid map border🌳\n");
			end_program(data);
		}
	}
}

void	check_map_border(t_data data, int count_lines)
{
	int x;
	int y;
	int	line_size;
	
	y = 0;
	line_size = (ft_strlen(data.map[y]) - 2);
	while (y < count_lines)
	{
		x = 0;
		while (x != line_size)
		{
			check_one_border(data, y, x, count_lines, line_size);
			x++;
		}
		y++;
	}
}

void	check_player_nbr(t_data data)
{
	int	x;
	int	y;
	int	player_count;
	
	y = 0;
	player_count = 0;
	while (data.map[y])
	{
		x = 0;
		while (data.map[y][x])
		{
			if (data.map[y][x] == 'P')
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

void	check_exit_nbr(t_data data)
{
	int	x;
	int	y;
	int exit_count;

	y = 0;
	exit_count = 0;
	while (data.map[y])
	{
		x = 0;
		while (data.map[y][x])
		{
			if (data.map[y][x] == 'E')
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

void	check_characters(t_data data)
{
	int x;
	int y;
	
	y = 0;
	while (data.map.map[y])
	{
		x = 0;
		while (data.map.map[y][x])
		{
			if (data.map.map[y][x] != '0' && 
				data.map.map[y][x] != '1' &&
				 data.map.map[y][x] != 'C' &&
				  data.map.map[y][x] != 'E' &&
				   data.map.map[y][x] != 'P' &&
				    data.map.map[y][x] != '\n')
			{
				ft_printf("Error, invalid character in map🌧️\n");
				end_program(data);
			}
			x++;
		}
		y++;
	}
}

void	check_map_shape(t_data data, int count_lines)
{
	int y;
		
	y = 0;	
	while (y < count_lines - 1)
	{
		if (ft_strlen(data.map.map[y]) != ft_strlen(data.map.map[0]))
		{
			ft_printf("Error, invalid map shape🔶\n");
			end_program(data);
		}
		y++;
	}
	if (ft_strlen(data.map.map[y]) != ft_strlen(data.map.map[0]) - 1)
	{
		ft_printf("Error, invalid map shape🔶\n");
		end_program(data);
	}
}

void	check_map(t_data data)
{
	int count_lines;
	
	count_lines = 0;
	while (data.map.map[count_lines])
		count_lines++;
	if (count_lines < 3)
	{
		ft_printf("Error, invalid map shape🔶\n");
		end_program(data);
	}
	check_map_shape(data, count_lines);
	check_characters(data);
	check_player_nbr(data);
	check_exit_nbr(data);
	check_map_border(data, count_lines);
}
