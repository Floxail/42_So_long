/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:08:27 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/19 12:08:27 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'X')
		return (ft_putendl_fd("PERDU", 1), close_game(game));
	if (game->map[y][x] == 'E')
	{
		if (game->collect_count == 0)
			return (ft_putendl_fd("BRAVO", 1), close_game(game));
		else
			return ;
	}
	if (game->map[y][x] == 'C')
	{
		game->collect_count -= 1;
		game->map[y][x] = '0';
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
	game->moves += 1;
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	render_map(game);
}
