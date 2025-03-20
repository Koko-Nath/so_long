/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:02:50 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/20 17:46:44 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// --------------------DEFINES--------------------

# define bush_path "assets/bush.xpm"
# define milk_path "assets/milk.xpm"
# define floor_path "assets/floor.xpm"
# define player_path "assets/player.xpm"
# define exit_path "assets/exit.xpm"

// --------------------INCLUDES--------------------

# include "includes/mlx/mlx.h"
# include "includes/mlx/mlx_int.h"
# include "includes/libft/libft.h"
# include "includes/libft/GNL/get_next_line.h"
# include <stdlib.h>

// --------------------STRUCTURES--------------------

typedef struct s_images{
	void	*img;
	char	*img_path;
	int		img_x;
	int		img_y;
} t_images;

typedef struct s_sprites{
	t_images bush;
	t_images floor;
	t_images exit;
	t_images milk;
	t_images player;
} t_sprites;

typedef struct s_data {
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	char		**map;
	char		*map_path;
	int			nbr_collec; 
	t_sprites	sprites;
}	t_data;

// --------------------FUNCTIONS-------------------- 

void	*load_textures(t_data data);
char	**read_map(t_data data);
void	aff_map(t_data data);
void	setup_images(t_sprites *img, t_data *data);
//int		*on_keypress(int keysym, t_data *data);
int 	handle_keypress(int keycode, t_data *data);
void 	move_player(t_data *data, int dx, int dy);
void	get_player_pos(t_data *data);
void	end_program(t_data data);
void	count_items(t_data *data);
int		on_destroy(t_data *data);
int		check_items(t_data *data, int x, int y);
void	check_collectible(t_data *data, int x, int y);
void	check_map(t_data data);

#endif