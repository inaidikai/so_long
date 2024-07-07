/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:46:27 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 02:38:24 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	berchk(char *y)
{
	int	i;

	i = 0;
	while (y[i])
	{
		if (y[i] != 46)
			i++;
		else
		{
			return (0);
		}
		if (y[i + 1] == 'b')
		{
			if (y[i + 2] == 'e')
			{
				if (y[i + 3] == 'r')
				{
					if (y[i + 4] == '\0')
						return (1);
				}
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (berchk(argv[1]) == 1)
		{
			so_long(argv[1]);
		}
		else
			ft_printf("Error : Wrong Map extention..!");
	}
	return (0);
}
