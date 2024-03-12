/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:20:50 by kabasolo          #+#    #+#             */
/*   Updated: 2024/03/11 16:00:01 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_key_hook(int key, t_game *g)
{
	size_t	x;
	size_t	y;

	if (key == ESC)
		exit (0);
	if (g->moving)
		return (0);
	x = g->p_x + (key == D || key == RIGHT) - (key == A || key == LEFT);
	y = g->p_y + (key == S || key == DOWN) - (key == W || key == UP);
	if (g->map[y][x] != '1' && !(x == g->p_x && y == g->p_y))
	{
		ft_printf("Moves: %d\n", g->moves ++);
		g->p_x = x;
		g->p_y = y;
		g->x_dir = (key == A || key == LEFT) - (key == D || key == RIGHT);
		g->y_dir = (key == W || key == UP) - (key == S || key == DOWN);
		g->frame = 0;
		g->moving = 1;
	}
	return (0);
}

