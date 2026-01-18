/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:16:12 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/18 11:41:28 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		i;

	if (!arg_chk(ac, av))
		return (1);
	game.map = parse_map(av[1], &game);
	if (!game.map)
		return (1);
	if (!chk_is_rectangular(game.map, &game))
		return (1);
	if (!chk_map_walls(game.map, &game))
		return (1);
	if (!chk_map_content(game.map, &game))
		return (1);
	if (!chk_valid_path(game.map, &game))
		return (1);
	ft_putendl_fd("Valid", 1);
	i = 0;
	while (game.map[i])
	{
		printf("%s\n", game.map[i]);
		i++;
	}
	return (0);
}