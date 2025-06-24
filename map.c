#include "solong.h"

//-----------------------------------------------------------

void	error_exit(char *msg)
{
	write(2, "ERROR\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit (1);
}

//-----------------------------------------------------------

int	check_file_existing(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("File does not exist!");
	return (fd);
}

void	check_file_type(char *filename)
{
	size_t	i;

	i = 0;
	while (filename[i])
		i++;
	if (ft_strcmp(&filename[i] - 4, ".ber"))
		error_exit("File has wrong file specificer!");
}

void	check_file_empty(int fd)
{
	size_t	b;
	char	buf[10];

	b = read(fd, buf, 10);
	close(fd);
	if (b <= 0)
		error_exit("File is empty!");
}

void	check_file(char *filename)
{
	int	fd;

	check_file_type(filename);
	fd = check_file_existing(filename);
	check_file_empty(fd);
}

//-----------------------------------------------------------

char	*read_file(int fd)
{
	ssize_t	b;
	char	buf[BUF_SIZE];
	char	*out;
	char	*tmp;

	b = 1;
	out = ft_strdup("");
	while (b > 0)
	{
		ft_bzero(buf, BUF_SIZE);
		b = read(fd, buf, BUF_SIZE - 1);
		if (b == -1)
		{
			free(out);
			close(fd);
			return (NULL);
		}
		tmp = out;
		out = ft_strjoin(out, buf);
		free(tmp);
	}
	return (out);
}

char	**get_file_data(char *filename)
{
	char	**out;
	char	*one_line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	one_line = read_file(fd);
	if (!one_line)
		return (NULL);
	out = ft_split(one_line, '\n');
	free(one_line);
	if (!out)
		return (NULL);
	return (out);
}

//-----------------------------------------------------------

char	**copy_split(char **split)
{
	char **out = NULL;
	ssize_t	i;

	i = 0;
	while(split[i++]);
	out = malloc(i * sizeof(char *));
	if (!out)
	{
		free_split(split);
		exit(1);
	}
	out[i - 1] = NULL;
	i = -1;
	while (split[++i])
	{
		out[i] = ft_strdup(split[i]);
		if (!out[i])
		{
			free_split(split);
			free_split(out);
			exit(1);
		}
	}
	return (out);
}

// FLOODFILL!!!!!??????????
void	check_map_accessibility(char **map)
{
	char **copy;

	copy = copy_split(map);
	if (!copy)
	{
		free_split(map);
		exit(1);
	}
	floodfill(copy, map);
	free_split(copy);
}

//-----------------------------------------------------------

void	check_map_size_shape(char **map)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = ft_strlen(map[0]);
	while (map[i])
	{
		if (j != ft_strlen(map[i]))
		{
			free_split(map);
			error_exit("Invalid map: Map is not rectangular!");
		}
		i++;
	}
	if (i < 3 || j < 3 || (i == 3 && j < 5) || (i < 5 && j == 3)
		|| (i == 4 && j < 4) || i < 4 && j == 4)
	{
		free_split(map);
		error_exit("Invalid map: Map does not have the minimum size!");
	}
}

void	check_map_walls_chars(char **map)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (!(c =='0' || c == '1' || c == 'E' || c == 'C' || c == 'P'))
			{
				free_split(map);
				error_exit("Invalid map: Invalid character found in map!");
			}
			if ((i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1]) && c != '1')
			{
				free_split(map);
				error_exit("Invalid map: Map is not enclosed by walls!");
			}
			j++;
		}
		i++;
	}
}

void	check_map_entity_count_sub(int c, int e, int p, char **map)
{
	if (c < 1 || e != 1 || p != 1)
		free_split(map);
	if (c < 1)
		error_exit("Invalid map: Not enough Collectibles on the map!");
	if (e < 1)
		error_exit("Invalid map: There must be at least one exit!");
	if (e > 1)
		error_exit("Invalid map: There can only be one exit!");
	if (p < 1)
		error_exit("Invalid map: There must be at least one starting position!");
	if (p > 1)
		error_exit("Invalid map: There can only be one starting position!");
}

void	check_map_entity_count(char **map)
{
	size_t	i;
	size_t	j;
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
	check_map_entity_count_sub(count[0], count[1], count[2], map);
}

void	check_map(char **map)
{
	check_map_size_shape(map);
	check_map_walls_chars(map);
	check_map_entity_count(map);
	check_map_accessibility(map);
}

//-----------------------------------------------------------

char	**get_map(char *filename)
{
	char	**out;

	check_file(filename);
	out = get_file_data(filename);
	if (!out)
		return (NULL);
	check_map(out);
	return (out);
}

int	main(void)
{
	char	**map;
	ssize_t	i;

	map = get_map("map/map.ber");
	if (!map)
		return (-1);
	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
	free_split(map);
	return (0);
}
