/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:39:44 by kabasolo          #+#    #+#             */
/*   Updated: 2024/03/21 14:25:57 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**get_map(int fd)
{
	char	*map;
	char	*temp;
	char	*str;
	char	**result;

	map = malloc(1);
	map[0] = '\0';
	str = get_next_line(fd);
	while (str)
	{
		temp = map;
		map = ft_strjoin(temp, str);
		free(temp);
		if (str[0] == '\n')
			return (free(str), free(map), error
				("There can not be more than one '\\n' on each line."), NULL);
		free(str);
		str = get_next_line(fd);
	}
	if (map[0] == '\0')
		return (free(map), error("Map lecture went wrong."), NULL);
	result = ft_split(map, '\n');
	free(map);
	return (result);
}

static void	get_pos(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
			x ++;
		}
		y ++;
	}
}

int	get_data(t_game *data, int fd)
{
	data->map = get_map(fd);
	if (!data->map)
		return (1);
	data->col = ft_strlen(data->map[0]);
	data->lines = 0;
	while (data->map[data->lines])
		data->lines ++;
	data->p = find(data->map, 'P');
	data->c = find(data->map, 'C');
	data->e = find(data->map, 'E');
	if (data->p != 1)
		return (freemap(data->map), error("Non-valid player quantity."));
	if (data->c < 1)
		return (freemap(data->map), error("Non-valid coin quantity."));
	if (data->e != 1)
		return (freemap(data->map), error("Non-valid exit quantity."));
	get_pos(data);
	data->map[data->p_y][data->p_x] = '0';
	if (checks(data))
		return (freemap(data->map), 1);
	return (0);
}
