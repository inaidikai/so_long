/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:00:45 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 02:10:10 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	*load(t_map *map, char *a)
{
	void	*result;
	int		width;
	int		height;

	width = 128;
	height = 128;
	result = mlx_xpm_file_to_image(map->mlx, a, &width, &height);
	if (height == 0 || width == 0)
	{
		perror("img");
		exit(EXIT_FAILURE);
	}
	return (result);
}

void	intimg(t_map *map)
{
	map->player = load(map, "image/player.xpm");
	map->collect = load(map, "image/collect.xpm");
	map->road = load(map, "image/road.xpm");
	map->wall = load(map, "image/wall.xpm");
	map->exit = load(map, "image/exit.xpm");
}

static int	program_close(t_map *map)
{
	int	i;

	write(1, "\033[0;34mExit program!\033[0\n", 24);
	i = 0;
	while (i < map->length)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	exit(EXIT_SUCCESS);
}

void	so_long(char *file)
{
	t_map	map;
	int		width;
	int		height;

	init_map(&map);
	mapy(&map, file);
	map.mlx = mlx_init();
	width = map.width * 128;
	height = map.length * 128;
	map.win = mlx_new_window(map.mlx, width, height, "so_long");
	intimg(&map);
	paint(&map, -1, -1);
	mlx_hook(map.win, X_EVENT_KEY_PRESS, X_NO_EVENT_MASK, &key_press, &map);
	mlx_hook(
		map.win, X_EVENT_DESTROY_NOTIFY, X_NO_EVENT_MASK, &program_close, &map);
	mlx_loop(map.mlx);
	mlx_clear_window(map.mlx, map.win);
	free_map(map.map);
}
