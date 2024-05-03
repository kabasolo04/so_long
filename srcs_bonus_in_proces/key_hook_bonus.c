/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:20:50 by kabasolo          #+#    #+#             */
/*   Updated: 2024/05/03 20:17:31 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_hook(int key, t_game *g)
{
	size_t	x;
	size_t	y;

	if (key == ESC)
		ft_close(g);
	g->x_dir = (key == D || key == RIGHT) - (key == A || key == LEFT);
	g->y_dir = (key == S || key == DOWN) - (key == W || key == UP);
	x = g->p_x + g->x_dir;
	y = g->p_y + g->y_dir;
	if (x == g->p_x && y == g->p_y)
		return ;
	if (g->map[y][x] != '1')
	{
		if (g->p_des == 100)
		{
			ft_printf("PATATAAA\n");
			g->p_x = x;
			g->p_y = y;
		}
	}
	g->moving = g->x_dir;
}