/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:53:45 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/03 16:20:32 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_path(char *path, t_config *conf)
{
	if (ft_strncmp(path, "NO ", 3) == 0)
		conf->NO_PATH = ft_strtrim(path + 3, "\n");
	else if (ft_strncmp(path, "SO ", 3) == 0)
		conf->SO_PATH = ft_strtrim(path + 3, "\n");
	else if (ft_strncmp(path, "WE ", 3) == 0)
		conf->WE_PATH = ft_strtrim(path + 3, "\n");
	else if (ft_strncmp(path, "EA ", 3) == 0)
		conf->EA_PATH = ft_strtrim(path + 3, "\n");
}

int	valide_line(t_list **tmp)
{
	int		i;
	char	*new_line;

	i = 0;
	while ((*tmp)->line[i] && ((*tmp)->line[i]  == ' ' || ((*tmp)->line[i]  >= 9 && (*tmp)->line[i]  <= 13)))
		i++;
	new_line = ft_substr((*tmp)->line, i, ft_strlen((*tmp)->line) - i);
	if (!new_line || ft_strncmp(new_line, "\0", 1) == 0)
	{
		if (new_line)
			free(new_line);
		return (0);
	}
	free((*tmp)->line);
	(*tmp)->line = new_line;
	if (is_map((*tmp)->line) && !(*tmp)->prev)
		return (write(2, "Error: map is on the top of file\n", 34), 0);
	return (1);
}

int	parsing(char *file_name, t_config *config)
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
	if (parse_file(fd, config) == -1)
		return (-1);
	return (0);
}
void	ll()
{
	system("leaks cub3D");
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
	free_config(game_Conf);
	free(game_Conf);
	return (0);
}
