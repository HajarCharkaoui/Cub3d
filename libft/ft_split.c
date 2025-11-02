/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:15:28 by hacharka          #+#    #+#             */
/*   Updated: 2024/11/22 22:42:37 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	count_del(const char *s, char c)
{
	int		count;
	int		in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s != c && !in_substring)
		{
			in_substring = 1;
			count++;
		}
		else if (*s == c)
		{
			in_substring = 0;
		}
		s++;
	}
	return (count);
}

static size_t	count_len(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

static void	free_memory(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

static char	**fill_the_array(char **array, char *s, char c)
{
	int		j;
	int		start;
	int		word_len;

	j = 0;
	start = 0;
	while (j < count_del(s, c) && s[start] != '\0')
	{
		while (s[start] == c)
			start++;
		word_len = count_len(s + start, c);
		array[j] = ft_substr(s, start, word_len);
		if (!array[j])
		{
			free_memory(array, j);
			return (NULL);
		}
		start += word_len;
		j++;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc((count_del(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_the_array(arr, s, c));
}
