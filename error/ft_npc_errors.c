/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_npc_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:03:51 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/22 14:18:52 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static void	ft_map_cpy(t_game *data)
{
	size_t	i;
	size_t	j;

	data->map_cpy = (char **)malloc((data->lines + 1) * sizeof(char *));
	if (data->map_cpy == NULL)
		return ;
	i = 0;
	while (i < data->lines)
	{
		data->map_cpy[i] = (char *)malloc((data->col + 1) * sizeof(char));
		if (data->map_cpy[i] == NULL)
			return (ft_freemap(data->map_cpy));
		j = 0;
		while (j < data->col)
		{
			data->map_cpy[i][j] = data->map[i][j];
			j ++;
		}
		data->map_cpy[i][j] = '\0';
		i ++;
	}
	data->map_cpy[data->lines] = NULL;
}

int	ft_npc_errors(t_game *data)
{
	ft_map_cpy(data);
	if (ft_flood_fill(data->map_cpy, 'E', data->p_x, data->p_y) != 1)
		return (ft_freemap(data->map_cpy), ft_errors(6), -1);
	ft_freemap(data->map_cpy);
	ft_map_cpy(data);
	if (ft_flood_fill(data->map_cpy, 'C', data->p_x, data->p_y) != data->c)
		return (ft_freemap(data->map_cpy), ft_errors(7), -1);
	ft_freemap(data->map_cpy);
	return (0);
}
