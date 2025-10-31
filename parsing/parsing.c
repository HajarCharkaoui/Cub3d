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

t_config	fill_the_list(int fd)
{
	char		*line;
	t_config	config_list;

	while ((line = get_next_line(fd)))
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			config_list.NO_PATH = ft_strdup(line + 3);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			config_list.SO_PATH = ft_strdup(line + 3);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			config_list.WE_PATH = ft_strdup(line + 3);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			config_list.EA_PATH = ft_strdup(line + 3);
		else if (ft_strncmp(line, "F ", 2) == 0)
			config_list.SO_PATH = ft_strdup(line + 3);
		else if (ft_strncmp(line, "C ", 2) == 0)
			config_list.SO_PATH = ft_strdup(line + 3);
		free(line);
	}
	return (config_list);
}

int	main(int ac, char **av)
{
	size_t		len;
	char		*file_name;
	int			fd;
	t_config	config_list;

	if (ac != 2)
		return (1);
	file_name = av[1];
	len = ft_strlen(av[1]);
	if (ft_strncmp(file_name + (len - 4), ".cub", 4) != 0)
		return(write(2, "Error: Map file must have a .cub extension\n", 44), 1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 1);
	config_list = fill_the_list(fd);
	return (0);
}
