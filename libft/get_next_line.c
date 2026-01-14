/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:09:42 by flvejux           #+#    #+#             */
/*   Updated: 2026/01/08 10:09:45 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static char	*cat_buff(char *stock, char *buffer)
{
	char	*tmp;

	tmp = stock;
	stock = ft_strjoin(stock, buffer);
	free (tmp);
	return (stock);
}

static char	*read_line(int fd, char *stock)
{
	int			count;
	char		*buffer;

	count = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!stock)
		stock = ft_strdup("");
	while (!ft_strchr(stock, '\n') && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (free (buffer), free (stock), NULL);
		buffer[count] = '\0';
		stock = cat_buff(stock, buffer);
		if (!stock)
			return (free (buffer), NULL);
	}
	return (free (buffer), stock);
}

static char	*get_line(char **stock)
{
	char	*line;
	char	*n_stock;
	int		len;

	len = 0;
	while ((*stock)[len] != '\n' && (*stock)[len])
		len++;
	if ((*stock)[len] == '\n')
		len++;
	line = ft_substr(*stock, 0, len);
	if (!line)
		return (free(*stock), *stock = NULL, NULL);
	if (!(*stock)[len])
	{
		free(*stock);
		*stock = NULL;
		return (line);
	}
	n_stock = ft_strdup(*stock + len);
	free (*stock);
	*stock = n_stock;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, line);
	if (!line || !*line)
		return (free(line), line = NULL, NULL);
	buf = get_line(&line);
	return (buf);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*buff;

// 	buff = 0;
// 	fd = open("./a.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	while ((buff = get_next_line(fd)) != NULL)
// 	{
// 		printf("GNL:%s",buff);
// 		free(buff);
// 	}
// 	close(fd);
// 	return (0);
// }