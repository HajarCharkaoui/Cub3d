/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:53:45 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/13 20:12:24 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_path(char *path, t_config *conf)
{
	int	i;

	i = skip_whitespaces(path);
	if (ft_strncmp(path + i, "NO ", 3) == 0)
		conf->NO_PATH = ft_strtrim(path + i + 3, "\n");
	else if (ft_strncmp(path + i, "SO ", 3) == 0)
		conf->SO_PATH = ft_strtrim(path + i + 3, "\n");
	else if (ft_strncmp(path + i, "WE ", 3) == 0)
		conf->WE_PATH = ft_strtrim(path + i + 3, "\n");
	else if (ft_strncmp(path + i, "EA ", 3) == 0)
		conf->EA_PATH = ft_strtrim(path + i + 3, "\n");
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
void	set_map(t_list *map_list, t_config *conf)
{
	int		size;
	t_list	*tmp;
	int		i;

	size = ft_lstsize(map_list);
	tmp = map_list;
	conf->map = malloc(sizeof(char *) * (size + 1));
	if (!conf->map)
		return (error("Malloc failed"));
	i = 0;
	while (tmp)
	{
		conf->map[i++] = ft_strdup(tmp->line);
		tmp = tmp->next;
	}
	conf->map[i] = NULL;
	free_list(map_list);
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
		return (-1);
	set_map(map, config);
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
