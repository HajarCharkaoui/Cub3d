/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:34:19 by hacharka          #+#    #+#             */
/*   Updated: 2025/10/31 17:10:25 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join == NULL)
		return (NULL);
	else
	{
		i = 0;
		j = 0;
		while (i < ft_strlen(s1) && s1[i] != '\0')
		{
			join[i++] = (char)s1[j++];
		}
		j = 0;
		while (j < ft_strlen(s2) && s2[j] != '\0')
		{
			join[i++] = (char)s2[j++];
		}
		join[i] = '\0';
		return (join);
	}
}
