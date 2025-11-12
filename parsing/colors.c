/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:39:48 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/12 17:35:51 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valide_color(char **RGB)
{
	int	i;
	int	j;

	if (RGB[3])
		return (0);
	i = 0;
	while (RGB[i])
	{
		j = 0;
		while (RGB[i][j])
		{
			if (RGB[i][j] < '0' || RGB[i][j] > '9')
				return (0);
			j++;
		}
		if (j > 3 || (RGB[i][0] == '0' && RGB[i][1])
			|| (ft_atoi(RGB[i]) < 0
				|| ft_atoi(RGB[i]) > 256))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	set_color(char *str, t_config *conf)
{
	int		color;
	char	**RGB;
	char	*blue;
	int		i;

	i = skip_whitespaces(str);
	RGB = ft_split(str + i + 2, ',');
	if (!RGB)
		return (-1);
	if (RGB[2] && ft_strchr(RGB[2], '\n'))
	{
		blue = ft_strtrim(RGB[2], "\n");
		free(RGB[2]);
		RGB[2] = blue;
	}
	if (!valide_color(RGB))
		return (free_args(RGB), -1);
	color = (ft_atoi(RGB[0]) << 16) + (ft_atoi(RGB[1]) << 8) + ft_atoi(RGB[2]);
	free_args(RGB);
	if (ft_strncmp(str + i, "F ", 2) == 0)
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
