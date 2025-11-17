/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:53:45 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/17 20:32:12 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	skip_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' 
			|| (str[i] >= 9 && str[i] <= 13)))
		i++;
	return (i);
}

char	**duplicate_map(char **src)
{
	char	**dst;
	int		size;
	int		i;

	size = 0;
	while (src[size])
		size++;
	dst = (char **)malloc (sizeof(char *) * (size + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

int	flood_fill(char **map, int y, int x)
{
	if (y < 0 || x < 0)
		return (-1);
	if (!map[y] || x >= (int)ft_strlen(map[y]))
		return (-1);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (-1);
	if (map[y][x] == 'F' || map[y][x] == '1')
		return (0);
	map[y][x] = 'F';
	if (flood_fill(map, y, x + 1) == -1)
		return (-1);
	if (flood_fill(map, y, x - 1) == -1)
		return (-1);
	if (flood_fill(map, y - 1, x) == -1)
		return (-1);
	if (flood_fill(map, y + 1, x) == -1)
		return (-1);
	return (0);
}

int	valide_map(t_config *conf)
{
	char	**tmp_map;
	int		i;
	int		j;

	tmp_map = duplicate_map(conf->map);
	i = 0;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (tmp_map[i][j] == '0')
			{
				if (flood_fill(tmp_map, i, j) == -1)
					return (error("Error: Map is open"), free_args(tmp_map), 0);
				else
					break ;
			}
			j++;
		}
		i++;
	}
	free_args(tmp_map);
	return (1);
}

int	parsing(char *file_name, t_config *config)
{
	int		len;
	int		fd;
	t_list	*map;

	map = NULL;
	init_config(config);
	len = ft_strlen(file_name);
	if (ft_strncmp(file_name + (len - 4), ".cub", 4) != 0)
		return (write(2, "Error: Map file must have a .cub extension\n", 44),
			-1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), -1);
	if (read_lines(fd, &map, config) == -1 || check_settings(config) == -1)
	{
		if (map)
			free_list(map);
		return (-1);
	}
	set_map(map, config);
	if (!valide_map(config) || set_player_pos(config) == -1)
		return (-1);
	return (0);
}
