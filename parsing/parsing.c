/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:53:45 by hacharka          #+#    #+#             */
/*   Updated: 2025/10/31 17:49:30 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_color(char *str)
{
	if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
		return (1);
	return (0);
}
int	is_deriction(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
			|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
			return (1);
	return (0);
}
int	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' || str[i] != '1' || str[i] != ' ' || str[i] != 'N'
			|| str[i] != 'E' || str[i] != 'S' || str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}
void	free_args(char **strs)
{
	int	i;

	i = 0;
	while(strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
void	free_config(t_config *config)
{
	if (config)
	{
		if (config->NO_PATH)
			free(config->NO_PATH);
		if (config->SO_PATH)
			free(config->SO_PATH);
		if (config->WE_PATH)
			free(config->WE_PATH);
		if (config->EA_PATH)
			free(config->EA_PATH);
		// also free your map, textures, etc.

	}

}
int	valide_color(char **RGB)
{
	int	i;
	int	j;

	if (RGB[3])
		return (0);
	i = 0;
	while (RGB[i])
	{
		j = 0;
		while (RGB[i][j])
		{
			if (RGB[i][j] < '0' || RGB[i][j] > '9')
				return (0);
			j++;
		}
		if (j > 3 || (RGB[i][0] == '0' && RGB[i][1])
			|| (ft_atoi(RGB[i]) < 0
				|| ft_atoi(RGB[i]) > 256))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	set_color(char *str, t_config *conf)
{
	int		color;
	char	**RGB;
	char	*blue;
	int		floor;

	if (ft_strncmp(str, "F ", 2) == 0)
		floor = 1;
	RGB = ft_split(str + 2, ',');
	if (!RGB)
		return (-1);
	if (RGB[2] && ft_strchr(RGB[2], '\n'))
	{
		blue = ft_strtrim(RGB[2], "\n");
		free(RGB[2]);
		RGB[2] = blue;
	}
	if (!valide_color(RGB))
		return (free_args(RGB), -1);
	color = (ft_atoi(RGB[0]) << 16) + (ft_atoi(RGB[1]) << 8) + ft_atoi(RGB[2]);
	free_args(RGB);
	if (floor == 1)
		conf->floor_color = color;
	else
		conf->ceiling_color = color;
	return (0);
}
void	init_config(t_config *config)
{
	config->NO_PATH = NULL;
	config->SO_PATH = NULL;
	config->WE_PATH = NULL;
	config->EA_PATH = NULL;
	config->ceiling_color = -1;
	config->floor_color = -1;
	config->map = NULL;
}
void	set_path(char *path, t_config *conf)
{
	if (ft_strncmp(path, "NO ", 3) == 0)
		conf->NO_PATH = ft_strtrim(path + 3, "\n");
	else if (ft_strncmp(path, " SO ", 3) == 0)
		conf->SO_PATH = ft_strtrim(path + 3, "\n");
	else if (ft_strncmp(path, " WE ", 3) == 0)
		conf->WE_PATH = ft_strtrim(path + 3, "\n");
	else if (ft_strncmp(path, " EA ", 3) == 0)
		conf->EA_PATH = ft_strtrim(path + 3, "\n");
}
int	valide_line(char *line, t_config *conf)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	new_line = ft_substr(line, i, ft_strlen(line) - i);
	if (!new_line || ft_strncmp(new_line, "\0", 1) == 0)
	{
		if (new_line)
			free(new_line);
		return (0);
	}
	if (is_deriction(new_line))
		set_path(new_line + 3, conf);
	else if (is_color(new_line))
		set_color(new_line, conf);
	// else if (is_map(new_line))
	// 	set_map(new_line, conf);
	return (1);
}
int	put_data(int fd, t_config *config)
{
	char		*line;
	char		**file_content;
	char		**tmp;
	int			i;

	(void)config;
	i= 0;
	file_content = NULL;
	while ((line = get_next_line(fd)))
	{
		tmp = (char **)realloc(file_content, (i + 2) * sizeof(char *));
		if (!tmp)
			return (perror("realloc"), free(line), close(fd), 0);
		file_content = tmp;
		file_content[i] = ft_strdup(line);
		if (!file_content[i])
			return (perror("malloc"), free(line), close(fd), 0);
		i++;
		free(line);
	}
	file_content[i] = NULL;
	close(fd);
	for (int i = 0; file_content[i]; i++)
		printf("%s", file_content[i]);
	exit(0);
	return (1);
}
int	parse_file(char *file_name, t_config *config)
{
	int	len;
	int	fd;

	init_config(config);
	len = ft_strlen(file_name);
	if (ft_strncmp(file_name + (len - 4), ".cub", 4) != 0)
		return(write(2, "Error: Map file must have a .cub extension\n", 44), -1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), -1);
	if (!put_data(fd, config))
		return (-1);
	return (0);
}
int	main(int ac, char **av)
{
	t_config	*game_Conf;

	if (ac != 2)
		return (1);
	game_Conf = malloc(sizeof(t_config));
	if (!game_Conf)
		return (1);
	if (parse_file(av[1], game_Conf) == -1)
		return (free_config(game_Conf), free(game_Conf), 1);
	printf("NO Path: %s\n", game_Conf->NO_PATH);
	printf("SO Path: %s\n", game_Conf->SO_PATH);
	printf("WE Path: %s\n", game_Conf->WE_PATH);
	printf("EA Path: %s\n", game_Conf->EA_PATH);
	printf("F color: %d\n", game_Conf->floor_color);
	printf("C color: %d\n", game_Conf->ceiling_color);
	free_config(game_Conf);
	free(game_Conf);
	return (0);
}
