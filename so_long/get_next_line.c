/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:00:25 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 01:33:25 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_remaining(int fd, char *remaining)
{
	int		read_bytes;
	char	*buffer;
	char	*temp;	

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(remaining, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buffer);
			if (read_bytes == 0)
				return (remaining);
			free(remaining);
			return (0);
		}
		buffer[read_bytes] = '\0';
		temp = remaining;
		remaining = ft_strjoin(remaining, buffer);
		free(temp);
	}
	return (free(buffer), remaining);
}

char	*assign_to_return_line(char *remaining)
{
	int		i;
	char	*line;

	i = 0;
	while (remaining[i] && remaining[i] != '\n')
		i++;
	if (remaining[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (remaining[i] != '\n' && remaining[i])
	{
		line[i] = remaining[i];
		i++;
	}
	if (remaining[i] == '\n')
	{
		line[i] = remaining[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*clear_stuffs_from_remaining(char *remaining)
{
	int		i;
	int		j;
	char	*new_remaining;

	i = 0;
	while (remaining[i] && remaining[i] != '\n')
		i++;
	if (remaining[i] == '\n')
		i++;
	if (!remaining[i] || !remaining)
	{
		free(remaining);
		return (NULL);
	}
	new_remaining = malloc(ft_strlen(remaining) - i + 1);
	if (!new_remaining)
	{
		free(remaining);
		return (NULL);
	}
	j = 0;
	while (remaining[i])
		new_remaining[j++] = remaining[i++];
	new_remaining[j] = '\0';
	return (free(remaining), new_remaining);
}

static char	*finalize_the_output_for_so_long(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*return_line;
	char		*finalize;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (0);
	remaining = read_to_remaining(fd, remaining);
	if (!remaining)
		return (NULL);
	return_line = assign_to_return_line(remaining);
	finalize = finalize_the_output_for_so_long(return_line);
	remaining = clear_stuffs_from_remaining(remaining);
	return (finalize);
}
