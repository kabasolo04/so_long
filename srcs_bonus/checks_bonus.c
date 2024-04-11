/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:03:51 by kabasolo          #+#    #+#             */
/*   Updated: 2024/03/29 11:18:28 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_closed(char **map, int col, int lines)
{
	int	n;
	int	m;

	n = 0;
	while (n < col && map[0][n] == '1' && map[lines - 1][n] == '1')
		n ++;
	m = 0;
	while (m < lines && map[m][0] == '1' && map[m][col - 1] == '1')
		m ++;
	if (n != col || m != lines)
		return (-1);
	return (0);
}

static int	is_all_even(char **map)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (len != ft_strlen(map[i ++]))
			return (-1);
	}
	return (0);
}

static int	is_all_legal(char **map)
{
	char	*chr;
	int		x;
	int		y;

	chr = "01PEC";
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr(chr, map[y][x]))
				return (-1);
			x ++;
		}
		y ++;
	}
	return (0);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] && map[y][x] != '1')
	{
		map[y][x] = '1';
		flood_fill(map, x + 1, y);
		flood_fill(map, x - 1, y);
		flood_fill(map, x, y + 1);
		flood_fill(map, x, y - 1);
	}
}

int	checks(t_game *data)
{
	char **copy;
	
	if (is_all_legal(data->map))
		return (error("The map must be done only with '01PCE'."));
	if (is_all_even(data->map))
		return (error("Not valid map, un-paring lenghts."));
	if (is_closed(data->map, data->col, data->lines))
		return (error("Maps border must be surrounded by 1."));
	copy = map_cpy(data);
	if (!copy)
		return (error("Memory error."));
	flood_fill(copy, data->p_x, data->p_y);
	if (find(copy, 'E') != 0)
		return (freemap(copy), error("The player must be able to reach the exit."));
	if (find(copy, 'C') != 0)
		return (freemap(copy), error("All the coins must be accesible for the player"));
	return (freemap(copy), 0);
}
