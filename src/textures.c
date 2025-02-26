/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:29:54 by ntordjma          #+#    #+#             */
/*   Updated: 2025/02/22 14:38:09 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx/mlx.h"
#include "so_long.h"

void	*load_textures(t_data data)
{
	void	*img_ptr;
	
	img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "bush.xpm", 10, 10);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, 2, 2);
	return	(img_ptr);
}