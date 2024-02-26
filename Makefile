# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 15:51:14 by kabasolo          #+#    #+#              #
#    Updated: 2024/02/26 13:29:16 by kabasolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	source/main.c \
		source/ft_get_data.c  \
		source/ft_draw_map.c \
		source/ft_key_hook.c \
		source/errors.c \
		source/ft_map_cpy.c \
		source/ft_checks.c \

OBJS = $(SRC:%.c=%.o)

MLX_LIB = mlx/
MLX_FLAGS = -L mlx/ -lmlx -framework OpenGL -framework AppKit
LIBFT_LIB = libft/
LIBFT_FLAGS = -L libft/ -lft
DEBUG_FLAGS = -g3 -fsanitize=address

CC		= cc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

.c.o:
		$(CC) $(DEBUG_FLAGS) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		make -C $(MLX_LIB)
		make -C $(LIBFT_LIB)
		$(CC) $(DEBUG_FLAGS) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

clean:
		$(RM) */*.o
		$(RM) $(OBJS) $(OBJSBONUS)
		make -C $(MLX_LIB) clean
		make -C $(LIBFT_LIB) clean

fclean:	clean
		$(RM) $(NAME) $(BONUS_NAME) $(MLX_LIB)/libmlx.a
		make -C $(LIBFT_LIB) fclean

re:		fclean all

.PHONY : all clean fclean re