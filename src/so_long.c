/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:31:26 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/20 14:15:37 by flox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	game.moves = 0;
	if (!arg_chk(ac, av))
		return (1);
	game.map = parse_map(av[1], &game);
	if (!game.map)
		return (1);
	if (!chk_is_rectangular(game.map, &game) || !chk_map_walls(game.map, &game)
		|| !chk_map_content(game.map, &game) || !chk_valid_path(game.map, &game))
		return (free_map(&game), 1);
	ft_putendl_fd("Valid map - Launching game", 1);
	init_graphics(&game);
	render_map(&game);
	mlx_hook(game.win_ptr, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win_ptr, 17, 0, close_game, &game);
	mlx_expose_hook(game.win_ptr, render_map, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
