/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:54:06 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/23 21:41:06 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keypress(int keycode, t_data *data)
{
    if (keycode == 119) // W
		p_move(data, 0, -1);
    else if (keycode == 115) // S
		p_move(data, 0, 1);
    else if (keycode == 97) // A
		p_move(data, -1, 0);
    else if (keycode == 100) // D
		p_move(data, 1, 0);
    else if (keycode == 65307) // ESC
        end_program(data);
    return (0);
}

void p_move(t_data *data, int dx, int dy)
{
    int new_x;
    int new_y;
	int	old_x;
	int	old_y;
	
	old_x = data->sprites.player.img_x;
	old_y = data->sprites.player.img_y;
	new_x = old_x + dx;
	new_y = old_y + dy;
    if (data->map.matrix[new_y][new_x] != '1')
    {
		data->map.matrix[old_y][old_x] = data->old_tile;
		if (is_item_or_exit(data, data->map.matrix, new_x, new_y) == 1)
			data->old_tile = 'E';
		else
			data->old_tile = '0';
		data->move_count += 1;
		ft_printf("%s%d\n", "👣 move count =", data->move_count);
        data->sprites.player.img_x = new_x;
        data->sprites.player.img_y = new_y;
        data->map.matrix[new_y][new_x] = 'P';
        aff_map(data, data->map.matrix);
    }
}
