/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:39:44 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/22 11:03:59 by kabasolo         ###   ########.fr       */
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

int	ft_get_data(t_game *data, int fd)
{
	int	n;

	data->map = ft_get_map(fd);
	if (!data->map)
		return (ft_errors(10), 1);
	data->col = ft_strlen(data->map[0]);
	n = 0;
	while (data->map[n])
		n ++;
	data->lines = n;
	data->c = ft_find(data, 'C'); //Coin quantity
	data->e = ft_find(data, 'E'); //Exit quantity
	data->p = ft_find(data, 'P'); //Player quantity
	if (data->c < 1)
		return (ft_freemap(data->map), ft_errors(5), 1);
	if (data->e != 1)
		return (ft_freemap(data->map), ft_errors(4), 1);
	if (data->p != 1)
		return (ft_freemap(data->map), ft_errors(3), 1);
	data->map[data->p_y][data->p_x] = '0';
	if (ft_map_check(data) != 0 || ft_npc_errors(data) != 0)
		return (ft_freemap(data->map), 1);
	return (0);
}
