/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:44:33 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/24 12:44:33 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int waitin(t_data **env)
{
	static int i = 0;
	i++;
	if (i == 4000)
		closer(env, 0);
	return (0);
}

void	funcheck(t_data **env)
{
	mlx_loop_hook((*env)->mlx, waitin, env);
}