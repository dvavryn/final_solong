/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:52:35 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/25 13:36:16 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	render_sub(ssize_t i, t_data **env)
{
	ssize_t	j;
	char	c;

	j = -1;
	while ((*env)->map[i][++j])
	{
		c = (*env)->map[i][j];
		if (c == '0')
			mlx_put_image_to_window((*env)->mlx, (*env)->win,
				(*env)->textures[0], j * 32, i * 32);
		if (c == 'C')
			mlx_put_image_to_window((*env)->mlx, (*env)->win,
				(*env)->textures[1], j * 32, i * 32);
		if (c == 'E')
			mlx_put_image_to_window((*env)->mlx, (*env)->win,
				(*env)->textures[2], j * 32, i * 32);
		if (c == 'P')
			mlx_put_image_to_window((*env)->mlx, (*env)->win,
				(*env)->textures[3], j * 32, i * 32);
		if (c == '1')
			mlx_put_image_to_window((*env)->mlx, (*env)->win,
				(*env)->textures[4], j * 32, i * 32);
	}
}

int	exited(char **map)
{
	ssize_t	i;
	ssize_t	j;
	size_t	e;
	size_t	c;

	e = 0;
	c = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'E')
				e++;
		}
	}
	if (!c && !e)
		return (1);
	return (0);
}

int	render(t_data **env)
{
	ssize_t	i;
	ssize_t	j;

	if (exited((*env)->map))
		closer(env, 0);
	i = -1;
	while ((*env)->map[++i])
	{
		render_sub(i, env);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*env;
	int		i;
	int		j;

	init_env(&env, argc, argv[1]);
	mlx_put_image_to_window(env->mlx, env->win, env->textures[0], 0, 0);
	hooks(&env);
	mlx_loop_hook(env->mlx, render, &env);
	mlx_loop(env->mlx);
}
