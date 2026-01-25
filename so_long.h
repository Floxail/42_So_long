/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:19:08 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/25 09:16:38 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*enemy;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		map_w;
	int		map_h;
	int		collectibles;
	int		moves;
	int		player_count;
	int		player_x;
	int		player_y;
	int		collect_count;
	int		exit_count;
	int		enemy_count;
	t_img	img;
}	t_game;

char		**parse_map(char *filepath, t_game *game);
int			arg_chk(int ac, char **av);
int			chk_is_rectangular(char **map, t_game *game);
int			chk_map_walls(char **map, t_game *game);
int			chk_map_content(char **map, t_game *game);
int			chk_valid_path(char **map, t_game *game);
void		init_graphics(t_game *game);
int			render_map(t_game *game);
void		init_img(t_game *game, int x, int y);
int			key_hook(int keycode, t_game *game);
int			close_game(t_game *game);
void		move_player(t_game *game, int x, int y);
void		error_exit(t_game *game, char *str);

#endif