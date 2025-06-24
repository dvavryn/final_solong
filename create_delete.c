/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:47:19 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/24 18:38:57 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_env(t_data **env)
{
	*env = malloc(sizeof(t_data));
	if (!*env)
		exit(1);
	
	(*env)->mlx = mlx_init();
	if (!(*env)->mlx)
	{
		closer(env, 1);
	}
	(*env)->win = mlx_new_window((*env)->mlx, WIDTH, HEIGHT, "so-long");
	if (!(*env)->win)
		closer(env, 1);
}

void	free_env(t_data **env)
{
	if ((*env)->win)
	{
		mlx_destroy_window((*env)->mlx, (*env)->win);
	}
	if ((*env)->mlx)
	{
		mlx_destroy_display((*env)->mlx);
		free((*env)->mlx);
	}
	if (*env)
	{
		free(*env);
	}
}
