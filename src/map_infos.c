/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:06:12 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/22 18:38:02 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_data *data)
{
	int x;
	int y;
	
	y = 0;
	while (data->map.matrix[y])
	{
		x = 0;
		while (data->map.matrix[y][x])
		{
			if (data->map.matrix[y][x] == 'P')
			{
				data->sprites.player.img_x = x;
				data->sprites.player.img_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	aff_map(t_map map, t_data data)
{
	int	x;
	int	y;
	
	y = 0;
	while (map.matrix[y])
	{
		x = 0;
		while(map.matrix[y][x])
		{
			if (map.matrix[y][x] == '0')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprites.floor.img, (x * 64), (y * 64));
			if (map.matrix[y][x] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprites.bush.img, (x * 64), (y * 64));		
			if (map.matrix[y][x] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprites.milk.img, (x * 64), (y * 64));
			if (map.matrix[y][x] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprites.exit.img, (x * 64), (y * 64));
			if (map.matrix[y][x] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.sprites.player.img, (x * 64), (y * 64));
			x++;
		}
		y++;
	}
}

int	is_item_or_exit(t_data *data, int x, int y)
{
	if (data->map.matrix[y][x] == 'C')
		data->nbr_collec--;
	return (0);
}