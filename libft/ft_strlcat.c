/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:31 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/30 12:34:11 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	t;
	size_t	l;

	i = ft_strlen(dst);
	t = ft_strlen(src);
	l = i + t;
	if (dstsize <= i)
		return (dstsize + t);
	t = 0;
	while (src[t] && t < dstsize - i - 1)
	{
		dst[i + t] = src[t];
		t ++;
	}
	dst[i + t] = '\0';
	return (l);
}
