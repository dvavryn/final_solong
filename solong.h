/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:50:56 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/25 20:22:26 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

// # include "mlx/mlx.h"
# include <mlx.h>
# include "libft/libft.h"
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
	char	**map;
	void	*mlx;
	void	*win;
	void	*textures[5];
	size_t	width;
	size_t	height;
	int		i;
	int		j;
}	t_data;

typedef struct s_ffill
{
	ssize_t	i;
	ssize_t	j;
}	t_ffill;

void	init_env(t_data **env, int argc, char *path);
void	free_env(t_data **env);
int		closer(t_data **env, int status);
int		keyhandler(int key, t_data **env);
void	hooks(t_data **env);
int		floodfill(char **copy);
void	error_exit(char *msg);
char	**get_map(char *filename);
void	move(int key, char **map);
int		check_file(char *filename);
char	**copy_split(char **split);
void	move_get_pos(t_ffill *pos, char **map);
size_t	get_count(char c, char **map);
void	ft_perror_map(char *s);
void	ft_perror_file(char *s);
int		check_map_size_shape(char **map);
int		check_map_walls_chars(char **map);
int		check_map_entity_count(char **map);
int		check_map_accessibility(char **map);

#endif