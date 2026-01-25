/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2026/01/25 09:14:23 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/25 09:14:39 by flvejux          ###   ########.ch       */
=======
/*   Created: 2026/01/20 10:31:26 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/22 11:19:46 by flox             ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
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
<<<<<<< HEAD
	if (!chk_is_rectangular(game.map, &game))
		return (1);
	if (!chk_map_walls(game.map, &game))
		return (1);
	if (!chk_map_content(game.map, &game))
		return (1);
	if (!chk_valid_path(game.map, &game))
		return (1);
=======
	if (!chk_is_rectangular(game.map, &game) || !chk_map_walls(game.map, &game)
		|| !chk_map_content(game.map, &game)
		|| !chk_valid_path(game.map, &game))
		return (free_map(&game), 1);
>>>>>>> refs/remotes/origin/main
	ft_putendl_fd("Valid map - Launching game", 1);
	init_graphics(&game);
	render_map(&game);
	mlx_hook(game.win_ptr, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win_ptr, 17, 0, close_game, &game);
	mlx_expose_hook(game.win_ptr, render_map, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
