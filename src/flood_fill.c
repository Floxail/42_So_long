/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:57:09 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/20 11:11:27 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

static char	**copy_map(char **map, t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->map_h + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->map_h)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_map_copy(map_copy, i);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static int	check_path_valid(char **map_copy, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
			{
				ft_putendl_fd("Error\nNo valid path to all C and E", 1);
				return (FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (y < 0 || y >= game->map_h || x < 0 || x >= game->map_w)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

int	chk_valid_path(char **map, t_game *game)
{
	char	**map_copy;
	int		result;

	map_copy = copy_map(map, game);
	if (!map_copy)
		return (FALSE);
	flood_fill(map_copy, game->player_x, game->player_y, game);
	result = check_path_valid(map_copy, game);
	free_map_copy(map_copy, game->map_h);
	return (result);
}
