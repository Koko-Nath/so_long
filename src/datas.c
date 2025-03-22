/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:57:24 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/22 18:40:24 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_data data)
{
	int	x;
	int y;
	
	x = 0;
	y = 0;
	data.sprites.bush.img = mlx_xpm_file_to_image(data.mlx_ptr, bush_path, &x, &y);
	data.sprites.floor.img = mlx_xpm_file_to_image(data.mlx_ptr, floor_path, &x, &y);
	data.sprites.exit.img = mlx_xpm_file_to_image(data.mlx_ptr, exit_path, &x, &y);
	data.sprites.milk.img = mlx_xpm_file_to_image(data.mlx_ptr, milk_path, &x, &y);
	data.sprites.player.img = mlx_xpm_file_to_image(data.mlx_ptr, player_path, &x, &y);
}

void	init_datas(t_data *data)
{
	// data->sprites.player.pos_x = 0;   useless je crois ??
	// data->sprites.player.pos_y = 0;	 useless je crois ??
	data->nbr_collec = 0;
	data->move_count = 0;
	check_map_path(&data);
	init_map(&data);
	full_checker(&data);
	//get_player_pos(data);
	//count_items(data);
	//pathfinding(data, data->sprites.player.img_x, data->sprites.player.img_y, 'Z');
}

void	init_map(t_data *data)
{
	int fd;
	int i;
	int count_lines;
	char *line;
	
	line = "";
	count_lines = 0;
	fd = open((const char*) data->map.path, O_RDONLY);
	while (get_next_line(fd))
		count_lines++;
	data->y_height = count_lines;
	data->map.matrix = malloc(sizeof(char*) * count_lines + 1);
	close(fd);
	fd = open((const char*) data->map.path, O_RDONLY);
	i = 0;
	while(i != count_lines)
	{
		line = (get_next_line(fd));
		data->map.matrix[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
		data->map.matrix[i] = line;
		i++;
	}
	data->map.matrix[i] = NULL;
	close(fd);
}

void	end_program(t_data *data)
{
	free(data->map.matrix);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	exit(0);
}