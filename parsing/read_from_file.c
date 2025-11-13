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

void	save_settings(char *element, t_config *conf)
{
	if (is_deriction(element))
		set_path(element, conf);
	else if (is_color(element))
		set_color(element, conf);
	conf->setting_count ++;
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
int	read_lines(int fd, t_list **map, t_config *config)
{
	char	*line;
	int		map_start;

	map_start = 0;
	*map = NULL;
	while ((line = get_next_line(fd)))
	{
		if (empty_line(line))
		{
			if (map_start)
				return (free(line), error("Error: Empty line in/after map"), -1);
			free(line);
			continue ;
		}
		else if (is_deriction(line) || is_color(line))
		{
			if (map_start)
				return (free(line), error("Error: Map start inside the setting"), -1);
			save_settings(line, config);
			free(line);
		}
		else if (is_map(line))
		{
			save_map(map, line);
			free(line);
			map_start = 1;
		}
		else
			return (free(line), error("Error: Invalide line"), -1);
	}
	close(fd);
	return (1);
}
