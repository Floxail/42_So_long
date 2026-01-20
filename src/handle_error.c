/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:08:33 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/19 12:08:33 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	chk_extension(char *file);

int	arg_chk(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putendl_fd("please put only one maps", 1);
		return (FALSE);
	}
	if (!chk_extension(av[1]))
	{
		ft_putendl_fd("put a \".ber\" file please", 1);
		return (FALSE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("reading map error", 1);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

static int	chk_extension(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (ext && ft_strncmp(ext, ".ber", 4) == 0)
		return (TRUE);
	return (FALSE);
}

int	chk_map_walls(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[game->map_h - 1][i] != '1')
		{
			ft_putendl_fd("Error\nMap is not surrounded by walls", 1);
			return (FALSE);
		}
		i++;
	}
	j = 0;
	while (j < game->map_h)
	{
		if (map[j][0] != '1' || map[j][game->map_w - 1] != '1')
		{
			ft_putendl_fd("Error\nMap is not surrounded by walls", 1);
			return (FALSE);
		}
		j++;
	}
	return (TRUE);
}

int	chk_is_rectangular(char **map, t_game *game)
{
	int	i;

	if (!map || !map[0])
		return (FALSE);
	game->map_w = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != game->map_w)
		{
			ft_putendl_fd("Error\nMap is not rectangular", 1);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
