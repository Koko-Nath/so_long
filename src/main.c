/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:01:43 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/19 16:34:29 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error. \n invalid number of arguments📄\n");
		return (1);
	}
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Error. \n mlx_init failed🛡️\n"), 1);
	data.win = mlx_new_window(data.mlx, 1920, 1920, "les 42 coups de midi");
	if (!data.win)
	{
		free(data.mlx);
		ft_printf("Error. \n mlx_window init failed🛡️");
		return (1);
	}
	data.map.path = argv[1];
	data.map.matrix = NULL;
	init_datas(&data);
	aff_map(&data);
	mlx_key_hook(data.win, keypress, &data);
	mlx_loop(data.mlx);
	end_program(&data);
	return (0);
}

// MAIN QUI TEST QUE LE PATHFINDING

// int	main(int argc, char **argv) 
// {
// 	t_data	data;
// 	int		checker;

// 	if (argc != 2)
// 	{
// 		ft_printf("Error, invalid number of arguments📄\n");
// 		return (1);
// 	}
// 	data.mlx = mlx_init();
// 	if (!data.mlx)
// 		return (ft_printf("Error, mlx_init failed🛡️\n"), 1);
// 	data.map_path = argv[1];
// 	data.map = NULL;
// 	data.win = mlx_new_window(data.mlx, 1920, 1920, "les 42 coups de midi");
// 	if (!data.win)
// 		return (free(data.mlx), ft_printf("Error, mlx_window init failed🛡️"), 1);
// 	data.map = read_map(data);
// 	setup_datas(&data.sprites, &data);
// 	check_map(data);
// 	count_items(&data);
// 	data.map_width = ft_strlen(data.map[0]);
// 	aff_map(data);
// 	get_player_pos(&data);
// 	checker = pathfinding(&data, data.sprites.player.img_x, data.sprites.player.img_y, 'Z');
// 	if (checker == 1)
// 		ft_printf("Error, no path to exit🚪\n");
// 	else if (checker == 0)
// 		ft_printf("Path to exit found 🚪 gg !!! =)\n");
// }
