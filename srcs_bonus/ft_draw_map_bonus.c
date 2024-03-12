/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:24:45 by kabasolo          #+#    #+#             */
/*   Updated: 2024/03/11 17:01:19 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_put_sprite(t_game *g, char c, int x, int y)
{
	int	x_pix;
	int	y_pix;
	int	x_des;
	int	y_des;
	
	x_des = g->x_dir * (PIX / FRAME) * g->frame;
	y_des = g->y_dir * (PIX / FRAME) * g->frame;
	x_pix = (x - g->x_dir * g->moving) * PIX + x_des * g->moving;
	y_pix = (y - g->y_dir * g->moving)  * PIX + y_des * g->moving;
	if (c != '1')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->floor, x_pix, y_pix);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->wall, x_pix, y_pix);
	if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->coin, x_pix, y_pix);
	if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win_ptr, g->exit, x_pix, y_pix);
}

static void	ft_fname(char *f_name, char prefix, char middle, int n)
{
	ft_memcpy(f_name, "textures_bonus/", 15);
	f_name[15] = prefix;
	f_name[16] = '/';
	f_name[17] = middle;
	f_name[18] = '/';
	f_name[19] = "01234567"[n % 4];
	ft_memcpy(f_name + 20, ".xpm", 4);
	f_name[24] = '\0';
}

static void	ft_put_player(t_game *g, int x, int y)
{
	int		i;
	int		n;
	char	f_name[25];
	
	n = FRAME / 4;
	ft_fname(f_name, 'P', 'R', g->frame / 4 * g->moving);
	if (g->x_dir == -1)
		ft_fname(f_name, 'P', 'R', g->frame / n * g->moving);
	if (g->x_dir == 1)
		ft_fname(f_name, 'P', 'L', g->frame / n * g->moving);
	if (g->y_dir == -1)
		ft_fname(f_name, 'P', 'D', g->frame / n * g->moving);
	if (g->y_dir == 1)
		ft_fname(f_name, 'P', 'U', g->frame / n * g->moving);
	g->player = mlx_xpm_file_to_image(g->mlx, f_name, &i, &n);
	if (!g->player || n % 4 > 4)
		return ;
	mlx_put_image_to_window(g->mlx, g->win_ptr, g->player, PIX * x, PIX * y);
	if (g->player)
		mlx_destroy_image(g->mlx, g->player);
}

void	ft_draw_map(t_game *g)
{
	int		y;
	int		x;
	int		ty;
	int		tx;

	ty = g->p_y - HEIGHT / 2;
	tx = g->p_x - WIDTH / 2;
	y = -1;
	while (y <= HEIGHT && g->moving)
	{
		x = -1;
		while (x <= WIDTH)
		{
			if (y + ty >= 0 && y + ty < g->lines && x + tx >= 0 && x + tx < g->col)
				ft_put_sprite(g, g->map[y + ty][x + tx], x, y);
			else
				ft_put_sprite(g, '1', x, y);
			x ++;
		}
		y ++;
		if (!g->moving)
			ft_put_sprite(g, g->map[g->p_y][g->p_x], WIDTH / 2, HEIGHT / 2);
		ft_put_player(g, WIDTH / 2, HEIGHT / 2);
	}
}
