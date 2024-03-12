/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:13:34 by kabasolo          #+#    #+#             */
/*   Updated: 2024/03/08 17:57:58 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_error(char *ms)
{
	write(2, "\nERROR: ", 8);
	write(2, ms, ft_strlen(ms));
	write(2, "\n\n", 2);
	return (1);
}

void	ft_freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i ++]);
	free(map);
}

void	ft_map_cpy(t_game *data)
{
	int	i;
	int	j;

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
