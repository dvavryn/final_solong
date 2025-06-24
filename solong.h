/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:50:56 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/24 18:34:16 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "mlx/mlx.h"
// # include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define BUF_SIZE	16

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*textures[5];
}	t_data;

typedef struct s_ffill
{
	size_t	i;
	size_t	j;
}	t_ffill;

// only for funcheck purposes
void	funcheck(t_data **env);

void	init_env(t_data **env);
void	free_env(t_data **env);

int	closer(t_data **env, int status);
int	keyhandler(int key, t_data **env);
void	hooks(t_data **env);

void	floodfill(char **copy, char **map);
void	error_exit(char *msg);

#endif