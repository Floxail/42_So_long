/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:08:27 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/19 14:09:00 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_box(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'X')
	{
		ft_putendl_fd("PERDU", 1);
		close_game(game);
	}
	if (game->map[y][x] == 'E')
	{
		if (game->collect_count == 0)
		{
			ft_putendl_fd("BRAVO", 1);
			close_game(game);
		}
		return (0);
	}
	if (game->map[y][x] == 'C')
		game->collect_count -= 1;
	return (1);
}

void	move_player(t_game *game, int x, int y)
{
	if (!check_box(game, x, y))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
	game->moves += 1;
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
	render_map(game);
}
