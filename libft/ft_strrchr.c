/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:48:14 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/30 12:40:48 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *)&s[i]);
		i --;
	}
	return (NULL);
}
