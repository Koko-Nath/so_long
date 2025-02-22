/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:01:43 by ntordjma          #+#    #+#             */
/*   Updated: 2025/02/22 14:41:02 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "mlx/mlx_int.h"
#include <stdlib.h>
#include "so_long.h"

// void	test(void *mlx_ptr)
// {
// 	t_data img;

// 	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_pet_pixel, &img.line_length, &img.endian);
// }

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int main(void)
{
	t_data	data;
	void	*img_ptr;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "feur =)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "bush.xpm", 10, 10);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, 2, 2);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}