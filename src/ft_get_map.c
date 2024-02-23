/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:34:52 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/22 10:49:49 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_get_map(int fd)
{
	char	*map;
	char	*temp;
	char	*str;
	char	**result;

	map = malloc(1);
	map[0] = '\0';
	result = NULL;
	str = get_next_line(fd);
	while (str)
	{
		temp = map;
		map = ft_strjoin(temp, str);
		free(temp);
		if (str[0] == '\n')
			return (free(str), free(map), NULL);
		free(str);
		str = get_next_line(fd);
	}
	if (map[0] == '\0')
		return (free(map), NULL);
	result = ft_split(map, '\n');
	free(map);
	return (result);
}
