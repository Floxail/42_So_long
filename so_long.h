/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:27:04 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/18 12:19:12 by flox             ###   ########.fr       */
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
}

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
	t_img 	img;
}	t_game;

char		**parse_map(char *filepath, t_game *game);
int			arg_chk(int ac, char **av);
int			chk_is_rectangular(char **map, t_game *game);
int			chk_map_walls(char **map, t_game *game);
int			chk_map_content(char **map, t_game *game);
int			chk_valid_path(char **map, t_game *game);

#endif