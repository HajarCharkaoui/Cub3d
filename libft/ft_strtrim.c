/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:13:20 by hacharka          #+#    #+#             */
/*   Updated: 2024/11/18 20:57:41 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	isexiste(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trim;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && isexiste(set, s1[start]) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && isexiste(set, s1[end - 1]) == 1)
		end--;
	trim = malloc(end - start + 1);
	if (trim != NULL)
	{
		i = 0;
		while (start < end)
		{
			trim[i++] = s1[start++];
		}
		trim[i] = '\0';
		return (trim);
	}
	return (NULL);
}
