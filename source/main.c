/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:55:26 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/26 14:11:43 by kabasolo         ###   ########.fr       */
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

static int	ft_close(t_game *game)
{
	if (game->mlx && game->win_ptr)
		mlx_destroy_window (game->mlx, game->win_ptr);
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
	free (game->mlx);
	ft_freemap (game->map);
	free (game);
	close (game->fd);
	return (0);
}

static int	ft_ber(char *arg)
{
	int	l;
	int	i;

	l = ft_strlen(arg);
	if (ft_strncmp (&arg[l - 4], ".ber", 4))
		return (ft_errors(9), 1);
	if (ft_strncmp (arg, ".ber", 4) == 0)
		return (ft_errors(15), 1);
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '/')
		{
			if (ft_strncmp (&arg[i + 1], ".ber", 4) == 0)
				return (ft_errors(15), 1);
		}
		i ++;
	}
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
		return (ft_errors(8), 1);
	if (ft_ber(argv[1]))
		return (1);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd < 0)
		return (close(game.fd), ft_errors(10), 1);
	if (ft_get_data(&game, game.fd) != 0)
		return (1);
	ft_start_game(game);
	return (0);
}
