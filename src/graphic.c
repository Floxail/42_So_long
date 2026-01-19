/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 07:11:19 by flvejux           #+#    #+#             */
/*   Updated: 19/01/2026 07:11:19 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_graphics(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_exit(game, "MLX init failed");
	int	w;
	int	h;

	w = game->map_w * 64;
	h = game->map_h * 64;
	game->win_ptr = mlx_new_window(game->mlx_ptr, w, h, "so-Long");
	if (!game->win_ptr)
		error_exit(game, "Windoes creation failed");
	game->img.wall = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/wall.xpm", &game->img.img_w, &game->img.img_h);
	game->img.player = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/player.xpm", &game->img.img_w, &game->img.img_h);
	game->img.floor = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/floor.xpm", &game->img.img_w, &game->img.img_h);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/collectible.xpm", &game->img.img_w, &game->img.img_h);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/enemy.xpm", &game->img.img_w, &game->img.img_h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/exit.xpm", &game->img.img_w, &game->img.img_h);
	if (!game->img.wall || !game->img.player || !game->img.floor
		|| !game->img.collectible || !game->img.enemy || !game->img.exit)
		error_exit(game, "texture loading failed");
}

void	render_map(t_game *game)
{
	int x;
	int y;
	int	x_pos;
	int y_pos;

	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			x_pos = x * 64;
			y_pos = y * 64;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, x_pos, y_pos);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.wall, x_pos, y_pos);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.player, x_pos, y_pos);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.collectible, x_pos, y_pos);
			else if (game->map[y][x] == 'X')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.enemy, x_pos, y_pos);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.exit, x_pos, y_pos);
			x++;
		}
		y++;
	}
}

