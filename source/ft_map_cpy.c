/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:42:10 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/26 12:25:59 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_cpy(t_game *data)
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
