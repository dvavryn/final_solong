/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:47:19 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/27 11:54:47 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void		get_textures(t_data **env);
static size_t	get_height(char **map);
static void		init_null(t_data **env);

void	init_env(t_data **env, int argc, char *path)
{
	if (argc != 2)
		error_exit("Wrong usage: ./solong <map>.ber");
	*env = malloc(sizeof(t_data));
	if (!*env)
		exit(1);
	init_null(env);
	(*env)->map = get_map(path);
	if (!(*env)->map)
		closer(env, 4);
	(*env)->mlx = mlx_init();
	if (!(*env)->mlx || !(*env)->map)
		closer(env, 1);
	(*env)->win = mlx_new_window
		((*env)->mlx, ft_strlen((*env)->map[0]) * 32,
			get_height((*env)->map) * 32, "so-long");
	if (!(*env)->win)
		closer(env, 1);
	get_textures(env);
}

void	free_env(t_data **env)
{
	if (!env || !*env)
		return ;
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
	env = NULL;
}

static void	get_textures(t_data **env)
{
	int	i;
	int	j;

	(*env)->textures[0] = mlx_xpm_file_to_image
		((*env)->mlx, "textures/bg.xpm", &i, &j);
	(*env)->textures[1] = mlx_xpm_file_to_image
		((*env)->mlx, "textures/collect.xpm", &i, &j);
	(*env)->textures[2] = mlx_xpm_file_to_image
		((*env)->mlx, "textures/exit.xpm", &i, &j);
	(*env)->textures[3] = mlx_xpm_file_to_image
		((*env)->mlx, "textures/player.xpm", &i, &j);
	(*env)->textures[4] = mlx_xpm_file_to_image
		((*env)->mlx, "textures/wall.xpm", &i, &j);
	if (!((*env)->textures[0] && (*env)->textures[1] && (*env)->textures[2]
			&& (*env)->textures[3] && (*env)->textures[4]))
	{
		free_env(env);
		error_exit("Textures are missing!");
	}
}

static size_t	get_height(char **map)
{
	ssize_t	i;

	i = -1;
	while (map[++i])
		;
	return (i);
}

static void	init_null(t_data **env)
{
	(*env)->mlx = NULL;
	(*env)->win = NULL;
	(*env)->height = 0;
	(*env)->width = 0;
	(*env)->map = NULL;
	(*env)->i = 0;
	(*env)->j = 0;
	(*env)->textures[0] = NULL;
	(*env)->textures[1] = NULL;
	(*env)->textures[2] = NULL;
	(*env)->textures[3] = NULL;
	(*env)->textures[4] = NULL;
}
