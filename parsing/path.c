/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:30:45 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/20 19:11:09 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_config(t_config *config)
{
	config->no_path = NULL;
	config->so_path = NULL;
	config->we_path = NULL;
	config->ea_path = NULL;
	config->ceiling_color = -1;
	config->floor_color = -1;
	config->setting_count = 0;
	config->map = NULL;
	config->x_player = 0;
	config->y_player = 0;
	config->dir_x = 0;
	config->dir_y = 0;
	config->plane_x = 0;
	config->plane_y = 0;
}

void	set_path(char *path, t_config *conf)
{
	if (ft_strncmp(path, "NO ", 3) == 0 && !conf->no_path)
		conf->no_path = ft_strtrim(path + 3, " \t");
	else if (ft_strncmp(path, "SO ", 3) == 0 && !conf->so_path)
		conf->so_path = ft_strtrim(path + 3, " \t");
	else if (ft_strncmp(path, "WE ", 3) == 0 && !conf->we_path)
		conf->we_path = ft_strtrim(path + 3, " \t");
	else if (ft_strncmp(path, "EA ", 3) == 0 && !conf->ea_path)
		conf->ea_path = ft_strtrim(path + 3, " \t");
	else
		return ;
}

int	valide_path(t_config *conf)
{
	int	fd;

	fd = open(conf->no_path, O_RDONLY);
	if (fd == -1)
		return (error("Error: Incorrect path to the nourth texture"), 0);
	close(fd);
	fd = open(conf->so_path, O_RDONLY);
	if (fd == -1)
		return (error("Error: Incorrect path to the south texture"), 0);
	close(fd);
	fd = open(conf->we_path, O_RDONLY);
	if (fd == -1)
		return (error("Error: Incorrect path to the west texture"), 0);
	close(fd);
	fd = open(conf->ea_path, O_RDONLY);
	if (fd == -1)
		return (error("Error: Incorrect path to the east texture"), 0);
	close(fd);
	return (1);
}
