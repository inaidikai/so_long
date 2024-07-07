/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapstore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:22:08 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 03:53:17 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	map_error(void)
{
	write(1, "Error\nInvalid Map\n", 18);
	exit(EXIT_FAILURE);
}

static int	fixer(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	size_t	width;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		map_error();
	line = get_next_line(fd);
	width = ft_strlen(line);
	height = 0;
	while (line)
	{
		if (width != ft_strlen(line))
		{
			free(line);
			map_error();
		}
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	map->length = height;
	return (width);
}

void	mapy(t_map *map, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	map->width = fixer(map, filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		map_error();
	map->map = (char **)malloc(sizeof(char *) * map->width);
	if (map->map == NULL)
	{
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
	parse(map, *map);
}
