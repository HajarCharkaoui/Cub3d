/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:36:45 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/17 20:35:44 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_deriction(char *str)
{
	int	i;

	i = skip_whitespaces(str);
	if (ft_strncmp(str + i, "NO ", 3) == 0 || ft_strncmp(str + i, "SO ", 3) == 0
		|| ft_strncmp(str + i, "WE ", 3) == 0
		|| ft_strncmp(str + i, "EA ", 3) == 0)
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

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
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
