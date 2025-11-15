/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:36:45 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/13 17:45:42 by hacharka         ###   ########.fr       */
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
	config->setting_count = 0;
	config->map = NULL;
}

int	is_deriction(char *str)
{
	int	i;

	i = skip_whitespaces(str);
	if (ft_strncmp(str + i, "NO ", 3) == 0 || ft_strncmp(str + i, "SO ", 3) == 0
			|| ft_strncmp(str + i, "WE ", 3) == 0 || ft_strncmp(str + i, "EA ", 3) == 0)
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
void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}
int	is_map(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = ft_strtrim(str, "\n");
	i = skip_whitespace(new_str);
	while (new_str[i] && is_space(new_str[i]))
		i++;
	if (new_str[i] == '\0')
		return (0);
	while (new_str[i])
	{
		if (new_str[i] != '0' && new_str[i] != '1' && new_str[i] != ' ' && new_str[i] != 'N'
			&& new_str[i] != 'E' && new_str[i] != 'S' && new_str[i] != 'W')
			{
				return (0);
			}
		i++;
	}
	free(new_str);
	return (1);
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
