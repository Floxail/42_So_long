/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:40:00 by flox              #+#    #+#             */
/*   Updated: 2026/01/18 11:45:00 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C'
		|| c == 'X');
}

static void	count_element(char c, int x, int y, t_game *game)
{
	if (c == 'P')
	{
		game->player_count++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (c == 'E')
		game->exit_count++;
	else if (c == 'C')
		game->collect_count++;
	else if (c == 'X')
		game->enemy_count++;
}

static int	check_counts(t_game *game)
{
	if (game->player_count != 1 || game->exit_count != 1
		|| game->collect_count < 1)
	{
		ft_putendl_fd("Error\nMap must have 1 P, 1 E, and at least 1 C", 1);
		return (FALSE);
	}
	return (TRUE);
}

int	chk_map_content(char **map, t_game *game)
{
	int	y;
	int	x;

	game->player_count = 0;
	game->exit_count = 0;
	game->collect_count = 0;
	game->enemy_count = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!is_valid_char(map[y][x]))
			{
				ft_putendl_fd("Error\nInvalid character in map", 1);
				return (FALSE);
			}
			count_element(map[y][x], x, y, game);
		}
	}
	return (check_counts(game));
}
