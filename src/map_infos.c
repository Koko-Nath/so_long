/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:06:12 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/19 16:24:32 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y != data->y_height - 1)
	{
		x = 0;
		while (x != data->x_width - 1)
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

void	aff_tile(t_data *data, t_sprites *s, size_t x, size_t y)
{
	x = x * 64;
	y = y * 64;
	if (data->map.matrix[y / 64][x / 64] == '0')
		mlx_put_image_to_window(data->mlx, data->win, s->floor.img, x, y);
	if (data->map.matrix[y / 64][x / 64] == '1')
		mlx_put_image_to_window(data->mlx, data->win, s->bush.img, x, y);
	if (data->map.matrix[y / 64][x / 64] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, s->milk.img, x, y);
	if (data->map.matrix[y / 64][x / 64] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, s->exit.img, x, y);
	if (data->map.matrix[y / 64][x / 64] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, s->player.img, x, y);
}

void	aff_map(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y != data->y_height - 1)
	{
		x = 0;
		while (x != data->x_width - 1)
		{
			aff_tile(data, &data->sprites, x, y);
			x++;
		}
		y++;
	}
}

int	is_item_or_exit(t_data *data, char **map, size_t x, size_t y)
{
	if (map[y][x] == 'C')
		data->nbr_collec--;
	else if (map[y][x] == 'E')
	{
		if (data->nbr_collec == 0)
		{
			data->move_count++;
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
