/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flox <flox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2026/01/25 09:12:50 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/25 09:12:50 by flvejux          ###   ########.ch       */
=======
/*   Created: 2026/01/20 10:47:13 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/24 10:10:02 by flox             ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	load_textures(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/wall.xpm",
			&game->img.img_w, &game->img.img_h);
	game->img.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/player.xpm", &game->img.img_w, &game->img.img_h);
	game->img.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/floor.xpm", &game->img.img_w, &game->img.img_h);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/collectible.xpm", &game->img.img_w, &game->img.img_h);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/enemy.xpm", &game->img.img_w, &game->img.img_h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/exit.xpm", &game->img.img_w, &game->img.img_h);
	if (!game->img.wall || !game->img.player || !game->img.floor
		|| !game->img.collectible || !game->img.enemy || !game->img.exit)
		error_exit(game, "texture loading failed");
}

static void	init_window(t_game *game)
{
	int	w;
	int	h;
	int	screen_w;
	int	screen_h;

	w = game->map_w * 64;
	h = game->map_h * 64;
	mlx_get_screen_size(game->mlx_ptr, &screen_w, &screen_h);
	if (w > screen_w || h > (screen_h - 64))
		error_exit(game, "Window size exceeds screen size\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, w, h, "so_Long");
	if (!game->win_ptr)
		error_exit(game, "Window creation failed\n");
}

void	init_graphics(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_exit(game, "MLX init failed");
	init_window(game);
	load_textures(game);
}

void	init_img(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.floor, x * 64, y * 64);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.wall, x * 64, y * 64);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player, x * 64, y * 64);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.collectible, x * 64, y * 64);
	else if (tile == 'X')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.enemy, x * 64, y * 64);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exit, x * 64, y * 64);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			init_img(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
