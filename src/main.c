/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:55:26 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/26 12:48:56 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i ++]);
	free(map);
}

static void	ft_free_sprites(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}

static int	ft_close(t_game *game)
{
	if (game->mlx && game->win_ptr)
		mlx_destroy_window (game->mlx, game->win_ptr);
	ft_free_sprites (game);
	free (game->mlx);
	ft_freemap (game->map);
	free (game);
	close (game->fd);
	return (0);
}

static int	ft_ber(char *arg)
{
	int	l;

	l = ft_strlen(arg);
	if (ft_strncmp (&arg[l - 4], ".ber", 4) != 0)
		return (write(2, "\nERROR: Map must be named '.ber'.\n\n", 35), 1);
	return (0);
}

static void	ft_start_game(t_game	game)
{
	game.mlx = mlx_init();
	game.moves = 0;
	game.win_ptr = mlx_new_window (game.mlx, game.col * PIX, game.lines * PIX,
			"SO_LONG");
	ft_draw_map (&game);
	mlx_hook(game.win_ptr, 17, 0, (int (*)())exit, &game);
	mlx_key_hook(game.win_ptr, ft_key_hook, &game);
	mlx_loop (game.mlx);
	ft_close(&game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_lecture_errors(0), 1);
	if (ft_ber(argv[1]))
		return (ft_lecture_errors(1), 1);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd < 0)
		return (close(game.fd), ft_lecture_errors(2), 1);
	if (ft_get_data(&game, game.fd) != 0)
		return (1);
	ft_start_game(game);
	return (0);
}
