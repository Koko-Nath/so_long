/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:02:50 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/22 01:05:11 by ntordjma         ###   ########.fr       */
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
# include "./libft/libft.h"
# include "./libft/GNL/get_next_line.h"
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

typedef struct s_tile{
	void	*tile_ptr;
	int		x;
	int		y;
	char	type;
} t_tile;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		*map_path;
	int			map_width;
	int			map_height;
	int			move_count;
	int			nbr_collec;
	char		**tiles_map; // tableau de tableau de pointers sur tiles (tiles_map[y][x])
	t_sprites	sprites;
}	t_data;

// --------------------FUNCTIONS-------------------- 

//INIT
void	setup_datas(t_sprites *img, t_data *data);
void	*load_textures(t_data data);
char	**read_map(t_data data);

void	aff_map(t_data data);

//MOVES
int 	handle_keypress(int keycode, t_data *data);
void 	move_player(t_data *data, int dx, int dy);
void	get_player_pos(t_data *data);

//CHECKS
void	count_items(t_data *data);
int		check_items(t_data *data, int x, int y);
void	check_collectible(t_data *data, int x, int y);
void	check_map(t_data data);


//MISCELANNEOUS
void	end_program(t_data data);
int		on_destroy(t_data *data);

// TESTS PATHFINDING
int	pathfinding(t_data *data, int x, int y, char last_move);

#endif