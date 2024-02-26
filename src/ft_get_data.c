/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:39:44 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/26 12:40:49 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_find(t_game *data, char c)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == c)
			{
				i ++;
				data->p_x = x;
				data->p_y = y;
			}
			x ++;
		}
		y ++;
	}
	return (i);
}

static char	**ft_get_map(int fd)
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
			return (free(str), free(map), ft_lecture_errors(5), NULL);
		free(str);
		str = get_next_line(fd);
	}
	if (map[0] == '\0')
		return (free(map), ft_lecture_errors(3), NULL);
	result = ft_split(map, '\n');
	free(map);
	return (result);
}

int	ft_get_data(t_game *data, int fd)
{
	int	n;

	data->map = ft_get_map(fd);
	if (!data->map)
		return (1);
	data->col = ft_strlen(data->map[0]);
	n = 0;
	while (data->map[n])
		n ++;
	data->lines = n;
	data->c = ft_find(data, 'C'); //Coin quantity
	data->e = ft_find(data, 'E'); //Exit quantity
	data->p = ft_find(data, 'P'); //Player quantity
	if (data->p != 1)
		return (ft_freemap(data->map), ft_map_errors(3), 1);
	if (data->c < 1)
		return (ft_freemap(data->map), ft_map_errors(5), 1);
	if (data->e != 1)
		return (ft_freemap(data->map), ft_map_errors(4), 1);
	data->map[data->p_y][data->p_x] = '0';
	if (ft_checks(data))
		return (ft_freemap(data->map), 1);
	return (0);
}
