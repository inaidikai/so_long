/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:29:03 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 02:20:25 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	playerxy(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->pi = i;
				map->pj = j;
				return ;
			}
			j++;
		}
	}
}

static void	pain(t_map *map, int i, int j)
{
	if (map->map[i][j] == '0' || map->map[i][j] == 'P' || map->map[i][j] == 'C' \
			|| map->map[i][j] == '1' || map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, \
								map->win, map->road, map->x, map->y);
}

void	paint(t_map *map, int i, int j)
{
	while (map->map[++i])
	{
		j = -1;
		map->x = 0;
		while (map->map[i][++j])
		{
			pain(map, i, j);
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, \
					map->win, map->wall, map->x, map->y);
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(\
				map->mlx, map->win, map->player, map->x, map->y);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(\
				map->mlx, map->win, map->collect, map->x, map->y);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(\
				map->mlx, map->win, map->exit, map->x, map->y);
			map->x += 128;
		}
		map->y += 128;
	}
}

int	img_put(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			mlx_put_image_to_window(map->mlx, map->win, map->wall,
				map->img_width * j, map->img_height * i);
		}
		i++;
	}
	return (0);
}

void	init_map(t_map *map)
{
	map->img_width = 128;
	map->img_height = 128;
	map->wall = "image/wall.xpm";
	map->road = "image/road.xpm";
	map->exit = "image/exit.xpm";
	map->collect = "image/collect.xpm";
	map->player = "image/player.xpm";
	map->move_count = 0;
	map->y = 0;
	map->rc = 0;
	map->valid = 0;
	map->visited = NULL;
	map->length = 0;
	map->width = 0;
	map->x = 0;
	map->y = 0;
	map->w = 0;
	map->p = 0;
	map->c = 0;
	map->e = 0;
	map->x = 0;
	map->pi = 0;
	map->pj = 0;
	map->mlx = NULL;
	map->win = NULL;
}
