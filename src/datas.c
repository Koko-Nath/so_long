/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:57:24 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/20 18:37:41 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_data *data)
{
	ft_printf("OUI");
	data->sprites.bush.img = mlx_xpm_file_to_image(data->mlx, BUSH_PATH, 
		&data->sprites.bush.img_x, &data->sprites.bush.img_y);
	data->sprites.floor.img = mlx_xpm_file_to_image(data->mlx, FLOOR_PATH, 
		&data->sprites.floor.img_x, &data->sprites.floor.img_y);
	data->sprites.exit.img = mlx_xpm_file_to_image(data->mlx, EXIT_PATH, 
		&data->sprites.exit.img_x, &data->sprites.exit.img_y);
	data->sprites.milk.img = mlx_xpm_file_to_image(data->mlx, MILK_PATH, 
		&data->sprites.milk.img_x, &data->sprites.milk.img_y);
	data->sprites.player.img = mlx_xpm_file_to_image(data->mlx, PLAYER_PATH, 
		&data->sprites.player.img_x, &data->sprites.player.img_y);
	if (!data->sprites.bush.img  || !data->sprites.floor.img ||
		!data->sprites.milk.img || !data->sprites.player.img
		|| !data->sprites.exit.img)
	{
		ft_printf("%s\n", "Error.\n Problem initialising images");
		free_images(data);
		end_program(data);
	}
}

int	get_y_max(t_data *data)
{
	size_t	count_lines;
	int		fd;
	char	*line;

	count_lines = 0;
	fd = open ((const char *) data->map.path, O_RDONLY);
	line = NULL;
	while (!count_lines || line)
	{
		line = get_next_line(fd);
		free(line);
		count_lines++;
	}
	if (count_lines < 3)
		return (ft_printf("Error.\ninvalid map shape 🔶\n"), 1);
	data->y_height = count_lines;
	close(fd);
	return (0);
}

void	init_datas(t_data *data)
{
	data->map.matrix = NULL;
	if (check_map_path(data->map.path) == 1)
		end_program(data);
	if (get_y_max(data) == 1)
		end_program(data);
	data->map.matrix = init_map(data);
	data->x_width = ft_strlen(data->map.matrix[1]);
	//data->nbr_collec = 0;
	//data->move_count = 0;
	data->old_tile = '0';
	get_player_pos(data);
	if (full_checker(data) == 1)
		end_program(data);
}

char	**init_map(t_data *data)
{
	int		fd;
	size_t	i;
	//char	*line;
	char	**map;

	map = NULL;
	//line = NULL;
	i = 0;
	map = ft_calloc(sizeof(char *), data->y_height + 1);
	if (!map)
	{
		ft_printf("%s\n", "Error.\nError initializing map");
		free_map(map);
		exit (1);
	}
	fd = open ((const char *) data->map.path, O_RDONLY);
	while (i != data->y_height - 1)
	{
		map[i] = (get_next_line(fd));
		//free(map[i]);
		i++;
	}
	//free(map[i]);
	close(fd);
	return (map);
}

