.PHONY: all re clean fclean

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = create_window.c
MLX = mlx/Makefile.gen
MLXFLAGS = -lbsd -lX11 -lm -lXext -lmlx
# -Lmlx -lmlx -framework OpenGL -framework AppKit
OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))
INC = -I ./inc -I ./libft -I ./mlx
LIB =  -L ./mlx $(MLXFLAGS) #-lmlx -lmlx -lXext -lX11 -lm -lbsd
# -L ./libft -libft

all: $(MLX) $(LFT) obj $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MXFLAGS) -o $@ $^ $(LIB)

$(MLX):
	@echo "[..] | la Minilibx de ses morts compile tkt.."
	@make -s -C minilibx
	@echo "[ OK ] | C'est tout bon frero "

$(LFT):
	@echo "[ .. ] | la libft mtn.."
	@make -s -C libft
	@echo "[ OK ] | C'est encore tout bon frero "

obj: 
	@mkdir -p obj

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@make -s $@ -C libft
	@rm -rf $(OBJ) obj
	@echo "objects removed. c'est ciao"

fclean: clean
	@make -s $@ -C libft
	@rm -rf $(NAME)
	@echo "binary file removed. c'est ciao"

re:	fclean all