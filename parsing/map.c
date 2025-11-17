/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hacharka <hacharka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:06:05 by hacharka          #+#    #+#             */
/*   Updated: 2025/11/17 20:30:16 by hacharka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_map(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = ft_strtrim(str, "\n");
	i = skip_whitespaces(new_str);
	while (new_str[i] && is_space(new_str[i]))
		i++;
	if (new_str[i] == '\0')
		return (0);
	while (new_str[i])
	{
		if (new_str[i] != '0' && new_str[i] != '1' && new_str[i] != ' '
			&& new_str[i] != 'N' && new_str[i] != 'E' && new_str[i] != 'S'
			&& new_str[i] != 'W')
		{
			return (0);
		}
		i++;
	}
	free(new_str);
	return (1);
}

void	save_map(t_list **map_list, char *data)
{
	t_list	*new_node;

	new_node = node(data);
	if (!new_node)
	{
		free_list(*map_list);
		free(data);
		return ;
	}
	ft_lstadd_back(map_list, new_node);
}

void	set_map(t_list *map_list, t_config *conf)
{
	int		size;
	t_list	*tmp;
	int		i;

	size = ft_lstsize(map_list);
	tmp = map_list;
	conf->map = malloc(sizeof(char *) * (size + 1));
	if (!conf->map)
		return (error("Malloc failed"));
	i = 0;
	while (tmp)
	{
		conf->map[i++] = ft_strdup(tmp->line);
		tmp = tmp->next;
	}
	conf->map[i] = NULL;
	free_list(map_list);
}

int	set_player_pos(t_config *conf)
{
	int		i;
	int		j;
	int		nbr_players;

	i = 0;
	nbr_players = 0;
	while (conf->map[i])
	{
		j = 0;
		while (conf->map[i][j])
		{
			if (conf->map[i][j] == 'N' || conf->map[i][j] == 'S' 
				||conf->map[i][j] == 'E' || conf->map[i][j] == 'W')
			{
				nbr_players++;
				set_coordinates(conf, i, j);
				break ;
			}
			j++;
		}
		i++;
	}
	if (nbr_players > 1)
		return (error("Error: there are more than one player"), -1);
	return (1);
}
