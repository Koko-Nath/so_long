/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:01:43 by ntordjma          #+#    #+#             */
/*   Updated: 2025/02/26 15:50:12 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_again(t_test *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	test(void *mlx_ptr, void *win_ptr)
// {
// 	t_test img;
// 	img.img = mlx_new_image(mlx_ptr, 200, 100);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	test_again(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
// }



void	setup_images(t_sprites *img, t_data *data)
{
	int	x;
	int y;

	x = 0;
	y = 0;
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
	free(data.mlx_ptr);
	free(data.win_ptr);
	free(data.map);
}

int main(void)
{
	t_data	data;
	
	data.map = NULL;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "feur =)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	setup_images(&data.sprites, &data);	
	data.map = read_map(data);
	aff_map(data);
	//mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	//mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	end_program(data);
	return (0);
}