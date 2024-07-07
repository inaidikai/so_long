/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapbfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:06:16 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 01:55:57 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isv(t_stack *s, int x, int y)
{
	while ((s)->next != NULL)
	{
		if ((s)->i == x && (s)->j == y)
			return (1);
		(s) = (s)->next;
	}
	return (0);
}

t_stack	*create_node(t_stack **stack, int i, int j)
{
	t_stack	*cnode;

	cnode = (t_stack *)malloc(sizeof(t_stack));
	cnode->i = i;
	cnode->j = j;
	if (stack == NULL)
	{
		stack = &cnode;
		(*stack)->next = NULL;
	}
	else
	{
		cnode->next = *stack;
		*stack = cnode;
	}
	return (*stack);
}

void	check_path(t_map *map, int i, int j, t_stack **visited)
{
	char	**arr;

	arr = map->map;
	*visited = create_node(visited, i, j);
	if (arr[i][j] == 'E')
	{
		map->valid = 1;
		return ;
	}
	if (arr[i][j] == 'C')
		map->rc++;
	if (arr[i + 1][j] != '1' && (isv(*visited, i + 1, j) == 0))
		check_path(map, i + 1, j, visited);
	if (arr[i - 1][j] != '1' && (isv(*visited, i - 1, j) == 0))
		check_path(map, i - 1, j, visited);
	if (arr[i][j + 1] != '1' && (isv(*visited, i, j + 1) == 0))
		check_path(map, i, j + 1, visited);
	if (arr[i][j - 1] != '1' && (isv(*visited, i, j - 1) == 0))
		check_path(map, i, j - 1, visited);
}

void	mapbfs(t_map *map)
{
	int		i;
	int		j;
	t_stack	*visited;

	visited = map->visited;
	i = 1;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				break ;
			}
			j++;
		}
		if (map->map[i][j] == 'P')
		{
			visited = create_node(&visited, i, j);
			break ;
		}
		i++;
	}
	check_path(map, i, j, &visited);
}
