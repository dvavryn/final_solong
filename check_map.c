/* ************************************************************************** */
/*                                                                            */
/*                                                               */
/*   check_map.c                                                  */
/*                                                    + +         +     */
/*   Bydvavryn <dvavryn@student.42vienna.com>     +#+  +       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created2025/06/24 2337 by dvavryn           #+#    #+#             */
/*   Updated2025/06/25 0067 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
static int	check_map_size_shape(char **map);
static int	check_map_walls_chars(char **map);
static int	check_map_entity_count(char **map);
static int	check_map_accessibility(char **map);

int	check_map(char **map)
{
	if (check_map_size_shape(map))
		return (1);
	if (check_map_walls_chars(map))
		return (1);
	if (check_map_entity_count(map))
		return (1);
	if (check_map_accessibility(map))
		return (1);
	return (0);
}

static int	check_map_accessibility(char **map)
{
	char	**copy;
	int		out;

	copy = copy_split(map);
	if (!copy)
		return (1);
	out = 0;
	out = floodfill(copy, map);
	free_split(copy);
	return (out);
}

static int	check_map_size_shape(char **map)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = ft_strlen(map[0]);
	while (map[i])
	{
		if (j != ft_strlen(map[i]))
		{
			ft_perror_map("Map is not rectangular!");
			return (1);
		}
		i++;
	}
	if (i < 3 || j < 3 || (i == 3 && j < 5) || (i < 5 && j == 3)
		|| (i == 4 && j < 4) || i < 4 && j == 4)
	{
		ft_perror_map("Map does not have the minimum size!");
		return (1);
	}
	return (0);
}

static int	check_map_walls_chars(char **map)
{
	ssize_t	i;
	ssize_t	j;
	char	c;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			c = map[i][j];
			if (!(c == '0' || c == '1' || c == 'E' || c == 'C' || c == 'P'))
			{
				ft_perror_map("Invalid character found in map!");
				return (1);
			}
			if ((i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1]) && c != '1')
			{
				ft_perror_map("Map is not enclosed by walls!");
				return (1);
			}
		}
	}
	return (0);
}

static int	check_map_entity_count_sub(int c, int e, int p, char **map)
{
	if (c > 0 && e == 1 && p == 1)
		return (0);
	if (c < 1)
		ft_perror_map("Not enough Collectibles on the map!");
	if (e < 1)
		ft_perror_map("There must be at least one exit!");
	if (e > 1)
		ft_perror_map("There can only be one exit!");
	if (p < 1)
		ft_perror_map("There must be at least one starting position!");
	if (p > 1)
		ft_perror_map("There can only be one starting position!");
	return (1);
}

static int	check_map_entity_count(char **map)
{
	size_t			i;
	size_t			j;
	unsigned int	count[3];

	i = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count[0]++;
			if (map[i][j] == 'E')
				count[1]++;
			if (map[i][j] == 'P')
				count[2]++;
			j++;
		}
		i++;
	}
	return (check_map_entity_count_sub(count[0], count[1], count[2], map));
}

