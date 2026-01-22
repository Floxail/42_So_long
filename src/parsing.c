/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:05:29 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/22 11:20:19 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_map_height(char *map, t_game *game)
{
	int		fd;
	char	*line;

	game->map_h = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	line = get_next_line(fd);
	while (line)
	{
		game->map_h++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (TRUE);
}

static char	**fill_map(char *map, t_game *game)
{
	char	**tmp_map;
	char	*line;
	int		fd;
	int		i;

	tmp_map = malloc(sizeof(char *) * (game->map_h + 1));
	if (!tmp_map)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (free(tmp_map), NULL);
	i = 0;
	while (i < game->map_h)
	{
		line = get_next_line(fd);
		tmp_map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	close(fd);
	tmp_map[i] = NULL;
	return (tmp_map);
}

char	**parse_map(char *map, t_game *game)
{
	if (!get_map_height(map, game))
		return (NULL);
	if (game->map_h == 0)
		return (NULL);
	return (fill_map(map, game));
}
