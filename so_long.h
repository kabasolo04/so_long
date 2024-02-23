/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:00:52 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/22 19:37:45 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef so_long
# define so_long

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>

#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

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

char	**ft_get_map(int fd);
int		ft_key_hook(int key, t_game *g);
int		ft_get_data(t_game *data, int fd);
void	ft_errors(int e);
int		ft_map_check(t_game *data);
int		ft_npc_errors(t_game *data);
void	ft_draw_map(t_game *g);
void	ft_free_sprites(t_game *game);
void	load_sprites(t_game *game);
void	ft_freemap(char **map);
void	mlx_sleep(int milliseconds, t_game *game);
int		ft_close(t_game *game);

#endif //so_long