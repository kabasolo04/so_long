/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:00:52 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/27 11:11:48 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define PIX 100

typedef struct s_game
{
	char	**map;
	char	**map_cpy;

	void	*mlx;
	void	*win_ptr;

	void	*wall;
	void	*floor;
	void	*coin;
	void	*exit;
	void	*player;

	int		moves;

	size_t	col;
	size_t	lines;

	size_t	p;
	size_t	c;
	size_t	e;

	size_t	p_x;
	size_t	p_y;

	int		fd;
}	t_game;

int		ft_key_hook(int key, t_game *g);
int		ft_get_data(t_game *data, int fd);
int		ft_error(char *ms);
void	ft_map_cpy(t_game *data);
int		ft_checks(t_game *data);
void	ft_draw_map(t_game *g);
void	ft_freemap(char **map);

#endif //SO_LONG_H