/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:29:55 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 01:33:59 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	player_location(t_map *map, int a, int b)
{
	if (map->map[map->pi + a][map->pj + b] == 'E' && map->rc == 0)
	{
		map->map[map->pi + a][map->pj + b] = '0';
		map->move_count++;
		write(1, "YOU WON", 8);
		exit(EXIT_SUCCESS);
	}
	else if (map->map[map->pi + a][map->pj + b] == 'E' && map->rc != 0)
		ft_printf("collect all coins\n");
	else if (map->map[map->pi + a][map->pj + b] == '1')
		ft_printf("move away from wall\n");
	else if (map->map[map->pi + a][map->pj + b] == '0' || map->map[map->pi
			+ a][map->pj + b] == 'C')
	{
		if (map->map[map->pi + a][map->pj + b] == 'C')
			map->rc--;
		map->map[map->pi + a][map->pj + b] = 'P';
		map->map[map->pi][map->pj] = '0';
		map->move_count++;
		ft_printf("Move count: %d\n", map->move_count);
		map->pi += a;
		map->pj += b;
	}
}

int	key_press(int keycode, t_map *map)
{
	playerxy(map);
	if (keycode == KEY_ESC)
	{
		write(1, "\033[0;36mYou Enter the ESC Key. Good Bye! :)\033[0m\n", 47);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		player_location(map, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		player_location(map, +1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		player_location(map, 0, +1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		player_location(map, 0, -1);
	map->y = 0;
	paint(map, -1, -1);
	return (0);
}
