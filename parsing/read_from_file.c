/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:46:30 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/13 19:48:18 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	save_settings(char *element, t_config *conf, int map_start)
{
	if (map_start)
	{
		if (conf->setting_count == 0)
			error("Error: Map start befor settings");
		else
			error("Error: Map start inside settings");
		free(element);
		return (-1);
	}
	if (is_deriction(element))
		set_path(element, conf);
	else if (is_color(element))
		set_color(element, conf);
	conf->setting_count ++;
	free(element);
	return (0);
}

void	save_map(t_list **map_list, char *data)
{
	t_list	*new_node;

	new_node = node(data);
	if (!new_node)
	{
		free_list(*map_list);
		free(data);
		return ;
	}
	ft_lstadd_back(map_list, new_node);
}
int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

int	process_lines(t_list **map, t_config *conf, char *line, int *map_start)
{
	if (empty_line(line))
	{
		if (*map_start)
		{
			if (conf->setting_count == 0)
				return (free(line), error("Error: Map start befor settings"), -1);
			else if (conf->setting_count > 0 && conf->setting_count < 6)
				return (free(line), error("Error: Map start inside settings"), -1);
			else
				return (free(line), error("Error: Empty lines in/after the map"), -1);
		}
		return (0);
	}
	else if (is_deriction(line) || is_color(line))
		return (save_settings(line, conf, *map_start));
	else if (is_map(line))
	{
		save_map(map, line);
		*map_start = 1;
		free(line);
		return (0);
	}
	else
		return (free(line), error("Error: Invalide line"), -1);
}

int	read_lines(int fd, t_list **map, t_config *config)
{
	char	*line;
	int		status;
	int		map_start;

	*map = NULL;
	status = 0;
	map_start = 0;
	while ((line = get_next_line(fd)))
	{
		status = process_lines(map, config, line, &map_start);
		if (status == -1)
		{
			close(fd);
			if (*map)
				free_list(*map);
			return (-1);
		}
	}
	close(fd);
	return (1);
}

int	check_settings(t_config *conf)
{
	int	fd;

	if ( conf->setting_count >= 0 && conf->setting_count < 6)
	{
		error("Error: One or more settings are missing");
		return (-1);
	}
	else if (conf->setting_count > 6)
	{
		error("Error: Duplicate configuration element found");
		return (-1);
	}
	fd = open(conf->NO_PATH, O_RDONLY);
	if (fd == -1)
		return (error("Error: Incorrect path to the nourth texture"), -1);
	fd = open(conf->SO_PATH, O_RDONLY);
	if (fd == -1)
		return (error("Error: Incorrect path to the nourth texture"), -1);
	fd = open(conf->WE_PATH, O_RDONLY);
	if (fd == -1)
		return (error("Error: Incorrect path to the nourth texture"), -1);
	fd = open(conf->EA_PATH, O_RDONLY);
	if (fd == -1)
		return (error("Error: Incorrect path to the nourth texture"), -1);
	
}
