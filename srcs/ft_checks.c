/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:03:51 by kabasolo          #+#    #+#             */
/*   Updated: 2024/03/11 16:33:32 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_closed(char **map, int col, int lines)
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

static int	ft_is_all_even(char **map)
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

static int	ft_is_all_legal(char **map)
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

static size_t	ft_flood_fill(char **map, char c, int x, int y)
{
	int	num;

	num = (map[y][x] == c);
	if (map[y][x] != '1')
	{
		map[y][x] = '1';
		num += ft_flood_fill(map, c, x + 1, y);
		num += ft_flood_fill(map, c, x - 1, y);
		num += ft_flood_fill(map, c, x, y + 1);
		num += ft_flood_fill(map, c, x, y - 1);
	}
	return (num);
}

int	ft_checks(t_game *data)
{
	if (ft_is_all_legal(data->map))
		return (ft_error("The map must be done only with '01PCE'."));
	if (ft_is_all_even(data->map))
		return (ft_error("Not valid map, un-paring lenghts."));
	if (ft_is_closed(data->map, data->col, data->lines))
		return (ft_error("Maps border must be surrounded by 1."));
	ft_map_cpy (data);
	if (data->map_cpy && ft_flood_fill(data->map_cpy, 'E', data->p_x,
			data->p_y) != 1)
		return (ft_freemap(data->map_cpy),
			ft_error("The player must be able to reach the exit."));
	if (data->map_cpy)
		ft_freemap(data->map_cpy);
	else
		return (ft_error("Memory error."));
	ft_map_cpy (data);
	if (data->map_cpy && ft_flood_fill(data->map_cpy, 'C', data->p_x,
			data->p_y) != data->c)
		return (ft_freemap(data->map_cpy),
			ft_error("All the coins must be accesible for the player"));
	if (data->map_cpy)
		ft_freemap(data->map_cpy);
	else
		return (ft_error("Memory error."));
	return (0);
}
