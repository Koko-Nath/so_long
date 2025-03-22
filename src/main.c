/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:01:43 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/22 01:05:18 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_datas(t_sprites *img, t_data *data)
{
	int	x;
	int y;
	
	x = 0;
	y = 0;
	data->sprites.player.img_x = 0;
	data->sprites.player.img_y = 0;
	data->nbr_collec = 0;
	data->move_count = 0;
	img->bush.img = mlx_xpm_file_to_image(data->mlx_ptr, bush_path, &x, &y);
	img->floor.img = mlx_xpm_file_to_image(data->mlx_ptr, floor_path, &x, &y);
	img->exit.img = mlx_xpm_file_to_image(data->mlx_ptr, exit_path, &x, &y);
	img->milk.img = mlx_xpm_file_to_image(data->mlx_ptr, milk_path, &x, &y);
	img->player.img = mlx_xpm_file_to_image(data->mlx_ptr, player_path, &x, &y);
}

void	end_program(t_data data)
{
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	exit(0);
}

//int main(int argc, char **argv)
// {
// 	t_data	data;
	
// 	if (argc != 2)
// 	{
// 		ft_printf("Error, invalid number of arguments📄\n");
// 		return (1);
// 	}
// 	data.mlx_ptr = mlx_init();
// 	if (!data.mlx_ptr)
// 		return (ft_printf("Error, mlx_init failed🛡️\n"), 1);
// 	data.map_path = argv[1];
// 	data.map = NULL;
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1920, "les 42 coups de midi");
// 	if (!data.win_ptr)
// 		return (free(data.mlx_ptr), ft_printf("Error, mlx_window init failed🛡️"), 1);
// 	setup_datas(&data.sprites, &data);
// 	data.map = read_map(data);
// 	check_map(data);
// 	count_items(&data);
// 	aff_map(data);
// 	mlx_key_hook(data.win_ptr, handle_keypress, &data);
// 	mlx_loop(data.mlx_ptr);
// 	end_program(data);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_data	data;
	int		checker;

	if (argc != 2)
	{
		ft_printf("Error, invalid number of arguments📄\n");
		return (1);
	}
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (ft_printf("Error, mlx_init failed🛡️\n"), 1);
	data.map_path = argv[1];
	data.map = NULL;
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1920, "les 42 coups de midi");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), ft_printf("Error, mlx_window init failed🛡️"), 1);
	data.map = read_map(data);
	setup_datas(&data.sprites, &data);
	check_map(data);
	count_items(&data);
	data.map_width = ft_strlen(data.map[0]);
	aff_map(data);
	get_player_pos(&data);
	checker = pathfinding(&data, data.sprites.player.img_x, data.sprites.player.img_y, 'Z');
	if (checker == 1)
		ft_printf("Error, no path to exit🚪\n");
	else if (checker == 0)
		ft_printf("Path to exit found 🚪 gg !!! =)\n");
}
