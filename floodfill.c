/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:11:46 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/25 00:28:40 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	fill(char **arr, t_ffill start, t_ffill max)
{
	int	to_place;
	int	wall;

	to_place = 'X';
	wall = '1';
	if (start.i < 0 || start.i > max.i || start.j < 0 || start.j > max.j)
		return ;
	if (arr[start.i][start.j] == to_place || arr[start.i][start.j] == wall)
		return ;
	arr[start.i][start.j] = to_place;
	start.i -= 1;
	fill(arr, start, max);
	start.i += 2;
	fill(arr, start, max);
	start.i -= 1;
	start.j -= 1;
	fill(arr, start, max);
	start.j += 2;
	fill(arr, start, max);
}

t_ffill	get_pos(char c, char **copy)
{
	t_ffill	out;

	out.i = 0;
	while (copy[out.i])
	{
		out.j = 0;
		while (copy[out.i][out.j])
		{
			if (copy[out.i][out.j] == c && c != 0)
				return (out);
			out.j++;
		}
		out.i++;
	}
	return (out);
}

int	floodfill(char **copy, char **map)
{
	t_ffill	start;
	t_ffill	max;
	ssize_t	i;
	ssize_t	j;

	start = get_pos('P', copy);
	max = get_pos(0, copy);
	fill(copy, start, max);
	i = -1;
	while (copy[++i])
	{
		j = -1;
		while (copy[i][++j])
		{
			if (!(copy[i][j] == '1' || copy[i][j] == 'X'))
			{
				ft_perror_map("There is no valid path on the map!");
				return (1);
			}
		}
	}
	return (0);
}
