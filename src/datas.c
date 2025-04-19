/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:57:24 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/19 16:37:31 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_data *data, t_sprites *s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	s->bush.img = mlx_xpm_file_to_image(data->mlx, BUSH_PATH, &x, &y);
	s->floor.img = mlx_xpm_file_to_image(data->mlx, FLOOR_PATH, &x, &y);
	s->exit.img = mlx_xpm_file_to_image(data->mlx, EXIT_PATH, &x, &y);
	s->milk.img = mlx_xpm_file_to_image(data->mlx, MILK_PATH, &x, &y);
	s->player.img = mlx_xpm_file_to_image(data->mlx, PLAYER_PATH, &x, &y);
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
		return (ft_printf("Error. \n invalid map shape 🔶\n"), 1);
	data->y_height = count_lines;
	close(fd);
	return (0);
}

void	init_datas(t_data *data)
{
	if (check_map_path(data->map.path) == 1)
		end_program(data);
	if (get_y_max(data) == 1)
		end_program(data);
	init_sprites(data, &data->sprites);
	data->map.matrix = init_map(data);
	data->x_width = ft_strlen(data->map.matrix[1]);
	get_player_pos(data);
	data->nbr_collec = 0;
	data->move_count = 0;
	data->old_tile = '0';
	if (full_checker(data) == 1)
		end_program(data);
}

char	**init_map(t_data *data)
{
	int		fd;
	size_t	i;
	char	*line;
	char	**map;

	line = NULL;
	i = 0;
	map = ft_calloc(sizeof(char *), data->y_height + 1);
	fd = open ((const char *) data->map.path, O_RDONLY);
	while (i != data->y_height - 1)
	{
		map[i] = (get_next_line(fd));
		i++;
	}
	close(fd);
	return (map);
}

int	end_program(t_data *data)
{
	free(data->map.matrix);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(0);
}
