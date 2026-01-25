/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 09:21:37 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/25 09:21:37 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_images(t_game *game)
{
	if (game->img.wall)
		mlx_destroy_image(game->mlx_ptr, game->img.wall);
	if (game->img.floor)
		mlx_destroy_image(game->mlx_ptr, game->img.floor);
	if (game->img.player)
		mlx_destroy_image(game->mlx_ptr, game->img.player);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx_ptr, game->img.collectible);
	if (game->img.enemy)
		mlx_destroy_image(game->mlx_ptr, game->img.enemy);
	if (game->img.exit)
		mlx_destroy_image(game->mlx_ptr, game->img.exit);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->map_h)
	{
		if (game->map[i])
			free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	close_game(t_game *game)
{
	if (!game)
		exit(0);
	free_images(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_map(game);
	exit(0);
}

void	error_exit(t_game *game, char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, 2);
	if (!game)
		exit(1);
	free_images(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_map(game);
	exit(1);
}
