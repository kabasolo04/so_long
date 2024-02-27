NAME = so_long
CC		= cc
MLX_LIB = srcs/mlx/
MLX_FLAGS = -L srcs/mlx/ -lmlx -framework OpenGL -framework AppKit
LIBFT_LIB = srcs/libft/
LIBFT_FLAGS = -L srcs/libft/ -lft
DEBUG_FLAGS = -g3 -fsanitize=address
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

SRC = 	srcs/main.c \
		srcs/ft_get_data.c  \
		srcs/ft_draw_map.c \
		srcs/ft_key_hook.c \
		srcs/ft_checks.c \
		srcs/utils.c \

OBJS = $(SRC:%.c=%.o)

all:	$(NAME)

.c.o:
		$(CC) -I includes/. $(DEBUG_FLAGS) $(CFLAGS) -c $< -o $@

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