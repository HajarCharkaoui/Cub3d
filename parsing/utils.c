/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:36:45 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/03 16:16:24 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	is_deriction(char *str)
{
	int	i;

	i = skip_whitespace(str);
	if (ft_strncmp(str + i, "NO ", 3) == 0 || ft_strncmp(str + i, "SO ", 3) == 0
			|| ft_strncmp(str + i, "WE ", 3) == 0 || ft_strncmp(str + i, "EA ", 3) == 0)
			return (1);
	return (0);
}

int	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ' && str[i] != 'N'
			&& str[i] != 'E' && str[i] != 'S' && str[i] != 'W' && str[i] != '\n')
			{
				return (0);
			}
		i++;
	}
	return (1);
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	return (i);
}