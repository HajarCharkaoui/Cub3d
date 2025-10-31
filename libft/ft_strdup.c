/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:20:48 by hacharka          #+#    #+#             */
/*   Updated: 2025/10/31 17:09:07 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	copy = malloc(len + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
