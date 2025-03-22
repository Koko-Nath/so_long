/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:02:50 by ntordjma          #+#    #+#             */
/*   Updated: 2025/03/22 18:39:18 by ntordjma         ###   ########.fr       */
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

typedef struct s_map{
	char	**matrix;
	int 	x_pos;
	int 	y_pos;
	char	*path;
} t_map;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	int			move_count;
	int			nbr_collec;
	int			x_width;
	int			y_height;
	t_map		map;
	//t_map		map_copy;
	t_sprites	sprites;
}	t_data;

// --------------------FUNCTIONS-------------------- 

//CHECK DIVERSE

void	check_map_path(t_data *data);
void	check_char(t_data *data, char **map);
void	full_checker(t_data *data);

//CHECK MAP

void	check_map_border(t_data *data, char **map, int y_max, int x_max);
void	check_map_shape(t_data *data, char **map, int y_max);
void	check_one_border(t_data *data, char **map, int y, int x);

//CHECK NBR

void	check_exit_nbr(t_data *data, char **map);
void	check_items_nbr(t_data *data, char **map);
void	check_player_nbr(t_data *data, char **map);

// DATAS

void	init_datas(t_data *data);
void	init_map(t_data *data);
void	init_sprites(t_data data);
void	end_program(t_data *data);

// MAP INFOS

void	aff_map(t_map map, t_data *data);
void	get_player_pos(t_data *data);
int		is_item_or_exit(t_data *data, int x, int y);

// MOVES

void	p_move(t_data *data, int dx, int dy);
int		keypress(int keycode, t_data *data);
int		on_destroy(t_data *data);

//

#endif