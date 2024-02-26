/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:24:45 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/26 11:54:24 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_load_sprites(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/P.xpm", &x, &y);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/0.xpm", &x, &y);
	game->coin = mlx_xpm_file_to_image(game->mlx, "textures/C.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/E.xpm", &x, &y);
	if (game->wall && game->player && game->floor && game->coin && game->exit)
		return (0);
	return (1);
}

static void	ft_put_sprite(t_game *g, char c, int i, int j)
{
	if (c != '1')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->floor, j * PIX, i * PIX);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->wall, j * PIX, i * PIX);
	if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->coin, j * PIX, i * PIX);
	if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->exit, j * PIX, i * PIX);
	if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->player, j * PIX, i * PIX);
}

void	ft_draw_map(t_game *game)
{
	size_t	y;
	size_t	x;

	if (ft_load_sprites(game))
		return (ft_lecture_errors(6), exit(0));
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
