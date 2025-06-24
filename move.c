/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 22:37:01 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/25 00:14:55 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	move_w(unsigned int *moves, t_ffill pos, char **map)
{
	if (pos.i > 1 && map[pos.i - 1][pos.j] != '1')
	{
		if (map[pos.i - 1][pos.j] == 'E' && get_count('C', map))
			return ;
		map[pos.i][pos.j] = '0';
		map[pos.i - 1][pos.j] = 'P';
		(*moves)++;
		ft_printf("Moves: %u\n", *moves);
	}
}

static void	move_a(unsigned int *moves, t_ffill pos, char **map)
{
	if (pos.j > 1 && map[pos.i][pos.j - 1] != '1')
	{
		if (map[pos.i][pos.j - 1] == 'E' && get_count('C', map))
			return ;
		map[pos.i][pos.j] = '0';
		map[pos.i][pos.j - 1] = 'P';
		(*moves)++;
		ft_printf("Moves: %u\n", *moves);
	}
}

static void	move_s(unsigned int *moves, t_ffill pos, char **map)
{
	if (map[pos.i + 1] && map[pos.i + 1][pos.j] != '1')
	{
		if (map[pos.i + 1][pos.j] == 'E' && get_count('C', map))
			return ;
		map[pos.i][pos.j] = '0';
		map[pos.i + 1][pos.j] = 'P';
		(*moves)++;
		ft_printf("Moves: %u\n", *moves);
	}
}

static void	move_d(unsigned int *moves, t_ffill pos, char **map)
{
	if (map[pos.i][pos.j + 1] && map[pos.i][pos.j + 1] != '1')
	{
		if (map[pos.i][pos.j + 1] == 'E' && get_count('C', map))
			return ;
		map[pos.i][pos.j] = '0';
		map[pos.i][pos.j + 1] = 'P';
		(*moves)++;
		ft_printf("Moves: %u\n", *moves);
	}
}


void	move(int key, char **map)
{
	t_ffill	pos;
	size_t	max;
	static unsigned int	moves = 0;

	move_get_pos(&pos, map);
	if (key == 'w')
	{
		move_w(&moves, pos, map);
	}
	if (key == 'a')
	{
		move_a(&moves, pos, map);

	}
	if (key == 's')
	{
		move_s(&moves, pos, map);

	}
	if (key == 'd')
	{
		move_d(&moves, pos, map);

	}
}
