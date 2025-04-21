
NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes/ -I$(LIBFT_DIR)
MLXFLAGS = -lX11 -lXext -lm -lz
FILES = main.c \
		check_diverse.c \
		check_nbr.c \
		check_map.c \
		datas.c \
		map_infos.c \
		pathfinding.c \
		moves.c \
		free_functions.c \
		init_map.c \

INC = includes/so_long.h
SRC = 	src/$(FILES)
OBJDIR = obj_dir/
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
MLX = mlx/
OBJ = $(FILES:%.c=$(OBJDIR)%.o)
# INC = -I ./libft -I ./libft/GNL -I ./mlx -I ./includes
# LIB = ./mlx/libmlx_Linux.a $(MLXFLAGS)
# MINILIBX_PATH = ./mlx

all: lib $(NAME)

lib :
		$(MAKE) -C $(MLX)
		$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)libmlx.a $(MLXFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: src/%.c $(INC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make -s $@ -C ./libft
	@rm -rf $(OBJDIR)

fclean: clean
	@make -s $@ -C ./libft
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all lib clean fclean re