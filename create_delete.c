/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:47:19 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/24 19:30:56 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_env(t_data **env, int argc, char *path)
{
	char **map;

	if (argc != 2)
		error_exit("Wrong usage: ./solong <map>.ber");
	*env = malloc(sizeof(t_data));
	if (!*env)
	{
		free_split(map);
		exit(1);
	}
	(*env)->mlx = mlx_init();
	if (!(*env)->mlx)
		closer(env, 1);
	(*env)->win = mlx_new_window((*env)->mlx, WIDTH, HEIGHT, "so-long");
	if (!(*env)->win)
		closer(env, 1);
	map = get_map(path);
	if (!map)
		exit(123);
	(*env)->map = map;
}

void	free_env(t_data **env)
{
	if ((*env)->win)
		mlx_destroy_window((*env)->mlx, (*env)->win);
	if ((*env)->mlx)
	{
		mlx_destroy_display((*env)->mlx);
		free((*env)->mlx);
	}
	if ((*env)->map)
		free_split((*env)->map);
	if (*env)
		free(*env);
}
