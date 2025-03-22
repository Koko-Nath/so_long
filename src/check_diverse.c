/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:54:39 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/22 18:31:02 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_path(t_data *data)
{
	int fd;
	
	//checker le format .ber et non .txt
	fd = open((const char*) data->map.path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, invalid map path🗺️\n");
		end_program(data);
	}
	close(fd);
}

void	check_char(t_data *data, char **map)
{
	int x;
	int y;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (x < data->x_width - 1)
		{
			if (map[y][x] != '0' && 
				map[y][x] != '1' &&
				 map[y][x] != 'C' &&
				  map[y][x] != 'E' &&
				   map[y][x] != 'P')
			{
				ft_printf("Error, invalid character in map🌧️\n");
				end_program(data);
			}
			x++;
		}
		y++;
	}
}

void	full_checker(t_data *data)
{
	int count_lines;
	
	count_lines = 0;
	while (data->map.matrix[count_lines])
		count_lines++;
	if (count_lines < 3)
	{
		ft_printf("Error, invalid map shape🔶\n");
		end_program(data);
	}
	data->y_height = count_lines;
	data->x_width = ft_strlen(data->map.matrix[0]);
	check_char(data, data->map.matrix);
	check_map_shape(data, data->map.matrix, data->y_height);
	//check_player_nbr(*data, data.map_copy.matrix);
	//check_exit_nbr(*data, data.map_copy.matrix);
	//check_items_nbr(*data, data.map_copy.matrix);
	//check_map_border(*data, data.map_copy.matrix);
}