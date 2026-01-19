/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:24:14 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/19 12:24:43 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	next_x;
	int	next_y;

	if (keycode == 65307)
		close_game(game);
	next_x = game->player_x;
	next_y = game->player_y;
	if (keycode == 'w' || keycode == 119)
		next_y--;
	else if (keycode == 's' || keycode == 115)
		next_y++;
	else if (keycode == 'a' || keycode == 97)
		next_x--;
	else if (keycode == 'd' || keycode == 100)
		next_x++;
	else
		return (0);
	move_player(game, next_x, next_y);
	return (0);
}
