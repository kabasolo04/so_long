/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:55:26 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/09 13:07:52 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ber(char *arg)
{
	int	l;

	l = ft_strlen(arg);
	if (ft_strncmp (&arg[l - 4], ".ber", 4))
		return (1);
	return (0);
}

static int	load_sprites(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures_bonus/1.xpm", &x, &y);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures_bonus/0.xpm", &x, &y);
	game->coin = mlx_xpm_file_to_image(game->mlx, "textures_bonus/C.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures_bonus/E.xpm", &x, &y);
	if (game->wall && game->floor && game->coin && game->exit)
		return (0);
	return (1);
}

int	animation(t_game *g)
{
	if (g->moving)
		mlx_clear_window(g->mlx, g->win_ptr);
	g->frame = (g->frame + 1) * (g->frame <= FRAME);
	draw_map(g);
	if (g->frame == FRAME - 2)
	{
		if (g->map[g->p_y][g->p_x] == 'C')
		{
			g->map[g->p_y][g->p_x] = '0';
			g->c --;
		}
		if (g->map[g->p_y][g->p_x] == 'E' && g->c == 0)
			exit (0);
	}
	if (g->frame > FRAME)
		g->moving = 0;
	return (0);
}

static void	start_game(t_game	game)
{
	game.mlx = mlx_init();
	game.moves = 0;
	game.moving = 1;
	game.frame = 0;
	game.win_ptr = mlx_new_window (game.mlx, WIDTH * PIX, HEIGHT * PIX, "SO_LONG_BONUS");
	if (load_sprites(&game))
		return (error("Could not open textures."), exit(0));
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_hook(game.win_ptr, 17, 0, (void *)ft_close, &game);
	mlx_hook(game.win_ptr, 2, 0, (void *)key_hook, &game);
	mlx_loop (game.mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
		return (error("Non-valid argument quantity."));
	if (ber(argv[1]))
		return (error("Map must be named '*.ber'."));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (close(fd), error("Non-valid fd."));
	if (get_data(&game, fd) != 0)
		return (1);
	close(fd);
	start_game(game);
	return (0);
}

/*
------------------------------------------------------------------------------

		b = (b + 1) * (b <= n) + i * (b > n); //Legal

		b = (b <= n ? b + 1 : i); //Prohibido (Ternario)

	EJEMPLO: (i -> i + 1 -> i + 2 -> i + 3 -> ... -> n -> i -> i + 1 -> ...)

------------------------------------------------------------------------------

		n = a * (n == b) + b * (n == a); //Legal

		n = (n == a ? n = b : n = a); //Prohibido (Ternario)

	EJEMPLO: (a -> b -> a -> b -> a -> b -> ...)

------------------------------------------------------------------------------

		n = a * (n == b) + b * (n == c) + c * (n == a);

	EJEMPLO: (a -> b -> c -> a -> b -> c -> ...)

------------------------------------------------------------------------------
*/

