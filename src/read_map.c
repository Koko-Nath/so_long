/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:24:35 by ntordjma          #+#    #+#             */
/*   Updated: 2025/02/26 15:47:41 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_data data)
{
	int fd;
	int i;
	int count_lines;
	char *line;
	
	line = "";
	i = 0;
	count_lines = 0;
	fd = open((const char*) map_path, O_RDONLY);
	while (get_next_line(fd))
		count_lines++;
	data.map = malloc(sizeof(char*) * count_lines + 1);
	close(fd);
	fd = open((const char*) map_path, O_RDONLY);
	while(i != count_lines)
	{
		//line = get_next_line(fd);
		data.map[i++] = get_next_line(fd);
	}
	return (data.map);
}

void	aff_map(t_data data)
{
	int	x;
	int	y;
	
	y = 0;
	while (data.map[y])
	{
		x = 0;
		while(data.map[y][x])
		{
			if (data.map[y][x] == '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprites.floor.img, (x * 64), (y * 64));
			if (data.map[y][x] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprites.bush.img, (x * 64), (y * 64));		
			if (data.map[y][x] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprites.milk.img, (x * 64), (y * 64));
			if (data.map[y][x] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprites.exit.img, (x * 64), (y * 64));
			if (data.map[y][x] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprites.player.img, (x * 64), (y * 64));
			x++;
		}
		y++;
	}
}

// setup_images(&img_ptr);
// 	img_ptr.img = mlx_xpm_file_to_image(data.mlx_ptr, img_ptr.img_path, &img_ptr.img_x, &img_ptr.img_y);
// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr.img, 200, 200);