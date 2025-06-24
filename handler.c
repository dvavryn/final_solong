/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:45:38 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/24 12:50:43 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	closer(t_data **env, int status)
{
	free_env(env);
	exit(status);
}

int	keyhandler(int key, t_data **env)
{
	if (key == 65307 || key == ' ')
	{
		closer(env, 0);
	}
	return (0);
}

void	hooks(t_data **env)
{
	mlx_hook((*env)->win, 2, 1L << 0, keyhandler, env);
	mlx_hook((*env)->win, 17, 1L << 2, closer, env);
}