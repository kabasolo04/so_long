/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:56:59 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/30 12:18:18 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s1;
	i = 0;
	if (n > 0)
	{
		while (i < n && str[i] == ((unsigned char *)s2)[i])
		{
			if ((str[i] && str[i] == '\0') || i == n - 1)
				return (0);
			i ++;
		}
		return (str[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}
