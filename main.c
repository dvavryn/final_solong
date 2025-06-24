/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:52:35 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/24 19:27:32 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int main(int argc, char **argv)
{
	t_data	*env;

	init_env(&env, argc, argv[1]);
	
	ssize_t	i = -1;
	while (env->map[++i])
		ft_printf("%s\n", env->map[i]);
		
	hooks(&env);
	// funcheck(&env);
	mlx_loop(env->mlx);
}
