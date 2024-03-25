/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:55:26 by kabasolo          #+#    #+#             */
/*   Updated: 2024/03/21 15:40:32 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_ber(char *arg)
{
	int	l;

	l = ft_strlen(arg);
	if (ft_strncmp (&arg[l - 4], ".ber", 4))
		return (1);
	return (0);
}

static void	start_game(t_game	game)
{
	game.mlx = mlx_init();
	game.moves = 0;
	game.win_ptr = mlx_new_window (game.mlx, game.col * PIX, game.lines * PIX,
			"SO_LONG");
	draw_map (&game);
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
	if (ft_ber(argv[1]))
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
