/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:58:58 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/15 20:39:04 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	t;

	i = 0;
	if (!needle[i])
		return ((char *)&haystack[i]);
	while (haystack[i] && i < len)
	{
		t = 0;
		while (haystack[i + t] == needle[t] && i + t < len)
		{
			if (!needle[++ t])
				return ((char *)&haystack[i]);
		}
		i ++;
	}
	return (NULL);
}
