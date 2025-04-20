/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:32:25 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/20 18:40:19 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

void	destroy_display(t_data *data)
{
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map.matrix);
}

void	free_images(t_data *data)
{
	if (data->sprites.bush.img)
	{
		// free(data->sprites.bush.img);
		mlx_destroy_image(data->mlx, data->sprites.bush.img);
		// data->sprites.bush.img = NULL;
	}
	if (data->sprites.floor.img)
	{
		// free(data->sprites.floor.img);
		mlx_destroy_image(data->mlx, data->sprites.floor.img);
		// data->sprites.floor.img = NULL;
	}
	if (data->sprites.exit.img)
	{
		// free(data->sprites.exit.img);
		mlx_destroy_image(data->mlx, data->sprites.exit.img);
		// data->sprites.exit.img = NULL;
	}
	if (data->sprites.milk.img)
	{
		// free(data->sprites.milk.img);
		mlx_destroy_image(data->mlx, data->sprites.milk.img);
		// data->sprites.milk.img = NULL;
	}
	if (data->sprites.player.img)
	{
		// free(data->sprites.player.img);
		mlx_destroy_image(data->mlx, data->sprites.player.img);
		// data->sprites.player.img = NULL;
	}
	//end_program(data);
	// mlx_destroy_window(data->mlx, data->win);
	// mlx_destroy_display(data->mlx);
	// free(data->mlx);
	// free_map(data->map.matrix);
}

// void	free_images(t_data *data)
// {
// 	if (data->sprites.bush.img)
// 		mlx_destroy_image(data, data->sprites.bush.img);
// 	if (data->sprites.floor.img)
// 		mlx_destroy_image(data, data->sprites.floor.img);
// 	if (data->sprites.player.img)
// 		mlx_destroy_image(data, data->sprites.player.img);
// 	if (data->sprites.milk.img)
// 		mlx_destroy_image(data, data->sprites.milk.img);
// 	if (data->sprites.exit.img)
// 		mlx_destroy_image(data, data->sprites.exit.img);
// 	mlx_destroy_window(data->mlx, data->win);
// 	mlx_destroy_display(data->mlx);
// 	free(data->mlx);
// 	free_map(data->map.matrix);
// }



int	end_program(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	free_images(data);
	//free(data->mlx);
	free_map(data->map.matrix);
	exit(0);
}