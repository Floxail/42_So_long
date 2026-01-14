/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:18:40 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/14 11:40:54 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*map_parser(char *map)
{
	int		height;
	int		i;
	int		fd;
	char	*tmp_map;
	char	*line;

	height = 0;
	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	tmp_map = malloc(sizeof(char *) * (height+1));
	if (!tmp_map)
		return (NULL);
	while (i < height)
	{
		line = get_next_line(fd);
		tmp_map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	return (map);
}

