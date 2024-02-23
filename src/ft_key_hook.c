/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:20:50 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/22 16:48:50 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_refresh(t_game *g, size_t x, size_t y)
{
	mlx_put_image_to_window(g->mlx, g->win_ptr, g->floor, g->p_x * 32,
		g->p_y * 32);
	if (g->map[g->p_y][g->p_x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->exit, g->p_x * 32,
			g->p_y * 32);
	g->p_x = x;
	g->p_y = y;
	mlx_put_image_to_window(g->mlx, g->win_ptr, g->floor, g->p_x * 32,
		g->p_y * 32);
	if (g->map[g->p_y][g->p_x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->exit, g->p_x * 32,
			g->p_y * 32);
	mlx_put_image_to_window(g->mlx, g->win_ptr, g->player, x * 32, y * 32);
}

int	ft_key_hook(int key, t_game *g)
{
	size_t	x;
	size_t	y;

	x = g->p_x + (key == D || key == RIGHT) - (key == A || key == LEFT);
	y = g->p_y + (key == S || key == DOWN) - (key == W || key == UP);
	if (g->map[y][x] != '1' && !(x == g->p_x && y == g->p_y))
	{
		g->moves ++;
		ft_printf("Moves: %d\n", g->moves);
		if (g->map[y][x] == 'C')
		{
			g->c --;
			g->map[y][x] = '0';
		}
		ft_refresh(g, x, y);
	}
	if (key == ESC || (g->map[g->p_y][g->p_x] == 'E' && g->c == 0))
		exit (0);
	return (0);
}
