/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:48:15 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/30 11:51:58 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	b;
	int	n;

	i = 0;
	b = 0;
	n = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' \
	|| str[i] == '\v' || str[i] == '\f')
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			b = 1;
		i ++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		n = (n * 10) + str[i] - '0';
		i ++;
	}
	if (b == 1)
		return (n * -1);
	return (n);
}
