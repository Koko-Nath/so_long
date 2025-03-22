/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:54:06 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/21 19:18:17 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	check_items(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'C')
		data->nbr_collec--;
	return (0);
}

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == 119) // W
		move_player(data, 0, -1);
    else if (keycode == 115) // S
		move_player(data, 0, 1);
    else if (keycode == 97) // A
		move_player(data, -1, 0);
    else if (keycode == 100) // D
		move_player(data, 1, 0);
    else if (keycode == 65307) // ESC
        on_destroy(data);
    return (0);
}

void move_player(t_data *data, int dx, int dy)
{
	get_player_pos(data);
    int new_x = data->sprites.player.img_x + dx;
    int new_y = data->sprites.player.img_y + dy;
    if (data->map[new_y][new_x] != '1' && data->map[new_y][new_x] != 'E')
    {
		check_items(data, new_x, new_y);
		data->move_count += 1;
		ft_printf("%s%d\n", "👣 move count =", data->move_count);
        data->map[data->sprites.player.img_y][data->sprites.player.img_x] = '0'; // Efface l'ancienne position
        data->sprites.player.img_x = new_x;
        data->sprites.player.img_y = new_y;
        data->map[new_y][new_x] = 'P'; // Place le joueur à la nouvelle position
        aff_map(*data); // Rafraîchit l'affichage de la carte
    }
	else if (data->map[new_y][new_x] == 'E')
	{
		if (data->nbr_collec == 0)
		{
			ft_printf("You win!\n");
			on_destroy(data);
		}
		else
			ft_printf("You need to collect all the items first! 🐮🥛\n");
	}
}
