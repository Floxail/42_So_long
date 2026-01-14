/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:01:05 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/14 10:05:09 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	chk_extension(char *file);

static int	arg_chk(int ac, char **av)
{
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
	if (open(av[1], O_RDONLY) == -1)
		ft_putendl_fd("reading map error", 1);
	ft_putendl_fd("Valid ✔", 0);
	return (TRUE);
}

static int	chk_extension(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (ext && ft_strncmp(ext, ".ber", 4))
		return (TRUE);
	return (FALSE);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		printf("OK %d is the arg check return", arg_chk(ac, av));
	}
}
