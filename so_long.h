/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:02:50 by ntordjma          #+#    #+#             */
/*   Updated: 2025/02/26 01:53:54 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define bush_path "assets/bush.xpm"
# define milk_path "assets/milk.xpm"
# define floor_path "assets/floor.xpm"
# define player_path "assets/player.xpm"
# define exit_path "assets/exit.xpm"

# define map_path "./map.txt"

# include "includes/mlx/mlx.h"
# include "includes/mlx/mlx_int.h"
# include "includes/libft/libft.h"
# include "includes/libft/GNL/get_next_line.h"
# include <stdlib.h>

typedef struct s_map {
	int	length;
	int width;
	int *pattern;
}	t_map;

typedef struct s_data {
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		**map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;

typedef struct s_images{
	void	*img;
	char	*img_path;
	int		img_x;
	int		img_y;
} t_images;

typedef struct	s_test {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_test;

// FUNCTIONS 

void	*load_textures(t_data data);
char	**read_map(char **map);
void	aff_map(char **map, t_data data);
void	setup_images(t_images img);


#endif