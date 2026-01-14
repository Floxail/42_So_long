/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:07:05 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/14 10:43:01 by flvejux          ###   ########.ch       */
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
	int		collect_count;
	int		exit_count;
	//t_img	sprite;
	//t_img	player;
}	t_game;

static int	arg_chk(int ac, char **av);

#endif