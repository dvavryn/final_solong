/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:47:19 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/25 01:01:11 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	get_textures(t_data **env)
{
	int	i;
	int	j;

	(*env)->textures[0] = mlx_xpm_file_to_image
		((*env)->mlx, "xpm/bg.xpm", &i, &j);
	(*env)->textures[1] = mlx_xpm_file_to_image
		((*env)->mlx, "xpm/collect.xpm", &i, &j);
	(*env)->textures[2] = mlx_xpm_file_to_image
		((*env)->mlx, "xpm/exit.xpm", &i, &j);
	(*env)->textures[3] = mlx_xpm_file_to_image
		((*env)->mlx, "xpm/player.xpm", &i, &j);
	(*env)->textures[4] = mlx_xpm_file_to_image
		((*env)->mlx, "xpm/wall.xpm", &i, &j);
}

size_t	get_height(char **map)
{
	ssize_t	i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

void	init_env(t_data **env, int argc, char *path)
{
	char	**map;

	if (argc != 2)
		error_exit("Wrong usage: ./solong <map>.ber");
	*env = malloc(sizeof(t_data));
	if (!*env)
		exit(1);
	map = get_map(path);
	// closer(env, 1);
	// (*env)->mlx = mlx_init();
	// if (!(*env)->mlx || !map)
	// 	closer(env, 1);
	// (*env)->win = mlx_new_window
		// ((*env)->mlx, ft_strlen(map[0]) * 32, get_height(map) * 32, "so-long");
	// if (!(*env)->win)
	// 	closer(env, 1);
	(*env)->map = map;
	// get_textures(env);
}

void	free_textures(t_data **env)
{
	if ((*env)->textures[0])
		mlx_destroy_image((*env)->mlx, (*env)->textures[0]);
	if ((*env)->textures[1])
		mlx_destroy_image((*env)->mlx, (*env)->textures[1]);
	if ((*env)->textures[2])
		mlx_destroy_image((*env)->mlx, (*env)->textures[2]);
	if ((*env)->textures[3])
		mlx_destroy_image((*env)->mlx, (*env)->textures[3]);
	if ((*env)->textures[4])
		mlx_destroy_image((*env)->mlx, (*env)->textures[4]);
}

void	free_env(t_data **env)
{
	free_textures(env);
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
