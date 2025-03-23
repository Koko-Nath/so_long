/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:57:24 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/23 21:50:59 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_data *data)
{
	int	x;
	int y;
	
	x = 0;
	y = 0;
	data->sprites.bush.img = mlx_xpm_file_to_image(data->mlx_ptr, bush_path, &x, &y);
	data->sprites.floor.img = mlx_xpm_file_to_image(data->mlx_ptr, floor_path, &x, &y);
	data->sprites.exit.img = mlx_xpm_file_to_image(data->mlx_ptr, exit_path, &x, &y);
	data->sprites.milk.img = mlx_xpm_file_to_image(data->mlx_ptr, milk_path, &x, &y);
	data->sprites.player.img = mlx_xpm_file_to_image(data->mlx_ptr, player_path, &x, &y);
}

void	init_datas(t_data *data)
{
	init_sprites(data);
	data->map.matrix = init_map(data);
	get_player_pos(data);
	data->nbr_collec = 0;
	data->move_count = 0;
	data->old_tile = '0';
	if (check_map_path(data->map.path) == 1)
		end_program(data);
	//data->map.matrix = init_map(data);
	if (data->y_height < 3)
	{
		ft_printf("Error, invalid map shape🔶\n");
		end_program(data);
	}
	data->x_width = ft_strlen(data->map.matrix[0]);
	if (full_checker(data) == 1)
		end_program(data);
}

char	**init_map(t_data *data)
{
	int fd;
	int i;
	int count_lines;
	char *line;
	char	**map;
	
	line = "";
	count_lines = 0;
	fd = open((const char*) data->map.path, O_RDONLY);
	while (get_next_line(fd))
		count_lines++;
	data->y_height = count_lines;
	map = malloc(sizeof(char*) * count_lines + 1);
	close(fd);
	fd = open((const char*) data->map.path, O_RDONLY);
	i = 0;
	while(i != count_lines)
	{
		line = (get_next_line(fd));
		map[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	end_program(t_data *data)
{
	free(data->map.matrix);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	exit(0);

	// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// mlx_destroy_display(data->mlx_ptr);
	// free(data->mlx_ptr);
	// exit(0);
	// return (0);
}