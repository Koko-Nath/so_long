/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:06:12 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/23 21:47:44 by ntordjma         ###   ########.fr       */
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
			}
			x++;
		}
		y++;
	}
}

void	aff_tile(t_data *data, char **map, t_sprites *s, int x, int y)
{
	if (map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, s->floor.img, (x * 64), (y * 64));
	if (map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, s->bush.img, (x * 64), (y * 64));
	if (map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, s->milk.img, (x * 64), (y * 64));
	if (map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, s->exit.img, (x * 64), (y * 64));
	if (map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, s->player.img, (x * 64), (y * 64));
}

void	aff_map(t_data *data, char **map)
{
	int	x;
	int	y;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			aff_tile(data, map, &data->sprites, x, y);
			x++;
		}
		y++;
	}
}


int	is_item_or_exit(t_data *data, char **map, int x, int y)
{
	if (map[y][x] == 'C')
		data->nbr_collec--;
	else if (map[x][y] == 'E')
	{
		if (data->nbr_collec == 0)
		{
			ft_printf("You win!\n");
			end_program(data);
		}
		else
		{
			ft_printf("You need to collect all the items first! 🐮🥛\n");
			return (1);
		}
	}
	return (0);
}