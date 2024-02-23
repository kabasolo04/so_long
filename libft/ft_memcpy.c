/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:19:07 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/11 16:00:13 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	size_t			i;

	if (!dst && !src)
		return (0);
	s = dst;
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i ++;
	}
	return (s);
}
