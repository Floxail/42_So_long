/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 07:54:03 by flvejux           #+#    #+#             */
/*   Updated: 19/01/2026 07:54:03 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int key_hook(int keycode, t_game *game)
{
    if (keycode == 65307)
        close_game(game);
    int next_x = game->player_x;
    int next_y = game->player_y;

    if (keycode == 'w') next_y--;
    else if (keycode == 's') next_y++;
    else if (keycode == 'a') next_x--;
    else if (keycode == 'd') next_x++;
    else
		return (0);
    move_player(game, next_x, next_y);
    return (0);
}