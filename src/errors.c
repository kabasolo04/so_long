/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:13:34 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/26 11:50:52 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_error_ms(char *ms)
{
	write(2, "\nERROR: ", 8);
	write(2, ms, ft_strlen(ms));
	write(2, "\n\n", 2);
}

void	ft_map_errors(int e)
{
	if (e == 0)
		ft_error_ms("Not valid map, un-paring lenghts.");
	if (e == 1)
		ft_error_ms("Maps border isn't valid.");
	if (e == 2)
		ft_error_ms("All the map must be done with 0, 1, P, C or E.");
	if (e == 3)
		ft_error_ms("Non-valid player quantity.");
	if (e == 4)
		ft_error_ms("Non-valid exit quantity.");
	if (e == 5)
		ft_error_ms("Non-valid collectable quantity.");
	if (e == 6)
		ft_error_ms("The player must be able to reach the exit.");
	if (e == 7)
		ft_error_ms("All the collectables must be accesible for the player");
}

void ft_lecture_errors(int e)
{
	if (e == 0)
		ft_error_ms("Non-valid argument quantity.");
	if (e == 1)
		ft_error_ms("Map must be named '.ber'.");
	if (e == 2)
		ft_error_ms("Non-valid fd.");
	if (e == 3)
		ft_error_ms("Map lecture went wrong.");
	if (e == 4)
		ft_error_ms("Could not open the map.");
	if (e == 5)
		ft_error_ms("There can not be more than one '\\n' on each line.");
	if (e == 6)
		ft_error_ms("Could not open textures.");
}