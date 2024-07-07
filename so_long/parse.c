/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:29:36 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 02:09:25 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	exit_error(t_map *map)
{
	free_map(map->map);
	exit(EXIT_FAILURE);
}

int	parse(t_map *map_array, t_map dimensions)
{
	if (!is_valid_map_structure(map_array, dimensions))
	{
		ft_printf("wrong   struct");
		exit_error(map_array);
	}
	else if (!border(map_array, dimensions))
	{
		ft_printf("wrong   border");
		exit_error(map_array);
	}
	else if (!charnum(map_array))
	{
		exit_error(map_array);
	}
	mapbfs(map_array);
	if (map_array->valid != 1 || map_array->c != map_array->rc)
	{
		ft_printf("no path");
		exit_error(map_array);
	}
	return (1);
}
