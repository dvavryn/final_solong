/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:52:41 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/25 12:40:03 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	check_file_existing(char *filename);
static int	check_file_type(char *filename);
static int	check_file_empty(int fd);

int	check_file(char *filename)
{
	int	fd;

	if (check_file_type(filename))
		return (1);
	fd = check_file_existing(filename);
	if (fd < 0)
		return (1);
	if (check_file_empty(fd))
		return (1);
	return (0);
}

static int	check_file_existing(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_perror_file("File does not exist!");
	return (fd);
}

static int	check_file_type(char *filename)
{
	size_t	i;

	i = 0;
	while (filename[i])
		i++;
	if (ft_strcmp(&filename[i] - 4, ".ber"))
	{
		ft_perror_file("File has wrong file specificer!");
		return (1);
	}
	return (0);
}

static int	check_file_empty(int fd)
{
	size_t	b;
	char	buf[10];

	b = read(fd, buf, 10);
	close(fd);
	if (b < 0)
		return (1);
	if (b == 0)
	{
		ft_perror_file("File is empty!");
		return (1);
	}
	return (0);
}
