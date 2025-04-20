/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:02:50 by ntordjma          #+#    #+#             */
/*   Updated: 2025/04/20 21:02:05 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// --------------------DEFINES--------------------

# define BUSH_PATH "../assets/bush.xpm"
# define MILK_PATH "../assets/milk.xpm"
# define FLOOR_PATH "../assets/floor.xpm"
# define PLAYER_PATH "../assets/player.xpm"
# define EXIT_PATH "../assets/exit.xpm"

// --------------------INCLUDES--------------------

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"
# include "../libft/GNL/get_next_line.h"
# include <stdlib.h>

// --------------------STRUCTURES--------------------

typedef struct s_images
{
	void	*img;
	char	*img_path;
	int		img_x;
	int		img_y;
}	t_images;

typedef struct s_sprites
{
	t_images	bush;
	t_images	floor;
	t_images	exit;
	t_images	milk;
	t_images	player;
}	t_sprites;

typedef struct s_tile
{
	void	*tile_ptr;
	int		x;
	int		y;
	char	type;
}	t_tile;

typedef struct s_map
{
	char	**matrix;
	size_t	x_pos;
	size_t	y_pos;
	size_t	x_max;
	size_t	y_max;
	int		c_left;
	char	*path;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			move_count;
	int			nbr_collec;
	size_t		x_width;
	size_t		y_height;
	size_t		player_x;
	size_t		player_y;
	char		old_tile;
	t_map		map;
	t_sprites	sprites;
}	t_data;

// --------------------FUNCTIONS-------------------- 

//CHECK DIVERSE

int		check_map_path(char *map_path); // OK
int		check_char(char **map, size_t y_max, size_t x_max); // OK
int		full_checker(t_data *data); // OK

//CHECK MAP

int		check_map_border(t_data *data, size_t y_max, size_t x_max); // OK
int		check_map_shape(char **map, size_t y_max); // OK
int		check_one_border(char **map, size_t y, size_t x, t_data *data);	// OK
int		check_pathfinding(t_data *data);
int		check_map_size(size_t y_max, size_t x_max);

//CHECK NBR

int		check_exit_nbr(char **map, size_t y_max, size_t x_max); // OK
int		check_items_nbr(t_data *data, char **map); // OK
int		check_player_nbr(char **map, size_t y_max, size_t x_max); // OK

// DATAS

void	init_datas(t_data *data);
char	**init_map(t_data *data);
//char	**init_map(t_data *data, char **map);
//void	init_map(t_data *data, char **map);
void	init_sprites(t_data *data);
int		end_program(t_data *data);
void	free_map(char **map);
void	destroy_display(t_data *data);
void	free_images(t_data *data);
void	close_window(t_data *data);

// MAP INFOS

void	aff_map(t_data *data);
void	get_player_pos(t_data *data);
int		is_item_or_exit(t_data *data, char **map, size_t x, size_t y);

// MOVES

void	p_move(t_data *data, int dx, int dy);
int		keypress(int keycode, t_data *data);
//int		on_destroy(t_data *data);

#endif
