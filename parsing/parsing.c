/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:53:45 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/15 17:24:07 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_path(char *path, t_config *conf)
{
	if (ft_strncmp(path, "NO ", 3) == 0 && conf->NO_PATH)
		conf->NO_PATH = ft_strtrim(path + 3, "\n");
	else if (ft_strncmp(path, "SO ", 3) == 0 && conf->SO_PATH)
		conf->SO_PATH = ft_strtrim(path + 3, "\n");
	else if (ft_strncmp(path, "WE ", 3) == 0 && conf->WE_PATH)
		conf->WE_PATH = ft_strtrim(path + 3, "\n");
	else if (ft_strncmp(path, "EA ", 3) == 0 && conf->EA_PATH)
		conf->EA_PATH = ft_strtrim(path + 3, "\n");
	else
		return ;
}

int	skip_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i]  == ' ' 
		|| (str[i]  >= 9 && str[i]  <= 13)))
		i++;
	return (i);
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
		return(write(2, "Error: Map file must have a .cub extension\n", 44), -1);
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
	if (set_player_pos(config) == -1 || !valide_map(config->map))
		return (-1);
	return (0);
}

void	ll()
{
	system("leaks -q cub3D");
}
int	main(int ac, char **av)
{
	t_config	*game_Conf;

	atexit(ll);
	if (ac != 2)
		return (1);
	game_Conf = malloc(sizeof(t_config));
	if (!game_Conf)
		return (1);
	if (parsing(av[1], game_Conf) == -1)
		return (free_config(game_Conf), free(game_Conf), 1);
	printf("NO Path: %s\n", game_Conf->NO_PATH);
	printf("SO Path: %s\n", game_Conf->SO_PATH);
	printf("WE Path: %s\n", game_Conf->WE_PATH);
	printf("EA Path: %s\n", game_Conf->EA_PATH);
	printf("F color: %d\n", game_Conf->floor_color);
	printf("C color: %d\n", game_Conf->ceiling_color);
	printf("--------------------------------------------\n");
	if (!game_Conf->map)
		printf("NULL\n");
	else
		{for (int i = 0; game_Conf->map[i]; i++)
			printf("%s", game_Conf->map[i]);
		printf("\n--------------------------------------------\n");}
	free_config(game_Conf);
	free(game_Conf);
	return (0);
}
