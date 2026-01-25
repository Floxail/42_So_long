/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 09:11:12 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/25 09:11:12 by flvejux          ###   ########.ch       */
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

void	display_moves(t_game *game)
{
	char	*moves;
	char	*str;

	moves = ft_itoa(game->moves);
	str = ft_strjoin("Moves : ", moves);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.wall, 0, 0);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, 0xFFFFFF, str);
	free(moves);
	free(str);
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
