# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 18:07:29 by ntordjma          #+#    #+#              #
#    Updated: 2025/02/26 16:11:12 by ntordjma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_print_numbers.c \
		ft_printf/ft_print_utils.c
OBJ = $(SRC:.c=.o)
INC = libft.h GNL/get_next_line.h ft_printf/ft_printf.h

all: $(NAME) 
	@echo "[...] libft comp..."
	
$(NAME): $(OBJ)
	ar rcs $@ $^

%.o : %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
