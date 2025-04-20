/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:01:43 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/20 19:02:32 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error.\ninvalid number of arguments📄\n");
		return (1);
	}
	ft_bzero(&data, sizeof(t_data));
	data.map.path = argv[1];
	init_datas(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Error.\nmlx_init failed🛡️\n"), 1);
	data.win = mlx_new_window(data.mlx, (((int)data.x_width - 1) * 64),
			(((int)data.y_height - 1) * 64), "so_long");
	if (!data.win)
	{
		ft_printf("Error.\nmlx_window init failed🛡️");
		end_program(&data);
	}
	init_sprites(&data);
	aff_map(&data);
	mlx_key_hook(data.win, keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}
