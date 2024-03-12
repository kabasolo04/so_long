/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:00:52 by kabasolo          #+#    #+#             */
/*   Updated: 2024/03/11 12:24:57 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <sys/time.h>

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define PIX 100
# define FRAME 16
# define HEIGHT 11
# define WIDTH 21

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
	int		frame;
	int		moving;
	int		x_dir;
	int		y_dir;

	int		col;
	int		lines;

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

#endif //SO_LONG_BONUS_H