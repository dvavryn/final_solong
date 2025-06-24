/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:52:16 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/25 00:51:39 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	error_exit(char *msg)
{
	write(2, "ERROR\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit (1);
}

void	move_get_pos(t_ffill *pos, char **map)
{
	pos->i = 0;
	while (map[pos->i])
	{
		pos->j = 0;
		while (map[pos->i][pos->j])
		{
			if (map[pos->i][pos->j] == 'P')
				return ;
			pos->j++;
		}
		pos->i++;
	}
}

size_t	get_count(char c, char **map)
{
	size_t	out;
	ssize_t	i;
	ssize_t	j;

	out = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
				out++;
		}
	}
	return (out);
}

void	ft_perror_map(char *s)
{
	write(2, "ERROR\n", 6);
	write(2, "Invalid map: ", 13);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
}

void	ft_perror_file(char *s)
{
	write(2, "ERROR\n", 6);
	write(2, "Invalid File: ", 14);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
}