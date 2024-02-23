/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:43:52 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/04 10:21:10 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(count * size);
	while ((i < count * size) && str)
	{
		str[i] = 0;
		i ++;
	}
	return (str);
}
