/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:01:24 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/16 18:55:46 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start ++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]))
		end --;
	return (ft_substr(s1, start, end - start));
}
