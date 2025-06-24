/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 22:28:26 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/25 00:40:10 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static char	**get_file_data(char *filename);

char	**get_map(char *filename)
{
	char	**out;

	if (check_file(filename))
		return (NULL);
	out = get_file_data(filename);
	if (!out)
		return (NULL);
	if (check_map(out))
	{
		free_split(out);
		return (NULL);
	}
	return (out);
}

static char	*read_file(int fd)
{
	ssize_t	b;
	char	buf[BUF_SIZE];
	char	*out;
	char	*tmp;

	b = 1;
	out = ft_strdup("");
	while (b > 0)
	{
		ft_bzero(buf, BUF_SIZE);
		b = read(fd, buf, BUF_SIZE - 1);
		if (b == -1)
		{
			free(out);
			close(fd);
			return (NULL);
		}
		tmp = out;
		out = ft_strjoin(out, buf);
		free(tmp);
	}
	return (out);
}

static char	**get_file_data(char *filename)
{
	char	**out;
	char	*one_line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	one_line = read_file(fd);
	if (!one_line)
		return (NULL);
	out = ft_split(one_line, '\n');
	free(one_line);
	if (!out)
		return (NULL);
	return (out);
}


