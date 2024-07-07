/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 02:11:47 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 03:43:12 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	border(t_map *map, t_map lb)
{
	int	i;

	i = 0;
	while (i < lb.width)
	{
		if (map->map[0][i] != '1' || map->map[lb.length - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < lb.length)
	{
		if (map->map[i][0] != '1' || map->map[i][lb.width - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	noku(char map)
{
	if (map != 'P' && map != 'C' && map != '1' && map != '0' && map != 'E')
	{
		write(1, "ERROR INVALID FORMAT IN MAP\n", 29);
		return (0);
	}
	return (1);
}

int	is_valid_map_structure(t_map *map_array, t_map dimensions)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((int)i < dimensions.length)
	{
		j = 0;
		while ((int)j < dimensions.width)
		{
			if (!noku(map_array->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	numchar(size_t *p, size_t *e, size_t *c, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				(*p)++;
			else if (map->map[i][j] == 'E')
				(*e)++;
			else if (map->map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
	map->c = (*c);
}

int	charnum(t_map *map_array)
{
	size_t	exit;
	size_t	player;
	size_t	collectible;

	collectible = 0;
	player = 0;
	exit = 0;
	numchar(&player, &exit, &collectible, map_array);
	if (exit != 1 || player != 1 || collectible < 1)
	{
		write(1, "Error: 1 exit || 1 player || 1 collectibles\n", 45);
		return (0);
	}
	return (1);
}
