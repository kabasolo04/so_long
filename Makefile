NAME = so_long
BONUS_NAME = so_long_bonus
CC= cc
MLX_LIB = libs/mlx/
MLX_FLAGS = -L libs/mlx/ -lmlx -framework OpenGL -framework AppKit
LIBFT_LIB = libs/libft/
LIBFT_FLAGS = -L libs/libft/ -lft
CFLAGS = -O2 -Wall -Wextra -Werror #-fsanitize=address -g3
RM		= rm -f

SRC = 	srcs/main.c \
		srcs/ft_get_data.c  \
		srcs/ft_draw_map.c \
		srcs/ft_key_hook.c \
		srcs/ft_checks.c \
		srcs/utils.c \

SRC_BONUS = 	srcs_bonus/main_bonus.c \
				srcs_bonus/ft_get_data_bonus.c  \
				srcs_bonus/ft_draw_map_bonus.c \
				srcs_bonus/ft_key_hook_bonus.c \
				srcs_bonus/ft_checks_bonus.c \
				srcs_bonus/utils_bonus.c \

OBJS = $(SRC:%.c=%.o)
OBJ_SBONUS = $(SRC_BONUS:.c=.o)

all:	$(NAME)

.c.o:
		$(CC) -I includes/. $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		make -C $(MLX_LIB)
		make -C $(LIBFT_LIB)
		$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

sanitize:
	$(eval CFLAGS += -fsanitize=address -g3)

sani: sanitize all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_SBONUS)
		make -C $(MLX_LIB)
		make -C $(LIBFT_LIB)
		$(CC) $(CFLAGS) $(OBJ_SBONUS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(BONUS_NAME)

clean:
		$(RM) */*.o
		$(RM) $(OBJS) $(OBJ_SBONUS)
		make -C $(MLX_LIB) clean
		make -C $(LIBFT_LIB) clean

fclean:	clean
		$(RM) $(NAME) $(OBJ_SBONUS) $(MLX_LIB)/libmlx.a
		make -C $(LIBFT_LIB) fclean

re:		fclean all

.PHONY : all clean fclean re bonus