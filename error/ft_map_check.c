/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:42:10 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/22 10:59:38 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		if (len != ft_strlen(map[i]))
			return (-1);
		i ++;
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

int	ft_map_check(t_game *data)
{
	if (ft_is_all_legal(data->map) != 0)
		return (ft_errors(2), -1);
	if (ft_is_closed(data->map, data->col, data->lines) != 0)
		return (ft_errors(1), -1);
	if (ft_is_all_even(data->map) != 0)
		return (ft_errors(0), -1);
	return (0);
}
