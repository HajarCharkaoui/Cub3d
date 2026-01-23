/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:39:48 by hacharka          #+#    #+#             */
/*   Updated: 2026/01/20 22:21:48 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valide_color(char **RGB)
{
	int	i;

	if (!RGB[0] || !RGB[1] || !RGB[2] || RGB[3])
		return (0);
	i = 0;
	while (RGB[i])
	{
		if (ft_atoi(RGB[i]) == -1 || ft_atoi(RGB[i]) > 256)
			return (0);
		i++;
	}
	return (1);
}

int	coma_count(char *str)
{
	int	coma;
	int	i;

	coma = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			coma++;
		i++;
	}
	return (coma);
}

int	set_color(char *str, t_config *conf)
{
	int		color;
	char	**rgb;
	char	*blue;

	if (coma_count(str) != 2)
		return (-1);
	rgb = ft_split(str + 2, ',');
	if (!rgb)
		return (-1);
	if (rgb[2] && ft_strchr(rgb[2], '\n'))
	{
		blue = ft_strtrim(rgb[2], "\n");
		free(rgb[2]);
		rgb[2] = blue;
	}
	if (!valide_color(rgb))
		return (free_args(rgb), -1);
	color = (ft_atoi(rgb[0]) << 16) + (ft_atoi(rgb[1]) << 8) + ft_atoi(rgb[2]);
	free_args(rgb);
	if (ft_strncmp(str, "F ", 2) == 0)
		conf->floor_color = color;
	else
		conf->ceiling_color = color;
	return (0);
}

int	is_color(char *str)
{
	int	i;

	i = skip_whitespaces(str);
	if (ft_strncmp(str + i, "F ", 2) == 0 || ft_strncmp(str + i, "C ", 2) == 0)
		return (1);
	return (0);
}
