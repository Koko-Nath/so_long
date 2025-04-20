.PHONY: all re clean fclean

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
FILES = main.c \
		check_diverse.c \
		check_nbr.c \
		check_map.c \
		datas.c \
		map_infos.c \
		pathfinding.c \
		moves.c \
		free_functions.c 

SRC = 	src/$(FILES)
MLX = ./mlx/Makefile.gen
LFT = ./libft/libft.a
MLXFLAGS = -lX11 -lXext -lm -lz
OBJ = $(FILES:%.c=$(OBJDIR)%.o)
OBJDIR = obj_dir/
INC = -I ./libft -I ./libft/GNL -I ./mlx -I ./includes
LIB = ./mlx/libmlx_Linux.a $(MLXFLAGS)

all: $(MLX) $(LFT) $(NAME)

$(NAME): $(OBJ) $(LFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^ ./libft/libft.a $(LIB)

$(MLX):
	@make -s -C mlx

$(LFT):
	@make -C ./libft

$(OBJDIR)%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@make -s $@ -C ./libft
	@rm -rf $(OBJDIR)

fclean: clean
	@make -s $@ -C ./libft
	@rm -rf $(NAME)

re:	fclean all