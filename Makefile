.PHONY: all re clean fclean

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
FILES = main.c \
		read_map.c \
		moves.c \
		check_map.c \
		pathfinding.c

SRC = 	src/$(FILES)
MLX = ./includes/mlx/Makefile.gen
LFT = ./libft/libft.a
MLXFLAGS = -lX11 -lXext -lm -lz
OBJ = $(FILES:%.c=$(OBJDIR)%.o)
OBJDIR = obj_dir/
INC = -I ./libft -I ./libft/GNL -I ./includes/mlx -I .
LIB = ./includes/mlx/libmlx_Linux.a $(MLXFLAGS)

all: $(MLX) $(LFT) $(NAME)

$(NAME): $(OBJ) $(LFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^ ./libft/libft.a $(LIB)

$(MLX):
	@echo "[..] | la Minilibx de ses morts compile tkt.."
	@make -s -C includes/mlx
	@echo "[ OK ] | C'est tout bon frero "

$(LFT):
	@echo "[ .. ] | la libft mtn.."
	@make -C ./libft
	@echo "[ OK ] | C'est encore tout bon frero "

$(OBJDIR)%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@make -s $@ -C ./libft
	@rm -rf $(OBJDIR)
	@echo "objects removed. c'est ciao"

fclean: clean
	@make -s $@ -C ./libft
	@rm -rf $(NAME)
	@echo "binary file removed. c'est ciao"

re:	fclean all