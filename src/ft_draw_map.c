/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:24:45 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/22 16:49:15 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_sprites(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx, "sprites/1.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, "sprites/P.xpm", &x, &y);
	game->floor = mlx_xpm_file_to_image(game->mlx, "sprites/0.xpm", &x, &y);
	game->coin = mlx_xpm_file_to_image(game->mlx, "sprites/C.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "sprites/E.xpm", &x, &y);
}

void	free_sprites(t_game *game)
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

void	ft_put_sprite(t_game *g, char c, int i, int j)
{
	if (c != '1')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->floor, j * 32, i * 32);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->wall, j * 32, i * 32);
	if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->coin, j * 32, i * 32);
	if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->exit, j * 32, i * 32);
	if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->player, j * 32, i * 32);
}

void	ft_draw_map(t_game *game)
{
	size_t	y;
	size_t	x;

	load_sprites(game);
	y = 0;
	while (y < game->lines)
	{
		x = 0;
		while (x < game->col)
		{
			if (y == game->p_y && x == game->p_x)
				ft_put_sprite(game, 'P', y, x);
			else
				ft_put_sprite(game, game->map[y][x], y, x);
			x ++;
		}
		y ++;
	}
}
