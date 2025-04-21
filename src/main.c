/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:01:43 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/21 15:47:30 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_my_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data->mlx);
		ft_printf("Error\nmlx_init failed 🛡️\n");
		return (1);
	}
	data->win = mlx_new_window(data->mlx, (((int)data->x_width - 1) * 64),
			(((int)data->y_height - 1) * 64), "so_long");
	if (!data->win)
	{
		free(data->win);
		ft_printf("Error\nmlx_window init failed 🛡️");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Error\ninvalid number of arguments 📄\n"));
	ft_bzero(&data, sizeof(t_data));
	data.map.path = argv[1];
	init_datas(&data);
	if (init_my_mlx(&data) == 1)
		end_program(&data);
	init_sprites(&data);
	aff_map(&data);
	mlx_key_hook(data.win, keypress, &data);
	mlx_hook(data.win, 17, 0, end_program, &data);
	mlx_loop(data.mlx);
	return (0);
}
