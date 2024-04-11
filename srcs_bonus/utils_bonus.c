/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:13:34 by kabasolo          #+#    #+#             */
/*   Updated: 2024/03/29 14:41:16 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error(char *ms)
{
	write(2, "\nERROR: ", 8);
	write(2, ms, ft_strlen(ms));
	write(2, "\n\n", 2);
	return (1);
}

void	freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i ++]);
	free(map);
}

char	**map_cpy(t_game *data)
{
	int		i;
	int		j;
	char	**map_cpy;

	map_cpy = (char **)malloc((data->lines + 1) * sizeof(char *));
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (i < data->lines)
	{
		map_cpy[i] = (char *)malloc((data->col + 1) * sizeof(char));
		if (map_cpy[i] == NULL)
			return (freemap(map_cpy), NULL);
		j = 0;
		while (j < data->col)
		{
			map_cpy[i][j] = data->map[i][j];
			j ++;
		}
		map_cpy[i][j] = '\0';
		i ++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	find(char **map, char c)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				i ++;
			x ++;
		}
		y ++;
	}
	return (i);
}

void	ft_close(t_game *game)
{
	if (game->mlx && game->win_ptr)
		mlx_destroy_window (game->mlx, game->win_ptr);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	free (game->mlx);
	freemap (game->map);
	exit(0);
}
